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

在哪些情况下，fd被认为是可读可写或者是出现异常，这对于select的使用是非常关键的。下列情况下，socket可读：

1. socket内核接收缓冲区的字节数>=其低水位标记SO_RCVLOWAT。此时我们可以无阻塞的读。且返回的字节数大于0
2. 通信的对方关闭连接。
3. 监听的socket上有新的请求连接
4. socket上有未处理的错误

socket可写：

1. 发送缓冲区的可用字节数大于等于其低水位标记SO_SNDLOWAT
2. 写操作被关闭
3. 使用非阻塞connect连接成功或者失败之后
4. socket上有未处理的错误

> [handleerror](./selectsample.c)

### epoll

epoll是linux特有的I/O复用函数，实现上和select有较大的差异。首先epoll使用一组函数来完成任务。其次，epoll把用户关心的fd放在内核的一个时间表里，从而无需想select那样需要每次都重复传fdset。但epoll需要一个额外fd，来唯一的标识内核中的这个时间表，这个fd由epoll_creat()创建。

```
#include <sys/epoll.h>
int epoll_creat(int size);
```

size参数在目前最新的版本中并不起作用了，只给内核一个提示，告诉他时间表是要多大。函数返回的fd作为其他所有的epoll调用的第一个参数，指定要访问的内核时间表。下面的函数用来操作内核的时间表

```
#inlude <sys/epoll.h>
int epoll_ctl(int epfd,int op,inr fd,struct epoll_event *event)
```

fd是要操作的文件描述符，op参数指定操作的类型，由如下的三种：

1. EPOLL_CTL_ADD,往内核时间表注册fd上的时间
2. EPOLL_CTL_MOD,修改fd上的注册事件
3. EPOLL_CTL_DEL,删除fd上的注册事件

event参数指定时间，他是epoll_event结构体型指针。

```
struct epoll_event{
	__uint32_t events; //epoll事件
	epoll_data_t data; //用户数据
};
```

events描述的是事件类型，epoll数据可读就是 EPOLLIN,EPOLLOUT就是数据可写。其余的事件和poll的相似，但是有两个额外的事件类型，EPOLLLET和EPOLLONESHOT，他们对于epoll的高效运转非常的关键。data用作存储用户的数据：

```
typedef union epoll_data{
	void *ptr;
	int fd;
	uint32_t u32;
	uint64_t u64;
}epoll_data_t;
```

因为是一个union，所以ptr和fd不能同时使用。

**epoll_wait函数**

在一段时间内等待一组文件描述符上的事件，原型：

```
#include <sys/epoll.h>
int epoll_wait(int epfd,struct epoll_event* events,int maxevents,int timeout);
```

函数成功的时候返回就绪的fd数量，失败的时候返回-1，并设置errno。

timeout参数设置超时值,-1的时候会一直阻塞，知道某个事件发生，maxevents指定最多监听多少个事件，必须大于0。epoll_wait函数如果检查到事件，就将所有的就绪的事件从内核表中复制到他的第二个参数events指向的数组结构体中。这个数组只用于输出epoll检测到的就绪事件，不同于select中的数组参数那样，既用于传入用户的注册事件，又用于传出内核检测到的就绪事件。

```
int ret = poll(fds,MAX_EVENT_NUMBER,-1);
for(int i = 0;i < MAX_EVENT_NUMBER;i++){
	if(fds[i].revents & POLLIN){
		int socketfd = fds[i].fd; 
	}
}
```

epoll去索引返回的就绪文件fd就方便很多

```
int ret = epoll_wait(epfd,events,MAX_EVENT_NUMBER,-1);
for(int i = 0;i < ret;i++){
	int socketfd = events[i];//肯定是就绪的，直接处理
}
```

**ET和LT模式**

epoll对于fd的操作模式有两种：LT（Level Trigger,水平触发），LT（Edge Trigger，边缘触发）。LT是默认的工作模式，这种模式下，epoll就是一个效率比较高的poll。当往epollfd上注册一个fd上的EPOLLET事件时，epoll将以et模式去操作该fd。ET是epoll的高效模式。

对于采用LT的文件描述符，epoll_wait检测到其上有事件发生并将此事件通知应用程序之后，应用程序可以不立即处理该事件。这样下一次调用epoll_wait的时候，该函数还是会向应用程序通知此事件，知道这个事件被处理。而对于采用ET模式的文件描述符，epoll_wait通知应用程序该事件之后，应用程序应该立即处理这个事件，后续epoll_wait不会再向应用程序通知这一事件。ET从某种意义上，降低了同一个epoll事件背重复触发的次数，效率是高于LT的。具体代码详见[epoll](./epoll_et_lt.c)

**EPOLLONESHOT事件**

既是我们使用ET模式，一个socket上的某个事件还是可能被触发多次。这在并发程序种就会引起一个问题。比如一个线程，在读取某个socket的数据之后开始处理，而在这个处理的过程中，socket上又有了新的数据可读，此时另外一个线程被唤醒来读取这些数据。问题出现，两个线程同时操作一个socket，这当然不是我们想要的。我们期望的是任何一个时刻，一个socket只会被一个线程处理。

这一点我们可以考虑EPOLLONESHOT，对于注册了这个事件的fd，操作系统最多触发其上注册的一个可读，可写或是异常事件，且只触发一次。除非我们使用epoll_ctl重置这个fd上的EPOLLONESHOT事件。这样当一个线程在处理某个socket的时候，其他的线程不会获得处理该线程的机会。同理，注册了EPOLLONESHOT事件的fd一旦被某个线程处理完毕，该线程就应该立即重置这个socket上的该事件，以确保这个socketfd在下一次可读的时候能够被触发。

[EPOLLONESHOT](EPOLLONESHOT_sample.c)

###  此处我们思考如何管理一个服务器的多个客户端连接

+ 网络  IO，会涉及到两个系统对象，一个是用户空间调用  IO 的进程或者线程，另一个是内核 空间的内核系统，比如发生  IO 操作 read 时，它会经历两个阶段：

    > 1 等待数据准备就绪

    > 2 将数据从内核拷贝到进程或者线程中。

+ 由此引出多种网络io模型（5种）

    > 阻塞io + 非阻塞io + 多路复用io + 异步io + 信号驱动io

+ 首先使用最朴素的思想，一个连接一个线程，recv每一个io。优点是很朴素，缺点是极度的耗费资源（太频繁的信号操作是耗内核资源的，内核态 <-> 用户态），动态的开辟线程和初始连接是很慢的。例如[sigio](sigio.c)

+ 之后这里肯定有冗余的操作的，不一定每一个io都需要去进行操作，我们此处引入select/poll/epoll。我们集中考虑这个fd是否可读？可写？是否出错？[select + epoll](server_io.c)

+ 然后io如何存储？对应每一个io，他有那些属性？这里我们就考虑一下[reactor](reactor.c)模式

