## 一些基础的Linux服务器的api和工具

- [端序](judgeEndian.c):一个整数在内存排列中的顺序将影响他被加载成为整数的值，一般pc选用的都是小端序。而网络序一般都是大端序。一般我们默认把发送的数据转换成为大端序之后再去发送，接收端总是采用大端序接收，考虑需不需要转换的问题。大端序一般是高位放在内存的低位。linux的netinet/in.h提供了4个函数完成端序的转换，端序的判断和系统转换接口详见[judgeEndian.c](judgeEndian.c)

- [socket监听](socketListen.c):初始socket，命名socket，调用listen监听socket。listen中的backlog提示监听队列的最大长度，超过这个长度不接受新的客户连接。