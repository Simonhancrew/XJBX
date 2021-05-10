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

### 2.1 key

| set key value                        | 设置键值                                                     |
| ------------------------------------ | :----------------------------------------------------------- |
| DEL key                              | key存在时删除                                                |
| Dump key                             | 序列化给定 key  ，并返回被序列化的值。                       |
| EXISTS key                           | 检查给定 key  是否存在                                       |
| EXPIRE key seconds                   | 为给定 key  设置过期时间，以秒计。                           |
| EXPIREAT key timestamp               | EXPIREAT  的作用和   EXPIRE  类似，都用于为    key  设置过期时间。不同在于    EXPIREAT  命 令接受的时间参数是   UNIX  时间戳(unix timestamp)。 |
| PEXPIRE key milliseconds             | 设置 key  的过期时间以毫秒计。                               |
| PEXPIREAT key milliseconds-timestamp | 设置 key  过期时间的时间戳(unix timestamp)  以毫秒计         |
| KEYS pattern                         | 查找所有符合给定模式( pattern)的 key  。                     |
| MOVE key db                          | 将当前数据库的 key  移动到给定的数据库 db  当中              |
| PERSIST key                          | 移除 key  的过期时间，key  将持久保持。                      |
| PTTL key                             | 以毫秒为单位返回 key  的剩余的过期时间。                     |
| TTL key                              | 以秒为单位，返回给定 key  的剩余生存时间(TTL, time to live)。 |
| RANDOMKEY                            | 从当前数据库中随机返回一个 key  。                           |
| RENAME key newkey                    | 修改    key  的名称                                          |
| RENAMENX key newkey                  | 仅当 newkey  不存在时，将 key  改名为 newkey  。             |
| TYPE key                             | 返回 key  所储存的值的类型                                   |

### 2.2 String

Redis 字符串数据类型的相关命令用于管理redis字符串值，基本语法如下

```
$ SET han redis
$ get han
"redis"
```

| 命令                           | 描述                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| SET key value                  | 设置指定 key  的值                                           |
| GET key                        | 获取指定 key  的值。                                         |
| GETRANGE key start end         | 返回 key  中字符串值的子字符                                 |
| GETSET key value               | 将给定 key  的值设为 value  ，并返回 key  的旧值(old value)。 |
| GETBIT key offset              | 对 key  所储存的字符串值，获取指定偏移量上的位(bit)          |
| MGET key1 [key2..]             | 获取所有(一个或多个)给定 key  的值。                         |
| SETBIT key offset value        | 对 key  所储存的字符串值，设置或清除指定偏移量上的位(bit)。  |
| SETEX key seconds value        | 将值 value  关联到 key  ，并将 key  的过期时间设为 seconds (以秒为单位)。 |
| SETNX key value                | 只有在 key  不存在时设置 key  的值。                         |
| SETRANGE key offset value      | 用 value  参数覆写给定 key  所储存的字符串值，从偏移量 offset  开始。 |
| STRLEN key                     | 返回 key  所储存的字符串值的长度。                           |
| MSET key value [key value ...] | **同时设置一个或多个 key-value  对。**                       |
| PSETEX key milliseconds value  | 这个命令和   SETEX  命令相似，但它以毫秒为单位设置   key  的生存时间，而不是像    SETEX 命令那样，以秒为单位。 |
| INCR key                       | 将 key  中储存的数字值增一                                   |
| INCRBY key increment           | 将 key  所储存的值加上给定的增量值（increment）。            |
| INCRBYFLOAT key increment      | 将 key  所储存的值加上给定的浮点增量值（increment）。        |
| DECR key                       | 将 key  中储存的数字值减一。                                 |
| DECRBY key decrement           | key  所储存的值减去给定的减量值（decrement） 。              |
| APPEND key value               | 如果    key  已经存在并且是一个字符串，APPEND  命令将指定的   value  追加到该   key  原 来值（value）的末尾。 |

缓存图片:set redis-log.jpg redis-log-data(网站首页的图片可以缓存在redis中,减少硬盘的load)

- 字符串的值既可以存储文字数据，又可以存储二进制数据
- MSET/MGET 命令可以有效地减少程序的网络通信次数，从而提高程序的执行效率
- redis 用户可以定制命名格式来提升  redis 数据的可读性并避免键名冲突

### 2.3 hash散列表

Redis hash 是一个   string 类型的   field 和   value 的映射表，hash 特别适合用于存储对象。Re dis 中每个   hash 可以存储 2<sup>31</sup> - 1 键值对（40多亿）

```
$ hmset han name "redis tutorial" likes 20 visitors 23000
OK
$ hgetall han
1) "name"
2) "redis tutorial"
3) "likes"
4) "20"
5) "visitors"
6) "23000
```

| 命令                                           | 描述                                                       |
| ---------------------------------------------- | ---------------------------------------------------------- |
| HSET key field value                           | 将哈希表 key  中的字段 field  的值设为 value  。           |
| HMSET key field1 value1 [field2 value2 ]       | 同时将多个 field-value (域-值)对设置到哈希表 key  中。     |
| HSETNX key field value                         | 只有在字段 field  不存在时，设置哈希表字段的值             |
| HVALS key                                      | 获取哈希表中所有值                                         |
| HSCAN key cursor [MATCH pattern] [COUNT count] | 迭代哈希表中的键值对                                       |
| HLEN key                                       | 获取哈希表中字段的数量                                     |
| HKEYS key                                      | 获取所有哈希表中的字段                                     |
| HINCRBYFLOAT key field increment               | 为哈希表 key  中的指定字段的浮点数值加上增量 increment  。 |
| HINCRBY key field increment                    | 为哈希表 key  中的指定字段的整数值加上增量 increment  。   |
| HGETALL key                                    | 获取在哈希表中指定 key  的所有字段和值                     |
| HGET key field                                 | 获取存储在哈希表中指定字段的值。                           |
| HEXISTS key field                              | 查看哈希表 key  中，指定的字段是否存在                     |
| HDEL key field1 [field2]                       | 删除一个或多个哈希表字段                                   |

例如短网址生成

| key        | field | value      |
| ---------- | ----- | ---------- |
| https://短 | link  | https://长 |
|            | count | 1          |

- 散列的最大优势，只需要在数据库里面创建一个键，就可以把任意多的字段和值存储到散列里面。
- 虽然散列键命令和字符串键命令在部分功能上有重合的地方，但是字符串键命令提供的操作比散列 键命令更为丰富。比如，字符串能够使用 SETRANGE 命令和 GETRANGE 命令设置或者读取字符 串值的其中一部分，或者使用 APPEND 命令将新内容追加到字符串值的末尾，而散列键并不支持 这些操作。
- 再比如我们要设置键过期时间，**键过期时间是针对整个键的**，**用户无法为散列中的不同字段设置不 同的过期时间**，所以当一个散列键过期的时候，他包含的所有字段和值都会被删除。与此相反，如 果用户使用字符串键存储信息项，就不会遇到这样的问题——用户可以为每个字符串键分别设置不 同的过期时间，让它们根据实际的需要自动被删除。

| 比较主题   | 结果                                                         |
| ---------- | ------------------------------------------------------------ |
| 资源占用   | 字符串键在数量较多的情况下，将占用大量的内存和 cpu 时间。与此相反，将多个数据项存储到同一个散列中可以有效地减少内存和 cpu 消 耗。 |
| 支持的操作 | 散列键支持的所有命令，几乎都有对应的字符串键版本，但字符串键支 持的 SETRANGE、GETRANGE、APPEND 等操作散列并不具备。 |
| 过期时间   | 字符串可以为单个键单独设置过期时间，独立删除某个数据项，而散列 一旦到期，它包含的所有字段和值都会被删除。 |

适用场景:

1. 如果程序需要为单个数据项单独设置过期的时间，那么使用字符串键。
2. 如果程序需要对数据项执行诸如 SETRANGE、GETRANGE 或者 APPEND 等操作，那么优 先考虑使用字符串键。当然，用户也可以选择把数据存储在散列中，然后将类似 SETRANG E、GETRANGE 这样的操作交给客户端执行。
3. 如果程序需要存储的数据项比较多，并且你希望尽可能地减少存储数据所需的内存，就应该优 先考虑使用散列键。
4. 如果多个数据项在逻辑上属于同一组或者同一类，那么应该优先考虑使用散列键。

### 2.4 List

Redis 列表是简单的字符串列表，按照插入顺序排序。你可以添加一个元素到列表的头部（左边）或者 尾部（右边）一个列表最多可以包含    2<sup>32</sup> - 1  个元素    (4294967295,  每个列表超过  40 亿个元素)

```
$ lpush han redissss
(integer) 1
$ lpush han meme
(integer) 2
$ RPUSH han hehe
(integer) 3
$ lrange han 0 5
1) "meme"
2) "redissss"
3) "hehe"
```

| 命令                                  | 描述                                                         |
| ------------------------------------- | ------------------------------------------------------------ |
| LPUSH key value1 [value2]             | 将一个或多个值插入到列表头部                                 |
| LRANGE key start stop                 | 获取列表指定范围内的元素                                     |
| BRPOP key1 [key2 ] timeout            | 移出并获取列表的最后一个元素， 如果列表没有元素会阻塞列表直到等待超时或发现 可弹出元素为止。 |
| BLPOP key1 [key2 ] timeout            | 移出并获取列表的第一个元素， 如果列表没有元素会阻塞列表直到等待超时或发现可 弹出元素为止。 |
| BRPOPLPUSH source destination timeout | 从列表中弹出一个值，将弹出的元素插入到另外一个列表中并返回它；  如果列表没有 元素会阻塞列表直到等待超时或发现可弹出元素为止。 |
| LINDEX key index                      | 通过索引获取列表中的元素                                     |
| LINSERT key BEFORE\|AFTER pivot value | 在列表的元素前或者后插入元素                                 |
| LLEN key                              | 获取列表长度                                                 |
| LPOP key                              | 移出并获取列表的第一个元素                                   |
| LPUSHX key value                      | 将一个值插入到已存在的列表头部                               |
| LREM key count value                  | 移除列表元素                                                 |
| LSET key index value                  | 通过索引设置列表元素的值                                     |
| LTRIM key start stop                  | 对一个列表进行修剪(trim)，就是说，让列表只保留指定区间内的元素，不在指定区间 之内的元素都将被删除。 |
| RPOP key                              | 移除列表的最后一个元素，返回值为移除的元素。                 |
| RPOPLPUSH source destination          | 移除列表的最后一个元素，并将该元素添加到另一个列表并返回     |
| RPUSH key value1 [value2]             | 在列表中添加一个或多个值                                     |
| RPUSHX key value                      | 为已存在的列表添加值                                         |

例如:

+ 先进先出队列,秒杀活动,把用户的购买操作全部放入队列
+ 分页

### 2.5 set集合(有点像unordered_set)

Redis 的Set  是    String  类型的无序集合。集合成员是唯一的，这就意味着集合中不能出现重复的数据.Redis  中集合是通过哈希表实现的，所以添加，删除，查找的复杂度都是O(1).集合中最大的成员数为2<sup>32</sup> - 1 (4294967295,  每个集合可存储  40 多亿个成员)。

```
$ sadd ahan redis
$ smembers ahan
1) "redis"
```

| 命令                                           | 描述                                                   |
| ---------------------------------------------- | ------------------------------------------------------ |
| SADD key member1 [member2]                     | 向集合添加一个或多个成员                               |
| SMEMBERS key                                   | 返回集合中的所有成员                                   |
| SCARD key                                      | 获取集合的成员数                                       |
| SDIFF key1 [key2]                              | 返回给定所有集合的差集                                 |
| SDIFFSTORE destination key1 [key2]             | 返回给定所有集合的差集并存储在 destination  中         |
| SINTER key1 [key2]                             | 返回给定所有集合的交集                                 |
| SISMEMBER key member                           | 判断 member  元素是否是集合 key  的成员                |
| SINTERSTORE destination key1 [key2]            | 返回给定所有集合的交集并存储在 destination  中         |
| SMOVE source destination member                | 将 member  元素从 source  集合移动到 destination  集合 |
| SPOP key                                       | 移除并返回集合中的一个随机元素                         |
| SRANDMEMBER key [count]                        | 返回集合中一个或多个随机数                             |
| SREM key member1 [member2]                     | 移除集合中一个或多个成员                               |
| SUNION key1 [key2]                             | 返回所有给定集合的并集                                 |
| SUNIONSTORE destination key1 [key2]            | 所有给定集合的并集存储在    destination  集合中        |
| SSCAN key cursor [MATCH pattern] [COUNT count] | 迭代集合中的元素                                       |

应用:

+ 唯一计数器:用户访问数和ip地址访问数

```
加入 IP:SADD users:count 202.177.2.232 
计算总数:SCARD users:count
```

  ### 2.6 soted set(有点像set)

Redis 有序集合和集合一样也是 string类型元素的集合,且不允许重复的成员。不同的是每个元素 都会关联一个 double类型的分数。redis正是通过分数来为集合中的成员进行从小到大的排序。 有序集合的成员是唯一的,但分数(score)却可以重复。集合是通过哈希表实现的,增删改查都是O(1).集合中最大的成员数为2<sup>32</sup> - 1 (4294967295,  每个集合可存储  40 多亿个成员)。

```
zadd hanhanhan 1 redis
zadd hanhanhan 2 mongodb
zrange hanhanhan 0 10
1) "redis"
2) "mongodb"
```



| 命令                                           | 描述                                                         |
| ---------------------------------------------- | ------------------------------------------------------------ |
| ZADD key score1 member1 [score2 member2]       | 向有序集合添加一个或多个成员，或者更新已存在成员的分数       |
| ZCARD key                                      | 获取有序集合的成员数                                         |
| ZCOUNT key min max                             | 计算在有序集合中指定区间分数的成员数                         |
| ZINCRBY key increment member                   | 有序集合中对指定成员的分数加上增量 increment                 |
| ZINTERSTORE destination numkeys key [key ...]  | 计算给定的一个或多个有序集的交集并将结果集存储在新的有序集合 key  中 |
| ZLEXCOUNT key min max                          | 在有序集合中计算指定字典区间内成员数量                       |
| ZRANGE key start stop [WITHSCORES]             | 通过索引区间返回有序集合成指定区间内的成员                   |
| ZRANGEBYLEX key min max [LIMIT offset count]   | 通过字典区间返回有序集合的成员                               |
| ZRANGEBYSCORE key min max [WITHSCORES] [LIMIT] | 通过分数返回有序集合指定区间内的成员                         |
| ZRANK key member                               | 返回有序集合中指定成员的索引                                 |
| ZREM key member [member ...]                   | 移除有序集合中的一个或多个成员                               |
| ZREMRANGEBYLEX key min max                     | 移除有序集合中给定的字典区间的所有成员                       |
| ZREMRANGEBYRANK key start stop                 | 移除有序集合中给定的排名区间的所有成员                       |
| ZREMRANGEBYSCORE key min max                   | 移除有序集合中给定的分数区间的所有成员                       |
| ZREVRANGE key start stop [WITHSCORES]          | 返回有序集中指定区间内的成员，通过索引，分数从高到底         |
| ZREVRANGEBYSCORE key max min [WITHSCORES]      | 返回有序集中指定分数区间内的成员，分数从高到低排序           |
| ZREVRANK key member                            | 返回有序集合中指定成员的排名，有序集成员按分数值递减(从大到小)排序 |
| ZSCORE key member                              | 返回有序集中，成员的分数值                                   |
| ZUNIONSTORE destination numkeys key [key ...]  | 计算给定的一个或多个有序集的并集，并存储在新的 key  中       |
| ZSCAN key cursor [MATCH pattern] [COUNT count] | 迭代有序集合中的元素（包括元素成员和元素分值）               |

应用:

+ 排行榜

```
(1)  点击新闻（今天热搜） zincrby hotNews:20190802 1 NASA
(2)  展示当日前 10
zrevrange hotNews:20190802 0 9 WITHSCORES
(3)  三天热搜榜单统计
zunionstore hotNews:20190731-20190802 3 hotNews: 20190731 hotNews:20190801 hotNews:20190802 
(4)  展示三天排行前 10
zrevrange hotNews: 20190731-20190802 0 10 WITHSCORES
```

+ 事件线

## 三 操作命令

### 3.1 hyperloglog

Redis 在 2.8.9 版本添加了 HyperLogLog 结构。Redis HyperLogLog 是用来做基数统计的算法， HyperLogLog 的优点是，在输入元素的数量或者体积非常非常大时，计算基数所需的空间总是固定 的并且是很小的。在 Redis 里面，每个 HyperLogLog 键只需要花费 12 KB 内存，就可以计算接 近 2<sup>64</sup> 个不同元素的基数。这和计算基数时，元素越多耗费内存就越多的集合形成鲜明对比。但 是，因为 HyperLogLog 只会根据输入元素来计算基数，而不会储存输入元素本身，所以 HyperLog Log 不能像集合那样，返回输入的各个元素。

| 命令                                      | 描述                                       |
| ----------------------------------------- | ------------------------------------------ |
| PFADD key element [element ...]           | 添加指定元素到 HyperLogLog  中。           |
| PFCOUNT key [key ...]                     | 返回给定 HyperLogLog  的基数估算值。       |
| PFMERGE destkey sourcekey [sourcekey ...] | 将多个 HyperLogLog  合并为一个 HyperLogLog |

### 3.2 发布订阅

Redis 发布订阅(pub/sub)是一种消息通信模式：发送者(pub)发送消息，订阅者(sub)接收消息。R edis 客户端可以订阅任意数量的频道。

### 3.3 redis事务

Redis 事务可以一次执行多个命令，   并且带有以下三个重要的保证： 

1. 批量操作在发送   EXEC 命令前被放入队列缓存。
2.  收到   EXEC 命令后进入事务执行，事务中任意命令执行失败，其余的命令依然被执行。 
3. 在事务执行过程，其他客户端提交的命令请求不会插入到事务执行命令序列中。

一个事务从开始到执行会经历以下三个阶段：

1. 开始事务
2. 命令入队。
3. 执行事务。

| 命令                | 描述                                                         |
| ------------------- | ------------------------------------------------------------ |
| DISCARD             | 取消事务，放弃执行事务块内的所有命令。                       |
| EXEC                | 执行所有事务块内的命令。                                     |
| MULTI               | 标记一个事务块的开始。                                       |
| UNWATCH             | 取消 WATCH  命令对所有 key  的监视。                         |
| WATCH key [key ...] | 监视一个(或多个) key  ，如果在事务执行之前这个(或这些) key  被其他命令所改动， 那么事务将被打断。 |

因为事务在执行时会独占服务器，所以用户应该避免在事务中执行过多命令，更不要将一些需要进 行大量计算的命令放入事务中，以免造成服务器阻塞。

## 四 C语言使用redis

### 4.1 编译 hiredis

```
cd redis-6.0.3/deps/hiredis
make
sudo make install
mkdir -p /usr/local/include/hiredis /usr/local/include/hiredis/adapters /usr/local/lib 
cp -pPR hiredis.h async.h read.h sds.h /usr/local/include/hiredis
cp -pPR adapters/*.h /usr/local/include/hiredis/adapters 
cp -pPR libhiredis.so /usr/local/lib/libhiredis.so.0.14 
cd /usr/local/lib && ln -sf libhiredis.so.0.14 libhiredis.so 
cp -pPR libhiredis.a /usr/local/lib
mkdir -p /usr/local/lib/pkgconfig
cp -pPR hiredis.pc /usr/local/lib/pkgconfig
```

###  4.2连接redis

 ```
//连接Redis服务
redisContext *context = redisConnect("127.0.0.1", 6379);
    if (context == NULL || context->err) {
        if (context) {
           printf("%s\n", context->errstr);
        } else {
           printf("redisConnect error\n");
        }
        exit(EXIT_FAILURE);
   }
 ```

### 4,3 授权auth

```
	redisReply *reply = redisCommand(context, "auth QAQ"); 
	printf("type : %d\n", reply->type);
	if (reply->type == REDIS_REPLY_STATUS) { 
		/*SET str Hello World*/
		printf("auth ok\n"); 
	}
	freeReplyObject(reply);
```

**void *redisCommand(redisContext *c, const char *format, ...);**

这个函数是一个带有不定参数的。可以按着 format 格式给出对应的参数，这就和  printf 函数类似。 c  是一个  reidsConnect 函数返回的一个对象

### 4.4 set/get/append

```
	char *key = "str";
	char *val = "Hello World"; /*SET key value */
	reply = redisCommand(context, "SET %s %s", key, val); 
	printf("type : %d\n", reply->type);
	if (reply->type == REDIS_REPLY_STATUS) { 
		/*SET str Hello World*/
		printf("SET %s %s\n", key, val); 
	}
	freeReplyObject(reply)
```

 ```
// GET Key
	reply = redisCommand(context, "GET %s", key); 
	if (reply->type == REDIS_REPLY_STRING) {
	/*GET str Hello World*/
	printf("GET str %s\n", reply->str); /*GET len 11*/
	printf("GET len %ld\n", reply->len); 
	}
	freeReplyObject(reply);
 ```

```
// APPEND key value
	char *append = " I am your GOD";
	reply = redisCommand(context, "APPEND %s %s", key, append); 
	if (reply->type == REDIS_REPLY_INTEGER) {
		printf("APPEND %s %s \n", key, append); 
	}
	freeReplyObject(reply); /*GET key*/
	reply = redisCommand(context, "GET %s", key); 
	if (reply->type == REDIS_REPLY_STRING) {
		//GET Hello World I am your GOD 
		printf("GET %s\n", reply->str);
	}
	freeReplyObject(reply);
```



