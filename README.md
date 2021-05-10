## [Some implement](XJBX)
---

+ [BloomFilter](XJBX/Bloomfilter)

    > 一个参考Cassandra中的BloomFilter实现，Hash选用MurmurHash2，通过双重散列公式生成散列函数
    > 参考：http://hur.st/bloomfilter


+ [SCL](XJBX/SCL)

    > Standard Code Library。基础算法模板
+ [Morris遍历](XJBX/SCL/Graph/MorrisTraverse.hpp)

    > 一种树的遍历算法，前中序很有趣，基本可以实现O(1)的额外空间复杂度。后序个人觉得没必要，因为有些操作感觉会引入一点额外的时间复杂度。主要是利用了叶子节点的空悬孩子的信息

+ [Server](/XJBX/Server/)
    > [多路复用](XJBX/Server/IOMultiplexing)：从one io one thread开始到epoll到reactor
    
    > [basicAPI](XJBX/Server/basicAPI)：简单的记录一下linux的相关网络处理函数和io函数

    > [redis](XJBX/Server/redis/README.md)：redis sample

    > [minigrep](XJBX/Server/minigrep/)：丐版grep(Rust)

    > [协程](XJBX/Server/Coroutine)：协程的实现（用户态线程）
+ [Linguistic Charactor](/XJBX/LingChar)

    > [左值和右值](/XJBX/LingChar/LRValue/README.md)，对于左值引用，move，右值引用的理解

    > [递归的复杂度](/XJBX/LingChar/Recursion/recursion.h),递归的复杂度判断

    > [智能指针](XJBX/LingChar/smartPointer/README.md):智能指针
+ [正则表达式记录](XJBX/Regexr/README.md)
    > 正则的内容备忘

+ [Solutions](/Solution/)
    
    > contribute 365