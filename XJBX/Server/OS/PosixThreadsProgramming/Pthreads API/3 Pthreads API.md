# Pthreads API

最初的 Pthreads API 是在 ANSI/IEEE POSIX 1003.1 - 1995 标准中定义的。 POSIX 标准一直在不断的发展和修订，包括 Pthreads 规范也是如此。

该标准的副本可以从 IEEE 购买或从其他在线站点免费下载。

构成 Pthreads API 的子程序可以非正式地分为四大组：

+ 线程管理：直接在线程上工作的程序，creating，detaching，joining等。他们还包括设置查询线程属性（可调度，可汇合）的函数
+ 互斥变量：处理同步的例程，称为“互斥”，是“互斥”的缩写。互斥锁函数提供了创建、销毁、锁定和解锁互斥锁的功能。这些由设置或修改与互斥锁关联的属性的互斥锁属性函数补充。
+ 条件变量：解决共享互斥锁的线程之间通信的例程。基于程序员指定的条件。该组包括根据指定的变量值创建、销毁、等待和发出信号的函数。还包括设置/查询条件变量属性的函数。
+ 同步：管理读写锁和barrier的程序

命名约定：线程库中所有的标识符都以pthread_开头。下面显示了一些示例

<table style="border-collapse:collapse;border-spacing:0" class="tg"><thead><tr><th style="background-color:#98ABCE;border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;position:-webkit-sticky;position:sticky;text-align:center;top:-1px;vertical-align:middle;will-change:transform;word-break:normal"><span style="background-color:#98ABCE">Routine Prefix</span></th><th style="background-color:#98ABCE;border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;position:-webkit-sticky;position:sticky;text-align:center;top:-1px;vertical-align:middle;will-change:transform;word-break:normal"><span style="background-color:#98ABCE">Functional Group</span></th></tr></thead><tbody><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Threads themselves and miscellaneous subroutines</td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_attr_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Thread attributes objects</td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_mutex_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Mutexes</td></tr><tr><td style="border-color:inherit;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_mutexattr_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Mutex attributes objects.</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_cond_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Condition variables</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_condattr_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Condition attributes objects</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_key_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Thread-specific data keys</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_rwlock_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Read/write locks</td></tr><tr><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;font-weight:bold;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:top;word-break:normal">pthread_barrier_</td><td style="border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;text-align:left;vertical-align:middle;word-break:normal">Synchronization barriers</td></tr></tbody></table>

不透明对象的概念遍及 API 的设计。不透明对象的概念遍及 API 的设计。基本调用用于创建或修改不透明对象 - 可以通过调用处理不透明属性的属性函数来修改不透明对象。

Pthreads API 包含大约 100 个子例程。本教程将重点介绍其中的一个子集——特别是那些最有可能对 Pthreads 初级程序员立即有用的那些。

为了可移植性，pthread.h 头文件应该包含在每个使用 Pthreads 库的源文件中。

当前的 POSIX 标准仅针对 C 语言定义。 Fortran 程序员可以使用 C 函数调用的包装器。某些 Fortran 编译器可能提供 Fortran pthreads API。

有许多关于 Pthreads 的优秀书籍可用。本教程的[参考资料](https://hpc-tutorials.llnl.gov/posix/references/)部分列出了其中一些。