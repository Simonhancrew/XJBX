## LeptCloud

LeptCloud是一个支持分布式存储的高负载解决方案。项目中涉及到了的常见中间件，和一些开发的常见工具。在研发的路径中收获良多，记录若干。

### 开门见山

在Leptcloud中，我使用fastdfs作为文件储存系统，nginx反向代理相关请求到端口，通过fastcgi的后台进程持续处理。mysql维护我的用户信息，redis维护登录的token减小存储的压力。

### 关于选型和瓶颈测试

这里的项目仅仅作为自己的练习和熟悉相关开发流程的学习之用，并没有涉及到超大规模的并发设计。在压测中，理论和经验情况下，常规服务器下支持10w人的并发还是没有问题的。

如何压测？后续会更新压测和瓶颈的分析，有些是利用code测试实现，有些会用wrk做压测。

### 项目文档和构架简析

![构架图](./pic/1.png)

整体构架图如上，详细记录会在后续讲解。项目实现的服务端代码在同目录的src下。

mysql中记录了用户信息和用户的文件信息，fastdfs中进行文件操作的时候会将记录写入mysql中。

接口文档在同目录下的API文档中

### 如何设计数据表和我的思路

首先给出设计的数据库表

```
#数据库表
#创建数据库
DROP database IF EXISTS `LEPTCLOUD_disk`;
CREATE DATABASE `LEPTCLOUD_disk`;

#使用数据库
use `LEPTCLOUD_disk`;


DROP TABLE IF EXISTS `file_info`;
CREATE TABLE `file_info` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '文件序号，自动递增，主键',
  `md5` varchar(256) NOT NULL COMMENT '文件md5',
  `file_id` varchar(256) NOT NULL COMMENT '文件id:/group1/M00/00/00/xxx.png',
  `url` varchar(512) NOT NULL COMMENT '文件url 192.168.52.139:80/group1/M00/00/00/xxx.png',
  `size` bigint(20) DEFAULT '0' COMMENT '文件大小, 以字节为单位',
  `type` varchar(32) DEFAULT '' COMMENT '文件类型： png, zip, mp4……',
  `count` int(11) DEFAULT '0' COMMENT '文件引用计数,默认为1。每增加一个用户拥有此文件，此计数器+1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=70 DEFAULT CHARSET=utf8 COMMENT='文件信息表';


DROP TABLE IF EXISTS `share_file_list`;
CREATE TABLE `share_file_list` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '编号',
  `user` varchar(32) NOT NULL COMMENT '文件所属用户',
  `md5` varchar(256) NOT NULL COMMENT '文件md5',
  `file_name` varchar(128) DEFAULT NULL COMMENT '文件名字',
  `pv` int(11) DEFAULT '1' COMMENT '文件下载量，默认值为1，下载一次加1',
  `create_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '文件共享时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COMMENT='共享文件列表';


DROP TABLE IF EXISTS `user_file_count`;
CREATE TABLE `user_file_count` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user` varchar(128) NOT NULL COMMENT '文件所属用户',
  `count` int(11) DEFAULT NULL COMMENT '拥有文件的数量',
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_UNIQUE` (`user`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COMMENT='用户文件数量表';


DROP TABLE IF EXISTS `user_file_list`;
CREATE TABLE `user_file_list` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '编号',
  `user` varchar(32) NOT NULL COMMENT '文件所属用户',
  `md5` varchar(256) NOT NULL COMMENT '文件md5',
  `create_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '文件创建时间',
  `file_name` varchar(128) DEFAULT NULL COMMENT '文件名字',
  `shared_status` int(11) DEFAULT NULL COMMENT '共享状态, 0为没有共享， 1为共享',
  `pv` int(11) DEFAULT NULL COMMENT '文件下载量，默认值为0，下载一次加1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=utf8 COMMENT='用户文件列表';


DROP TABLE IF EXISTS `user_info`;
CREATE TABLE `user_info` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '用户序号，自动递增，主键',
  `user_name` varchar(32) NOT NULL DEFAULT '' COMMENT '用户名称',
  `nick_name` varchar(32) CHARACTER SET utf8mb4 NOT NULL DEFAULT '' COMMENT '用户昵称',
  `password` varchar(32) NOT NULL DEFAULT '' COMMENT '密码',
  `phone` varchar(16) NOT NULL DEFAULT '' COMMENT '手机号码',
  `email` varchar(64) DEFAULT '' COMMENT '邮箱',
  `create_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP COMMENT '时间',
  PRIMARY KEY (`id`),
  UNIQUE KEY `uq_nick_name` (`nick_name`),
  UNIQUE KEY `uq_user_name` (`user_name`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8 COMMENT='用户信息表';
```



### 分布式文件系统详解

 

### Q&A

+ 云盘多⼤上传量，⾼峰期能到多少
+ 同⼀个group⾥的storage如何做同步
+ 不同group⾥的storage能否做同步
+ 存储的storage服务器宕机了，其他storage如何同步？
+ 如何防⽌盗链
+ FastDFS如何应对单点故障
+ 能否⽀持断点续传？如何实现？
+ 能否⽀持⼩⽂件合并
+ 如何实现负载均衡

