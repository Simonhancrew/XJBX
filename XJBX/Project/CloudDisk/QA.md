## Q&A

### 两个storage怎么做同步

1. 只在本组内的storage server之间进⾏同步；
2. 源头数据才需要同步，备份数据不需要再次同步，否则就构成环路了，源数据和备份数据区 分是用 binlog的操作类型来区分，操作类型是⼤写字⺟，表示源数据，⼩写字⺟表示备份数据；
3. 当先新增加⼀台storage server时，由已有的⼀台storage server将已有的所有数据（包括源头数据和 备份数据）同步给该新增服务器。

线程：

+ tracker_report_thread_entrance ，连接tracker有独⽴的线程，连接n个tracker就有n个线程
+ storage_sync_thread_entrance ，给同group的storage做同步，同组有n个storage，就有n-1个线 程

同步命令

```
#define STORAGE_PROTO_CMD_SYNC_CREATE_FILE     16    //新增⽂件 
#define STORAGE_PROTO_CMD_SYNC_DELETE_FILE     17  // 删除⽂件 
#define STORAGE_PROTO_CMD_SYNC_UPDATE_FILE    18    // 更新⽂件 
#define STORAGE_PROTO_CMD_SYNC_CREATE_LINK    19  // 创建链接
```

#### binlog格式

FastDFS⽂件同步采⽤binlog异步复制⽅式。storage server使⽤binlog⽂件记录⽂件上传、删除等操 作，根据binlog进⾏⽂件同步。binlog中只记录⽂件ID和操作，不记录⽂件内容。

```
1572660675 C M00/00/00/oYYBAF285cOIHiVCAACI-7zX1qUAAAAVgAACC8AAIkT490.txt
1572660827 c M00/00/00/oYYBAF285luIK8jCAAAJeheau6AAAAAVgABI-cAAAmS021.xml
1572660911 D M00/00/00/oYYBAF285cOIHiVCAACI-7zX1qUAAAAVgAACC8AAIkT490.txt
1572660967 d M00/00/00/oYYBAF285luIK8jCAAAJeheau6AAAAAVgABI-cAAAmS021.xml
```

从上⾯可以看到，binlog⽂件有三列，依次为：

+ 时间戳
+ 操作类型
+ ⽂件ID（不带group名称）
  + Storage_id（ip的数值型)
  + timestamp（创建时间）
  + file_size（若原始值为32位则前⾯加⼊⼀个随机值填充，最终为64位）
  + crc32（⽂件内容的检验码）

同组内的storage server之间是对等的，文件上传、删除等操作可以在任意⼀台storage server上进⾏。 ⽂件同步只在同组内的storage server之间进⾏，采⽤push⽅式，即源头服务器同步给本组的其他存储服 务器。对于同组的其他storage server，⼀台storage server分别启动⼀个线程进⾏文件同步。

⽂件同步采⽤增量⽅式，记录已同步的位置到mark⽂件中。

#### 同步规则

1. 只在本组内的storage server之间进⾏同步；
2. 源头数据才需要同步，备份数据不需要再次同步，否则就构成环路了，源数据和备份数据区 分是⽤ binlog的操作类型来区分，操作类型是⼤写字⺟，表示源数据，⼩写字⺟表示备份数据；
3. 当先新增加⼀台storage server时，由已有的⼀台storage server将已有的所有数据（包括源头数据和 备份数据）同步给该新增服务器。

#### binlog同步过程

在FastDFS之中，每个Storage之间的同步都是由⼀个独⽴线程负责的，该线程中的所有操作都是以同步方式执⾏的。⽐如⼀组服务器有A、B、C三台机器，那么在每台机器上都有两个线程负责同步，如A机器， 线程1负责同步数据到B，线程2负责同步数据到C

