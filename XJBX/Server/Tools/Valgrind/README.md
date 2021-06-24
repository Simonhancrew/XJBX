## Valgrind工具(注意加上-g加调试信息)

### 编译安装

```
wget <find the link of valgrind>
tar -jxvf valgrind-x.xx.xx.tar.bz2 //your version
cd valgrind-3.xx.0  // compile the file
./configure   
make 
sudo make install
```

### 实际使用

这里准备一个程序,编译他的时候`gcc -g -O0 sample.c -o sample`

> 为了使 valgrind 发现的错误更精确，如能够定位到源代码行，建议在编译时加上-g 参数，编译优化选项请选择 O0

```
#include <stdio.h>
#include <stdlib.h>
void fun( )
{
    int *p = (int *)malloc(10*sizeof(int));
    p[10] = 0;
    //free(p);
}

int main(void)
{
    fun(); 
    return 0;
}
```

第二部就是使用`valgrind ./sample`直接运行就可以了。

调用 Valgrind 的通用格式是：`valgrind [valgrind-options] your-prog [your-prog- options]`

Valgrind 的参数分为两类，一类是 core 的参数，它对所有的工具都适用；另外一 类就是具体某个工具如 memcheck 的参数。Valgrind 默认的工具就是 memcheck，也可 以通过“--tool=tool name”指定其他的工具。

输出如下

```
==93933== Memcheck, a memory error detector
==93933== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==93933== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
==93933== Command: ./sample
==93933== 
==93933== Invalid write of size 4
==93933==    at 0x10916B: fun (sample.c:6)
==93933==    by 0x109185: main (sample.c:12)
==93933==  Address 0x4a68068 is 0 bytes after a block of size 40 alloc'd
==93933==    at 0x483C855: malloc (vg_replace_malloc.c:380)
==93933==    by 0x10915E: fun (sample.c:5)
==93933==    by 0x109185: main (sample.c:12)
==93933== 
==93933== 
==93933== HEAP SUMMARY:
==93933==     in use at exit: 40 bytes in 1 blocks
==93933==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==93933== 
==93933== LEAK SUMMARY:
==93933==    definitely lost: 40 bytes in 1 blocks
==93933==    indirectly lost: 0 bytes in 0 blocks
==93933==      possibly lost: 0 bytes in 0 blocks
==93933==    still reachable: 0 bytes in 0 blocks
==93933==         suppressed: 0 bytes in 0 blocks
==93933== Rerun with --leak-check=full to see details of leaked memory
==93933== 
==93933== For lists of detected and suppressed errors, rerun with: -s
==93933== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

左边的行数字代表的是 Process ID。最下面会有一个总结。

这里关注一下

```
内存泄露的级别
Definitely（明确地） lost (cover case 3)
no pointer to the block can be found memcheck won't report such blocks individually unless –show-reachable=yes is specified
确定的内存泄露，已经不能够访问这块内存
```

### 利用memecheck发现常见的内存问题

这里枚举几个常见的内存错误使用情况，并说明如何检查他。

#### 1 使用未初始化的内存

对于位于程序中不同段的变量，其初始值是不同的，全局变量和静态变量初始值为 0，而局部变量和动态申请的变量，其初始值为随机值。如果程序使用了为随机值的变 量，那么程序的行为就变得不可预期。

```
#include <stdio.h>

int main(void)
{
    int a[5];
    int i, s;
    a[0] = a[1] = a[2] = a[3] = a[4] = 0;
    for (i = 0; i < 5; i++)
    {
        s += a[i];
    }
    if (s == 377)
    {
        printf("sum is %d\n", s);
    }
    return 0;
}
```

```
==93971== Memcheck, a memory error detector
==93971== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==93971== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
==93971== Command: ./badloop
==93971== 
==93971== Conditional jump or move depends on uninitialised value(s)
==93971==    at 0x1091C9: main (badloop.c:12)
==93971== 
==93971== 
==93971== HEAP SUMMARY:
==93971==     in use at exit: 0 bytes in 0 blocks
==93971==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==93971== 
==93971== All heap blocks were freed -- no leaks are possible
==93971== 
==93971== Use --track-origins=yes to see where uninitialised values come from
==93971== For lists of detected and suppressed errors, rerun with: -s
==93971== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

这里s是局部变量，没有初始话，存在未定义行为。

另外，valgrind 对于 protobuf,stl 这样的 3 方库的兼容性不算太好，所以会造成输出一 堆的 still reachable 字样。其实完全没有必要去纠结这些问题。可以肯定这些都是误判的。 当你使用了这样的库的情况下，一般都会需要将这些检查 option 关闭掉。防止自己被爆 出来的一堆的错误唬住了。信息太多反而阻碍自己的判断。

我们还可以将测试结果指定输出文件。

```
valgrind   --log-file=./valgrind_report.log   --leak-check=full   --show-leak-kinds=all   --show- reachable=no --track-origins=yes ./执行程序
```

#### 内存读写越界

```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int len = 4;
    int *pt = (int *)malloc((len) * sizeof(int));
    int *p = pt;
    for (int i = 0; i < len; i++)
    {
        p++;
    }
    *p = 5;//无效的写入
    printf("the value of p equal:%d\n", *p);
    free(pt);
    
    return 0;
}
```

输出

```
==94096== Memcheck, a memory error detector
==94096== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==94096== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
==94096== Command: ./badacc
==94096== 
==94096== Invalid write of size 4
==94096==    at 0x1091D7: main (badacc.c:13)
==94096==  Address 0x4a68050 is 0 bytes after a block of size 16 alloc'd
==94096==    at 0x483C855: malloc (vg_replace_malloc.c:380)
==94096==    by 0x1091AC: main (badacc.c:7)
==94096== 
==94096== Invalid read of size 4
==94096==    at 0x1091E1: main (badacc.c:14)
==94096==  Address 0x4a68050 is 0 bytes after a block of size 16 alloc'd
==94096==    at 0x483C855: malloc (vg_replace_malloc.c:380)
==94096==    by 0x1091AC: main (badacc.c:7)
==94096== 
the value of p equal:5
==94096== 
==94096== HEAP SUMMARY:
==94096==     in use at exit: 0 bytes in 0 blocks
==94096==   total heap usage: 2 allocs, 2 frees, 1,040 bytes allocated
==94096== 
==94096== All heap blocks were freed -- no leaks are possible
==94096== 
==94096== For lists of detected and suppressed errors, rerun with: -s
==94096== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```

看到了无效的读写都被发现了。

#### 内存覆盖

```
#include <stdio.h>
#include <string.h>

int main(void)
{
    char x[50] = {0};
    
    strncpy(x+20, x, 20);   //ok
    strncpy(x+20, x, 21); // verlap
    strncpy(x, x+20, 20);   //ok
    strncpy(x, x+20, 21); // verlap

    return 0;
}
```

```
==94116== Memcheck, a memory error detector
==94116== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==94116== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
==94116== Command: ./badlap
==94116== 
==94116== Source and destination overlap in strncpy(0x1fff000220, 0x1fff000234, 21)
==94116==    at 0x48429C0: strncpy (vg_replace_strmem.c:564)
==94116==    by 0x109229: main (in /home/space/src-gdb/valgrind/badlap)
==94116== 
==94116== 
==94116== HEAP SUMMARY:
==94116==     in use at exit: 0 bytes in 0 blocks
==94116==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==94116== 
==94116== All heap blocks were freed -- no leaks are possible
==94116== 
==94116== For lists of detected and suppressed errors, rerun with: -s
==94116== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

#### 动态内存管理错误

这里释放后仍然读

````
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p = (char *)malloc(10);
    char *pt = p;
    for(int i = 0; i < 10; i++)
    {
        p[i] = 'z';
    }
    
    delete p;

    pt[1] = 'x';
    free(pt);

    printf("end \n");

    return 0;
}
````

输出

```
==94144== Mismatched free() / delete / delete []
==94144==    at 0x483F8C9: operator delete(void*, unsigned long) (vg_replace_malloc.c:814)
==94144==    by 0x109203: main (badmac.cpp:13)
==94144==  Address 0x4dc7c80 is 0 bytes inside a block of size 10 alloc'd
==94144==    at 0x483C855: malloc (vg_replace_malloc.c:380)
==94144==    by 0x1091BE: main (badmac.cpp:6)
==94144== 
==94144== Invalid write of size 1
==94144==    at 0x10920C: main (badmac.cpp:15)
==94144==  Address 0x4dc7c81 is 1 bytes inside a block of size 10 free'd
==94144==    at 0x483F8C9: operator delete(void*, unsigned long) (vg_replace_malloc.c:814)
==94144==    by 0x109203: main (badmac.cpp:13)
==94144==  Block was alloc'd at
==94144==    at 0x483C855: malloc (vg_replace_malloc.c:380)
==94144==    by 0x1091BE: main (badmac.cpp:6)
==94144== 
==94144== Invalid free() / delete / delete[] / realloc()
==94144==    at 0x483F0C3: free (vg_replace_malloc.c:755)
==94144==    by 0x10921A: main (badmac.cpp:16)
==94144==  Address 0x4dc7c80 is 0 bytes inside a block of size 10 free'd
==94144==    at 0x483F8C9: operator delete(void*, unsigned long) (vg_replace_malloc.c:814)
==94144==    by 0x109203: main (badmac.cpp:13)
==94144==  Block was alloc'd at
==94144==    at 0x483C855: malloc (vg_replace_malloc.c:380)
==94144==    by 0x1091BE: main (badmac.cpp:6)
==94144== 
end 
==94144== 
==94144== HEAP SUMMARY:
==94144==     in use at exit: 0 bytes in 0 blocks
==94144==   total heap usage: 3 allocs, 4 frees, 73,738 bytes allocated
==94144== 
==94144== All heap blocks were freed -- no leaks are possible
==94144== 
==94144== For lists of detected and suppressed errors, rerun with: -s
==94144== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
```

