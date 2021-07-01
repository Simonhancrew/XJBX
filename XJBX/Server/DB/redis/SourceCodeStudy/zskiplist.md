## 跳表

跳表是一种有序数据结构，每个节点存在多个访问其他节点的指针，从而达到快速访问的效果。跳表的平均访问时间是O（logN）的，但是是不稳定的，最坏的是O（N）的。要求稳定场景下，最好还是使用红黑树。

跳表的实现比平衡树要简单很多，没必要去为平衡做出rotate的操作.

跳表是有序集合键的底层实现之一,redis只在两个地方用到了跳表,第一个就是有序集合键,另一个就是在集群节点用作内部数据结构.

### 实现

就是一个Node一个list

```
/* ZSETs use a specialized version of Skiplists */
/*
 * 跳跃表节点
 */
typedef struct zskiplistNode {

    // 成员对象
    robj *obj;

    // 分值
    double score;

    // 后退指针
    struct zskiplistNode *backward;

    // 层
    struct zskiplistLevel {

        // 前进指针
        struct zskiplistNode *forward;

        // 跨度
        unsigned int span;

    } level[];

} zskiplistNode;

```

一个节点有多个层，每个节点的层高是随机出来的。

然后多个节点就组成了跳跃表

```
/*
 * 跳跃表
 */
typedef struct zskiplist {

    // 表头节点和表尾节点
    struct zskiplistNode *header, *tail;

    // 表中节点的数量
    unsigned long length;

    // 表中层数最大的节点的层数
    int level;

} zskiplist;
```

跳表的head和tail都可以O（1）的访问到，这是比较具有优势的。之前也看到有人拿跳表来改过定时器，处理过期时间，能最小的拿到尾部。但是删除可能是问题。

### 总结

1. 跳表是有序集合的底层实现
2. 每个跳表的层高是1-32之前的随机数

