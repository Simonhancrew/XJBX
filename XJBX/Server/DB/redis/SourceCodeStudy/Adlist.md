## Redis链表的实现问题

首先redis链表的node的实现是一个双向的，看一下node的代码就知道了

```
zhe/*
 * 双端链表节点
 */
typedef struct listNode {

    // 前置节点
    struct listNode *prev;

    // 后置节点
    struct listNode *next;

    // 节点的值
    void *value;

} listNode;
```

这里看到void* ,这里可以保存不同类型的值。但是我之前在msvc里面看char*是8字节的，可能后续还要继续深究一下。正常来讲一个指针里面会多存一个数据类型，这样他在+1的时候才能知道跨过多大的内存。

然后他为了方便使用，进一步封装了链表

```
/*
 * 双端链表结构
 */
typedef struct list {

    // 表头节点
    listNode *head;

    // 表尾节点
    listNode *tail;

    // 节点值复制函数
    void *(*dup)(void *ptr);

    // 节点值释放函数
    void (*free)(void *ptr);

    // 节点值对比函数
    int (*match)(void *ptr, void *key);

    // 链表所包含的节点数量
    unsigned long len;

} list;
```

这里关注一下函数指针的问题，`dup`,`free`，`match`可以自己指定成别的函数，实现了一个多态类型的特定函数。

这里关于链表的实现也比较的精美，代码不多，加了注释也才不到600行。

### 总结

+ redis的链表被用在了列表键，发布订阅，慢查询，监视器等地方。

+ redis实现的是一个双端链表，而且头尾都是NULL
+ 每个List还记录了长度和首尾，可以O（1）的拿到一些数据
+ 最后要关注一下函数指针和node中的void*实现的多态技巧（C）。