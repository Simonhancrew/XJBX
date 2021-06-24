## 哈希表的实现

首先看到哈希表的定义

```
/*
 * 哈希表
 *
 * 每个字典都使用两个哈希表，从而实现渐进式 rehash 。
 */
typedef struct dictht {
    
    // 哈希表数组
    dictEntry **table;

    // 哈希表大小
    unsigned long size;
    
    // 哈希表大小掩码，用于计算索引值
    // 总是等于 size - 1
    unsigned long sizemask;

    // 该哈希表已有节点的数量
    unsigned long used;

} dictht;
```

table是一个数组，数组里的每个元素指向`dictEntry`结构的指针。看到这个entry我就想到了rust的`entry.or_insert()`.

然后再看到哈希的节点,这里看到最后部分，节点之前形成了一个链表的。解决哈希冲突的方式可以时拉链法或者开放地址法，但是开放地址法我记得要拼人品的。

```
// 如果字典的私有数据不使用时
// 用这个宏来避免编译器错误
#define DICT_NOTUSED(V) ((void) V)

/*
 * 哈希表节点
 */
typedef struct dictEntry {
    
    // 键
    void *key;

    // 值
    union {
        void *val;
        uint64_t u64;
        int64_t s64;
    } v;

    // 指向下个哈希表节点，形成链表
    struct dictEntry *next;

} dictEntry;
```

### 字典的实现

```
/*
 * 字典
 */
typedef struct dict {

    // 类型特定函数
    dictType *type;

    // 私有数据
    void *privdata;

    // 哈希表
    dictht ht[2];

    // rehash 索引
    // 当 rehash 不在进行时，值为 -1
    int rehashidx; /* rehashing not in progress if rehashidx == -1 */

    // 目前正在运行的安全迭代器的数量
    int iterators; /* number of iterators currently running */

} dict;
```

这里type属性和privatedata属性是针对不同类型的键值对，为创建字典多态而设置。

+ type指向了一个dictType的结构，这里保存了一些列用于特定操作的函数。redis会为不同的字典设置不同类型的特定函数。
+ privatedata保存了需要传给那些类型特定函数的可选参数。

然后ht这里是两张哈希表，一般只用ht[0],只有在rehash的时候才会使用到hash[1].rehashidx记录目前的rehash有没有执行。

```
/*
 * 字典类型特定函数
 */
typedef struct dictType {

    // 计算哈希值的函数
    unsigned int (*hashFunction)(const void *key);

    // 复制键的函数
    void *(*keyDup)(void *privdata, const void *key);

    // 复制值的函数
    void *(*valDup)(void *privdata, const void *obj);

    // 对比键的函数
    int (*keyCompare)(void *privdata, const void *key1, const void *key2);

    // 销毁键的函数
    void (*keyDestructor)(void *privdata, void *key);
    
    // 销毁值的函数
    void (*valDestructor)(void *privdata, void *obj);

} dictType;
```

### 哈希算法

一个新的k-v添加到字典的时候应该先根据他的键算一下他的哈希值和索引。再根据索引，把哈希值放到应有的位置上去。

```
//根据key值计算hash的值
hash = dict->type->hashFuntion(key);
```

之后就可以算一下索引值了

```
index = hash & dict->ht[x].sizemask;
```

当字典用于数据库的底层实现，或者哈希键的底层实现的时候，redis使用MurmurHash2算法作为计算键的哈希值。

### 键冲突的解决

头插法，比较简单

### rehash

