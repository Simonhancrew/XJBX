# Just a recorcd of my daily routine


## [Some implement](XJBX)
---

+ [BloomFilter](XJBX/Bloomfilter)

    > 一个参考Cassandra中的BloomFilter实现，Hash选用MurmurHash2，通过双重散列公式生成散列函数
    > 参考：http://hur.st/bloomfilter


+ [SCL](XJBX/SCL)

    > Standard Code Library。很重要的一些基础模板
+ [Morris遍历](XJBX/SCL/Graph/MorrisTraverse.hpp)

    >一种树的遍历算法，前中序很有趣，基本可以实现O(1)的额外空间复杂度。后序个人觉得没必要，因为有些操作感觉会引入一点额外的时间复杂度。主要是利用了叶子节点的空悬孩子的信息

+ [Server](/XJBX/Server/)
    > [多路复用](XJBX/Server/IOMultiplexing)，从one io one thread开始到epoll
## [Solution](Solution)

> 大多数是Lc的题目，一般用C++,golang,python3实现，偶尔有rust。
