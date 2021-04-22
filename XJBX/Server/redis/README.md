## remote directory server

reids 是一个有Salvatore Sanfilippo写的k-v存储系统。redis是一个开源的使用Ansi c预研编写，遵守bsd协议，支持网络，可基于内存亦可持久化的日志型，k-v数据库，并支持多种语言api。它通常被称为数据结构服务器，因为值可以是string，hash，list，sets，sorted sets等类型.

## 一 redis 安装

[官网](https://redis.io/)

### 1.1下载redis

[直接下载地址](http://download.redis.io/releases/redis-6.0.3.tar.gz)

```shell
$ wget http://download.redis.io/releases/redis-6.0.3.tar.gz
$ tar zxvf redis-6.0.3.tar.gz
```

### 1.2 编译安装

```shell
$ cd redis-6.03
$ make
$ sudo make install
```

之后会默认安装到/usr/local/bin的位置.对应redis-server是服务端程序,redis-cli是客户端程序

查看版本

```
$ redis-server -v
```

### 1.3 启动redis

#### 1 直接启动

```
$ redis-server
```

#### 2 后台启动

在/etc创建redis目录

```
$ sudo mkdir /etc/redis
```

 将编译目录下的redis.conf拷贝到/etc/redis目录下

```
$ sudo cp redis.conf /etc/redis/6379.conf
```

修改改复制的文件,将

```
$ daemonize no
```

改为

```
$ daemonize yes
```

指定6379.conf文件启动

```
$ redis-server /etc/redis/6379.conf
```

查看redis进程id

```
$ ps -ef | grep redis
```

### 1.4 redis-cli的使用

#### 1默认无权限控制

```
$ redis-cli -h 127.0.0.1 -p 6379
```

#### 2服务停止

```
$ redis-cli -h 127.0.0.1 -p 6379 shutdown
```

#### 3有权控制(-a 密码)

 在.conf文件中找到requirepass选项后的密码

```
$ redis-cli -h 127.0.0.1 -p 6379 -a <密码>
```

#### 4 redis默认启动

端口127.0.0.1,默认6379

```
$ redis-cll
```

### 1.5redis多线程

#### 1 如需开启需要修改   redis.conf 配置文件：io-threads-do-reads yes

#### 2 Redis 6.0 多线程开启时，线程数如何设置

开启多线程后，还需要设置线程数，否则是不生效的。同样修改   redis.conf 配置文件

```
io-threads 4
```

关于线程数的设置，官方有一个建议：4 核的机器建议设置为   2 或    3 个线程，8 核的建议设置为
6 个线程，线程数一定要小于机器核数

### 1.6 抓包分析

```
$ sudo tcpdump -i any dst host 127.0.0.1 and port 6379
```

## 二 基本数据结构

