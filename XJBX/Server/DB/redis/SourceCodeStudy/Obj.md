## Redis的对象

一般不会直接用到底层的数据结构，然后还为了针对不同场景去做一些内存上的节省，还有一些多态的问题，redis自己做了一个自己的对象系统。

看了一下，主要的类型就是5种：

1. 字符串对象
2. 列表对象
3. 哈希对象
4. 集合对象
5. 有序集合对象

然后把之前看的串起来了：

1. SDS
2. 双端链表
3. 字典
4. 压缩列表
5. 整数集合
6. 跳表

此外，redis还实现了内存上的共享机制（针对对象），但是这里要考虑一下复杂度的问题。还有利用引用计数实现的内存回收机制。

redis还有访问时间记录，在服务器开启了mexmemory的时候，空转时长比较大的k-v可能就会被优先删除。

### 对象的类型和编码

在`redis.h`中看到object的实现。当redis创建一个新的k-v对的时候一般都会创建两个对象，一个作为k，一个作为v。

```
/* A redis object, that is a type able to hold a string / list / set */

/* The actual Redis Object */
/*
 * Redis 对象
 */
#define REDIS_LRU_BITS 24
#define REDIS_LRU_CLOCK_MAX ((1<<REDIS_LRU_BITS)-1) /* Max value of obj->lru */
#define REDIS_LRU_CLOCK_RESOLUTION 1000 /* LRU clock resolution in ms */
typedef struct redisObject {

    // 类型
    unsigned type:4;// 位域

    // 编码
    unsigned encoding:4;

    // 对象最后一次被访问的时间
    unsigned lru:REDIS_LRU_BITS; /* lru time (relative to server.lruclock) */

    // 引用计数
    int refcount;

    // 指向实际值的指针
    void *ptr;

} robj;
```

对于一个键来说，他总会是一个字符串对象，值可能是以下的几种：

1. REDIS_STRING	字符串对象
2. REDIS_LIST	列表对象
3. REDIS_HASH	哈希对象
4. REDIS_SET	集合对象
5. REDIS_ZSET	有序集合对象

具体是啥可以通过type关键字来看

结构体中的ptr指向具体的对象数据结构，具体是啥可以通过encoding知道，看一下宏定义就知道具体的了。

```
/* Objects encoding. Some kind of objects like Strings and Hashes can be
 * internally represented in multiple ways. The 'encoding' field of the object
 * is set to one of this fields for this object. */
// 对象编码
#define REDIS_ENCODING_RAW 0     /* Raw representation 简单动态字符串*/
#define REDIS_ENCODING_INT 1     /* Encoded as integer long类型整数 */
#define REDIS_ENCODING_HT 2      /* Encoded as hash table 字典*/
#define REDIS_ENCODING_ZIPMAP 3  /* Encoded as zipmap 字符串到字符串的映射*/
#define REDIS_ENCODING_LINKEDLIST 4 /* Encoded as regular linked list 双端链表*/
#define REDIS_ENCODING_ZIPLIST 5 /* Encoded as ziplist 压缩列表*/
#define REDIS_ENCODING_INTSET 6  /* Encoded as intset 整数集合*/
#define REDIS_ENCODING_SKIPLIST 7  /* Encoded as skiplist 跳跃表和字典*/
#define REDIS_ENCODING_EMBSTR 8  /* Embedded sds string encoding embstr编码的sds*/
```

仔细看会发现其实每个对象都用了至少两种结构做位底层的存储编码。主要为了权衡时间复杂度和内存的

### 字符串对象





