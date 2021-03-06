## COUNT

开发中，看一个表的行数，一般就直接

```
select count(*) from t
```

但是这个在表越来越大的时候，是存在问题的。

### 实现方式

不同引擎的count实现是不一样的，

+ myisam是把表的总行数记录下来，放在了磁盘上，所以这个速度是很快的，用空间换时间了。
+ InnoDB就比较麻烦了，需要遍历一次

当然这是在不加过滤条件的情况下，实际下加入判断，第一个引擎肯定也不会返回的O(1)那么快的。

这里，思考一下为什么InnoDB不把表的行数存下来，像Myisam一样。

答案就是要考虑MVCC的问题，这个时候，返回多少行是补丁的。这里需要复习一下前面事务隔离的相关记录。

实际执行的时候，数据库还是做了优化的。

InnoDB 是索引组织表，主键索引树的叶子节点是数据，而普通索引树的叶子节点是主键值。所以，普通索引树比主键索引树小很多。对于 count(*) 这样的操作，遍历哪个索引树得到的结果逻辑上都是一样的。因此，MySQL 优化器会找到最小的那棵树来遍历。

这把握一个中心点，就是尽量遍历少的次数，做最多的事，在逻辑正确下。

另外之前，还可以用

```
show table status
```

TABLE_ROWS在这个显示中存在的，但是这里仅仅是一个估算值，在之前选错索引的分析中，我们看到，可能错误偏差还是挺大的。所以不能直接使用。

因此，解决方案就只能是自己去做计数了。

计数的基本思路就是：开辟一块空间，把数据存起来。

### 用缓存系统计数

不如用一个redis来存这些频繁改变的信息。

但是可能丢失是个问题，需要考虑持久化。但实际中，这个值还是不甚精确。

考虑两种情况（考虑会话执行），你要找100行操作记录：

1. 查到的100行里面有新记录，redis尚未更新
2. 没有新纪录，redis却更新了。

并发系统中，这个精度很难控制。

### 用数据库保存计数

这里能够保证逻辑一致和不丢失的问题。

### 总结

count计数的问题，解决方法两种，推荐在数据库单独放一张计数表，同事能解决一致视图的问题。