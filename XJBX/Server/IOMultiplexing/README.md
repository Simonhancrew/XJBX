## io复用详解

io复用使得程序可以同时监听多个fd，这对提升程序的性能及其的关键。通常有一下几个场景需要使用到io复用的技术

+ 客户端要同时处理多个socket（例如非阻塞的connect）
+ 客户端同时处理用户的输入和网络链接（例如聊天室）
+ TCP服务器需要同时处理监听socket和链接socket（这也是最多的场景）
+ 服务器需要同时处理tcp和udp的请求（回射服务器）
+ 服务器同时监听多个端口和处理多个事务。

但需要指出的是，复用虽然能够监听多个fd，但是这个函数本身是阻塞的。多个fd就位的时候，不采取额外的措施，程序只能顺序处理每一个fd，这让服务器看起来是串行工作的。要实现并发，可以考虑多线程的方案。

### select 系统调用

监听一段时间内，用户感兴趣的fd上的可读，可写，和异常事件等。

```
#include <sys/select.h>
#include <sys/time.h>

int select(int max_fd, fd_set *readset, fd_set *writeset, fd_set *exceptset, struct timeval *timeout)
```

1. max_fd指定被监听的fd的总数，一般被设置为监听的所有的文件fd最大值 + 1（fd从0开始计数）
2. readset、writeset和exceptset指定要让内核测试**读、写**和**异常**条件的fd集合，如果不需要测试的可以设置为NULL，select返回的时候内核将修改他们来通知程序那些文件描述符已经就位。这三个参数是fd_set结构体指针，这个结构体内仅仅包含一个整型的数组，数组的每个元素的每一位标记一个fd。fd_set能容纳的文件描述符数量由FD_SETSIZE来指定。（1024以下的时候，可能select的性能会优于epoll）

```
FD_ZERO(int fd, fd_set* fds)   //清空集合
FD_SET(int fd, fd_set* fds)    //将给定的描述符加入集合
FD_ISSET(int fd, fd_set* fds)  //将给定的描述符从文件中删除  
FD_CLR(int fd, fd_set* fds)    //判断指定描述符是否在集合中
```

3. timeout参数用来设置超时的时间。这是一个timeval结构类型的指针，后续内核将修改他，告诉程序select等待了多久。（不过这个值是不完全可信的，失败的时候就不确定）。如果结构体中的两个数都传0，立即返回，传null的话，select将一直阻塞，知道某个fd就绪。

```
struct timeval{
	long tv_sec;//秒数
	long tv_usec; //微秒
};
```

select成功的时候会返回就绪fd的数量，如果超时时间内没有任何的fd就绪，select会返回0。select失败的时候会返回-1，并设置errno。如果程序在select等待期间，接受到了信号，就会立即返回-1，errno被设置为EINTR。

















### 此处我们思考如何管理一个服务器的多个客户端连接

+ 网络  IO，会涉及到两个系统对象，一个是用户空间调用  IO 的进程或者线程，另一个是内核 空间的内核系统，比如发生  IO 操作 read 时，它会经历两个阶段：

    > 1 等待数据准备就绪

    > 2 将数据从内核拷贝到进程或者线程中。

+ 由此引出多种网络io模型（5种）

    > 阻塞io + 非阻塞io + 多路复用io + 异步io + 信号驱动io

+ 首先使用最朴素的思想，一个连接一个线程，recv每一个io。优点是很朴素，缺点是极度的耗费资源（太频繁的信号操作是耗内核资源的，内核态 <-> 用户态），动态的开辟线程和初始连接是很慢的。例如[sigio](sigio.c)

+ 之后这里肯定有冗余的操作的，不一定每一个io都需要去进行操作，我们此处引入select/poll/epoll。我们集中考虑这个fd是否可读？可写？是否出错？[select + epoll](server_io.c)

+ 然后io如何存储？对应每一个io，他有那些属性？这里我们就考虑一下[reactor](reactor.c)模式
