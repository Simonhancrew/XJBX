# 内存池的学习

## Node

在`nginx`内存池中有一个头部，头部里又包含一个数据部，数据部主要用来为用户分配小块内存。数据部之外主要为用户分配大块内存、管理外部资源、日志信息以及内存池的一些其他信息。

内存数据块如下

```
typedef struct {
	u_char *last;
	u_char *end;
	ngx_pool_t *next;
	ngx_uint_t failed;
} ngx_pool_data_t;
```

内存池头如下

```
struct ngx_pool_s {
	ngx_pool_data_t d;
	size_t max;
	ngx_pool_t *current;
	ngx_chain_t *chain;
	ngx_pool_large_t *large;
	ngx_pool_cleanup_t *cleanup;
	ngx_log_t *log;
};
```

这两者组成了基本的`nginx`内存池的主体结构

`nginx`的内存池实际是一个由`ngx_pool_data_t`和`ngx_pool_s`构成的链表。

`ngx_pool_data_t`中：

> `last`：是一个unsigned char 类型的指针，保存的是/当前内存池分配到末位地址，即下一次分配从此处开始。
>
> `end`：内存池结束位置；
>
> `next`：内存池里面有很多块内存，这些内存块就是通过该指针连成链表的，next指向下一块内存。
>
> `failed`：内存池分配失败次数。 

`ngx_pool_s`中:

> `d`：内存池的数据块；
>
> `max`：内存池数据块的最大值；
>
> `current`：指向当前内存池；
>
> `chain`：该指针挂接一个
>
> `ngx_chain_t`结构；
>
> large：大块内存链表，即分配空间超过max的情况使用；cleanup：释放内存池的
>
> `callbacklog`：日志信息

## 创建等基本操作

| operation          | Routine                                                      |
| ------------------ | ------------------------------------------------------------ |
| 创建内存池         | `ngx_pool_t * ngx_create_pool(size_t size, ngx_log_t *log);` |
| 销毁内存池         | `void ngx_destroy_pool(ngx_pool_t *pool);`                   |
| 重置内存池         | `void ngx_reset_pool(ngx_pool_t *pool);`                     |
| 内存申请（对齐）   | `void * ngx_palloc(ngx_pool_t *pool, size_t size);`          |
| 内存申请（不对齐） | `void * ngx_pnalloc(ngx_pool_t *pool, size_t size);`         |
| 内存清除           | `ngx_int_t ngx_pfree(ngx_pool_t *pool, void *p);`            |

+ 内存池的创建

```
ngx_pool_t *ngx_create_pool(size_t size, ngx_log_t *log)
{
 	ngx_pool_t *p;
	p = ngx_memalign(NGX_POOL_ALIGNMENT, size, log);
    if (p == NULL) {
    	return NULL;
    }
	p->d.last = (u_char *) p + sizeof(ngx_pool_t);//初始状态：last指向ngx_pool_t结构体之后数据取起始位置
 	p->d.end = (u_char *) p + size;//end指向分配的整个size大小的内存的末尾
 	p->d.next = NULL;
 	p->d.failed = 0;
 	//#define NGX_MAX_ALLOC_FROM_POOL (ngx_pagesize - 1)
 	//内存池最大不超过4095，x86中页的大小为4K
 	size = size - sizeof(ngx_pool_t);
 	p->max = (size < NGX_MAX_ALLOC_FROM_POOL) ? size : NGX_MAX_ALLOC_FROM_POOL;
 	p->current = p;
 	p->chain = NULL;
 	p->large = NULL;
 	p->cleanup = NULL;
 	p->log = log;
	return p;
}
```

`nginx`对内存的管理分为大内存与小内存，当某一个申请的内存大于某一个值时，就需要从大内存中分配空间，否则从小内存中分配空间。`nginx`中的内存池是在创建的时候就设定好了大小，在以后分配小块内存的时候，如果内存不够，则是重新创建一块内存串到内存池中，而不是将原有的内存池进行扩张。当要分配大块内存是，则是在内存池外面再分配空间进行管理的，称为大块内存池。

+ 内存的申请

```
void *ngx_palloc(ngx_pool_t *pool, size_t size)
{
 	u_char *m;
 	ngx_pool_t *p;
 
 	if (size <= pool->max) {//如果申请的内存大小大于内存池的max值，则走另一条路，申请大内存
 
 		p = pool->current;
 
 		do {
 			m = ngx_align_ptr(p->d.last, NGX_ALIGNMENT);//对内存地址进行对齐处理
 
 			if ((size_t) (p->d.end - m) >= size) {//如果在当前内存块有效范围内，进行内存指针的移动
 				p->d.last = m + size;
 
			 	return m;
 			}
 
 			p = p->d.next;//如果当前内存块有效容量不够分配，则移动到下一个内存块进行分配
 
		 } while (p);

			return ngx_palloc_block(pool, size);
	}
	return ngx_palloc_large(pool, size);
}
```

1. `ngx_align_ptr`，这是一个用来内存地址取整的宏，非常精巧，一句话就搞定了。作用不言而喻，取整可以降低CPU读取内存的次数，提高性能。因为这里并没有真正意义调用`malloc`等函数申请内存，而是移动指针标记而已，所以内存对齐的活，C编译器帮不了你了，得自己动手。

2. `ngx_palloc_block(ngx_pool_t *pool, size_t size)`这个函数是用来分配新的内存块，为pool内存池开辟一个新的内存块，并申请使用size大小的内存；

   ```
   static void *ngx_palloc_block(ngx_pool_t *pool, size_t size)
   {
   	u_char *m;
   	size_t psize;
    	ngx_pool_t *p, *new, *current;
    
   	psize = (size_t) (pool->d.end - (u_char *) pool);//计算内存池第一个内存块的大小
   
    	m = ngx_memalign(NGX_POOL_ALIGNMENT, psize, pool->log);//分配和第一个内存块同样大小的内存块
    	if (m == NULL) {
   		return NULL;
    	}
    
    	new = (ngx_pool_t *) m;
    
    	new->d.end = m + psize;//设置新内存块的end
    	new->d.next = NULL;
    	new->d.failed = 0;
    
   	m += sizeof(ngx_pool_data_t);//将指针m移动到d后面的一个位置，作为起始位置
    	m = ngx_align_ptr(m, NGX_ALIGNMENT);//对m指针按4字节对齐处理
    	new->d.last = m + size;//设置新内存块的last，即申请使用size大小的内存
    
    	current = pool->current;
    	//这里的循环用来找最后一个链表节点，这里failed用来控制循环的长度，如果分配失败次数达到5次，
    	//就忽略，不需要每次都从头找起
    	for (p = current; p->d.next; p = p->d.next) {
    		if (p->d.failed++ > 4) {
    			current = p->d.next;
    		}
    	}
    
    	p->d.next = new;
    
    	pool->current = current ? current : new;
   
    	return m;
   }
   ```

3. `ngx_palloc_large(ngx_pool_t *pool, size_t size)`在`ngx_palloc`中首先会判断申请的内存大小是否超过内存块的最大限值，如果超过，则直接调用`ngx_palloc_large`，进入大内存块的分配流程；

   ```
   static void *ngx_palloc_large(ngx_pool_t *pool, size_t size)
   {
    	void *p;
    	ngx_uint_t n;
    	ngx_pool_large_t *large;
    	// 直接在系统堆中分配一块空间
    	p = ngx_alloc(size, pool->log);
    	if (p == NULL) {
    		return NULL;
    	}
    	n = 0;
    	// 查找到一个空的large区，如果有，则将刚才分配的空间交由它管理
    	for (large = pool->large; large; large = large->next) {
    	if (large->alloc == NULL) {
    		large->alloc = p;
    		return p;
    	}
    	if (n++ > 3) break;
   ```

4. 内存清理

   1. `ngx_pfree`

   ```
   ngx_int_t ngx_pfree(ngx_pool_t *pool, void *p)
   {
   	ngx_pool_large_t *l;
    	//只检查是否是大内存块，如果是大内存块则释放
    	for (l = pool->large; l; l = l->next) {
    		if (p == l->alloc) {
    			ngx_log_debug1(NGX_LOG_DEBUG_ALLOC, pool->log, 0,"free: %p", l->alloc);
    			ngx_free(l->alloc);
    			l->alloc = NULL;
   			return NGX_OK;
    		}
   	}
   	return NGX_DECLINED;
   }
   ```

   所以说`Nginx`内存池中大内存块和小内存块的分配与释放是不一样的。我们在使用内存池时，可以使用`ngx_palloc`进行分配，使用`ngx_pfree`释放。而对于大内存，这样做是没有问题的，而对于小内存就不一样了，分配的小内存，不会进行释放。因为大内存块的分配只对前3个内存块进行检查，否则就直接分配内存，所以大内存块的释放必须及时。

   2. `ngx_pool_cleanup_s`

   `Nginx`内存池支持通过回调函数，对外部资源的清理。`ngx_pool_cleanup_t`是回调函数结构体，它在内存池中以链表形式保存，在内存池进行销毁时，循环调用这些回调函数对数据进行清理。

   ```
   struct ngx_pool_cleanup_s {
   	ngx_pool_cleanup_pt handler;
   	void *data;
   	ngx_pool_cleanup_t *next;
   };
   ```

   其中handler：是回调函数指针；

   `data`：回调时，将此数据传入回调函数；

   `next`：指向下一个回调函数结构体；如果我们需要添加自己的回调函数，则需要调用`ngx_pool_cleanup_add`来得到一个`ngx_pool_cleanup_t`，然后设置handler为我们的清理函数，并设置data为我们要清理的数据。

   这样在`ngx_destroy_pool`中会循环调用handler清理数据；比如：我们可以将一个开打的文件描述符作为资源挂载到内存池上，同时提供一个关闭文件描述的函数注册到handler上，那么内存池在释放的时候，就会调用我们提供的关闭文件函数来处理文件描述符资源了。

5. 销毁

   `ngx_destroy_pool`：内存池的销毁

   ```
   void ngx_destroy_pool(ngx_pool_t *pool)
   {
   	ngx_pool_t *p, *n;
    	ngx_pool_large_t *l;
    	ngx_pool_cleanup_t *c;
   
    	//首先调用所有的数据清理函数
    	for (c = pool->cleanup; c; c = c->next) {
   		if (c->handler) {
    			ngx_log_debug1(NGX_LOG_DEBUG_ALLOC, pool->log, 0,"run cleanup: %p", c);
    			c->handler(c->data);
    		}
   	 }
   
    	//释放所有的大块内存
    	for (l = pool->large; l; l = l->next) {
   		ngx_log_debug1(NGX_LOG_DEBUG_ALLOC, pool->log, 0, "free: %p", l->alloc);
   
    		if (l->alloc) {
    			ngx_free(l->alloc);
    		}
    	}
   
    	//最后释放所有内存池中的内存块
    	for (p = pool, n = pool->d.next; /* void */; p = n, n = n->d.next) {
    		ngx_free(p);
   
    		if (n == NULL) {
    			break;
   		}
    	}
    }
   ```

   

   