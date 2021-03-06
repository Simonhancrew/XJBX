## 压缩列表

ziplist是列表和哈希的底层实现之一，列表或者哈希里面都是int或者短string的时候就用压缩列表做存储底层实现。Ziplist 是为了尽可能地节约内存而设计的特殊编码双端链表。

### 组成

压缩列表的实现就是为了省空间，由一系列的特殊编码连续内存块组成。一个压缩列表可以包含任意多个节点，每个节点可以保存一个字节数组或是一个整数值。

| zlbytes | zltail | zllen | entry1 | entry2 | ...  | entryn | zlend |
| :-----: | :----: | :---: | :----: | :----: | :--: | :----: | :---: |

压缩列表组成如上

+ zlbytes：uint32_t,4字节，记录整个压缩列表占用的字节数。重分配内存和计算zlend的位置的时候使用
+ zltail，uint32_t，4字节， 记录压缩列表表尾节点距离压缩列表的起始地址有多少字节： 通过这个偏移量，程序无须遍历整个压缩列表就可以确定表尾节点的地址。
+ zllen，uint16_t，2字节，记录了压缩列表包含的节点数量： 当这个属性的值小于 `UINT16_MAX` （`65535`）时， 这个属性的值就是压缩列表包含节点的数量； 当这个值等于 `UINT16_MAX` 时， 节点的真实数量需要遍历整个压缩列表才能计算得出。
+ entry的长度由节点实际值决定
+ zlend，uint8_t，1字节，特殊值 `0xFF` （十进制 `255` ），用于标记压缩列表的末端。

### 节点entry构成

每个压缩列表节点可以保存一个字节数组或者一个整数值， 其中， 字节数组可以是以下三种长度的其中一种：

1. 长度小于等于 `63` （2^{6}-1）字节的字节数组；
2. 长度小于等于 `16383` （2^{14}-1） 字节的字节数组；
3. 长度小于等于 `4294967295` （2^{32}-1）字节的字节数组；

而整数值则可以是以下六种长度的其中一种：

1. `4` 位长，介于 `0` 至 `12` 之间的无符号整数；
2. `1` 字节长的有符号整数；
3. `3` 字节长的有符号整数；
4. `int16_t` 类型整数；
5. `int32_t` 类型整数；
6. `int64_t` 类型整数。

每个压缩列表节点都由 `previous_entry_length` 、 `encoding` 、 `content` 三个部分组成

```
typedef struct zlentry {

    // prevrawlen ：前置节点的长度
    // prevrawlensize ：编码 prevrawlen 所需的字节大小
    unsigned int prevrawlensize, prevrawlen;

    // len ：当前节点值的长度
    // lensize ：编码 len 所需的字节大小
    unsigned int lensize, len;

    // 当前节点 header 的大小
    // 等于 prevrawlensize + lensize
    unsigned int headersize;

    // 当前节点值所使用的编码类型
    unsigned char encoding;

    // 指向当前节点的指针
    unsigned char *p;

} zlentry;
```

#### previous_entry_length

从表尾遍历到表头很有用，知道了当前节点的指针，减去previous_entry_lenght就是前一个节点的真实地址。

#### encoding

encoding记录了节点的 `content` 属性所保存数据的类型以及长度：

- 一字节、两字节或者五字节长， 值的最高位为 `00` 、 `01` 或者 `10` 的是字节数组编码： 这种编码表示节点的 `content` 属性保存着字节数组， 数组的长度由编码除去最高两位之后的其他位记录；
- 一字节长， 值的最高位以 `11` 开头的是整数编码： 这种编码表示节点的 `content` 属性保存着整数值， 整数值的类型和长度由编码除去最高两位之后的其他位记录；

#### content

节点的 content 属性负责保存节点的值， 节点值可以是一个字节数组或者整数， 值的类型和长度由节点的 encoding 属性决定。

### 连锁更新

zl允许两端O（1）的添加和删除元素，但是可能涉及到内存的重新分配，索引实际复杂度要分析实际的内存情况。

但是最坏复杂度O(n*n)的情况很少出现，因为很少有这么多的连续垃圾长度entry出现

### 总结

+ 压缩列表为了生内存
+ 短小的时候的哈希和列表的底层实现
+ 各种操作的实际复杂度要分析内存分布，但是平均都是O(n)的