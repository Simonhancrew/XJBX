## SDS注意事项

1. 我先看的sds.h,在这个里面比较好奇的一个点是**柔性数组**的问题

```
static inline size_t sdslen(const sds s) {
    struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));
    return sh->len;
}
```

为啥`struct sdshdr *sh = (void*)(s-(sizeof(struct sdshdr)));`就拿到了sds的内存起始地点呢？

回去看初始化的方式的sds的定义。

```
/*
 * 保存字符串对象的结构
 */
struct sdshdr {
    
    // buf 中已占用空间的长度
    int len;

    // buf 中剩余可用空间的长度
    int free;

    // 数据空间
    char buf[];
};
```

这里最后的`char buf[]`可以这么玩？怎么没有大小？这里其实用到的就是柔性数组。

比如，考虑如下的代码

```
struct test
{
	int a;
	char buf[];
};
```

实际执行的sizeof test的时候是4.说明这里：

1. 首先柔性数组不占内存，值代表地址；
2. 可以通过p->buf来访问字符串，符合常规用法。
3. 字符串长度为动态分配。

```
#include <stdlib.h>
#include <iostream>
using namespace std;
struct test {
	int idx;
	char buf[];
};
int main() {
	char ch[] = "hello world!";
	struct test* p = (struct test*)malloc(sizeof(struct test) + sizeof(ch) + 1);
	memcpy(p->buf, ch, sizeof ch);
	cout << p->buf << endl;
}
```

所以，`sizeof(struct sdshdr)`实际就是8字节。

为什么-8就拿到了sds的数据起始呢？

再探索init方式了。

```
/*
 * 根据给定的初始化字符串 init 和字符串长度 initlen
 * 创建一个新的 sds
 *
 * 参数
 *  init ：初始化字符串指针
 *  initlen ：初始化字符串的长度
 *
 * 返回值
 *  sds ：创建成功返回 sdshdr 相对应的 sds
 *        创建失败返回 NULL
 *
 * 复杂度
 *  T = O(N)
 */
 sds sdsnewlen(const void *init, size_t initlen) {

    struct sdshdr *sh;

    // 根据是否有初始化内容，选择适当的内存分配方式
    // T = O(N)
    if (init) {
        // zmalloc 不初始化所分配的内存
        sh = zmalloc(sizeof(struct sdshdr)+initlen+1);
    } else {
        // zcalloc 将分配的内存全部初始化为 0
        sh = zcalloc(sizeof(struct sdshdr)+initlen+1);
    }

    // 内存分配失败，返回
    if (sh == NULL) return NULL;

    // 设置初始化长度
    sh->len = initlen;
    // 新 sds 不预留任何空间
    sh->free = 0;
    // 如果有指定初始化内容，将它们复制到 sdshdr 的 buf 中
    // T = O(N)
    if (initlen && init)
        memcpy(sh->buf, init, initlen);
    // 以 \0 结尾
    sh->buf[initlen] = '\0';

    // 返回 buf 部分，而不是整个 sdshdr
    return (char*)sh->buf;
}
```

原来如此，这里返回的是buf的部分啊，他内存分布是连续的（虚拟化的情况下）,之后就简答的-8就可以拿sds的起始地址了啊。