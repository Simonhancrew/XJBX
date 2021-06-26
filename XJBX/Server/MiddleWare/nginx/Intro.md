## Nginx

主要的三个应用场景

1. 访问静态资源
2. API服务 -> 数据库缓存服务器
3. 反向代理（缓存加速，负载均衡）-> 应用服

### Nginx的特点

1. 高并发
2. 可扩展
3. 高可靠
4. 热部署
5. BSD许可（可以修改源码）

### Nginx组成

+ Nginx二进制可执行文件，各个模块源码编译而来
+ Nginx.conf配置文件，控制nginx的行为
+ access.log访问日志
+ error.log错误日志

### 编译和使用

自己编译安装，不然的话可能有些模块不能自己使用。

进入网址，下载stable版本

```
https://nginx.org/en/download.html
```

然后

```
tar -xzf  nginx-1.20.1.tar.gz 
```

进入目录之后可以看到如下的文件夹分布,changes是一个迭代版本的更改记录

```
drwxr-xr-x  6 han han   4096 6月  26 00:08 auto/
-rw-r--r--  1 han han 311503 5月  25 20:35 CHANGES
-rw-r--r--  1 han han 475396 5月  25 20:35 CHANGES.ru // 俄语
drwxr-xr-x  2 han han   4096 6月  26 00:08 conf/   // 示例文件
-rwxr-xr-x  1 han han   2590 5月  25 20:35 configure* //执行编译前
drwxr-xr-x  4 han han   4096 6月  26 00:08 contrib/ // vim的东西吧
drwxr-xr-x  2 han han   4096 6月  26 00:08 html/   // 标准的html文件
-rw-r--r--  1 han han   1397 5月  25 20:35 LICENSE 
drwxr-xr-x  2 han han   4096 6月  26 00:08 man/    // 不解释
-rw-r--r--  1 han han     49 5月  25 20:35 README  
drwxr-xr-x  9 han han   4096 6月  26 00:08 src/   // 源码分布
```

之后执行编译就行了

```
./configure --prefix=xxxxx
make
sudo make install
```

