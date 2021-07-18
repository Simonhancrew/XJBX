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

### 具体部署

首先是几个命令，在`/usr/local/nginx/sbin`下有可执行文件，具体启动命令如下

```
./sbin/nginx –c ./conf/nginx.conf
```

另外还可以通过-s参数来控制启动后的相关信号值

```
nginx -s signal
```

+ stop -  快速关闭服务
+ quit -  正常关闭服务
+ reload -  重新加载配置文件
+ reopen -  重新打开日志文件

然后可以看一下conf里的文件结构,配置文件可以包括服务器监听的端口和服务器名称区分的几个 server 块。当 nginx 决定哪个服务器处理请求后，它会根据服务器块内部定义的 location 指令的参数测试请求头中指定的 URI。

```
user  root;
worker_processes  1;

#error_log  logs/error.log;
#error_log  logs/error.log  notice;
#error_log  logs/error.log  info;

#pid        logs/nginx.pid;


events {
    worker_connections  1024;
}


http {
    include       mime.types;
    default_type  application/octet-stream;
    # 日志格式
    log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
                      '$status $body_bytes_sent "$http_referer" '
                      '"$http_user_agent" "$http_x_forwarded_for"';

    #access_log  logs/access.log  main;

    sendfile        on;
    #tcp_nopush     on;

    #keepalive_timeout  0;
    keepalive_timeout  65;

    #gzip  on; #压缩相关
	#gzip_min_length 50; 长度
	#gzip_comp_level 2; 级别
	#gzip_types text/plain; 要压缩的内容

    server {
        listen       80;
        server_name  localhost;

        #charset koi8-r;
		# 日志的存放处
        access_log  logs/host.access.log  main;

        location / {
            charset utf-8;
	    root   /home/space/; 此处可以使用alias
	    autoindex on; 打开目录
	    types{
	    	video/webm mkv;
	    }
        
	}
        #error_page  404              /404.html;

        # redirect server error pages to the static page /50x.html
        #
        error_page   500 502 503 504  /50x.html;
        location = /50x.html {
            root   html;
        }

        # proxy the PHP scripts to Apache listening on 127.0.0.1:80
        #
        #location ~ \.php$ {
        #    proxy_pass   http://127.0.0.1;
        #}

        # pass the PHP scripts to FastCGI server listening on 127.0.0.1:9000
        #
        #location ~ \.php$ {
        #    root           html;
        #    fastcgi_pass   127.0.0.1:9000;
        #    fastcgi_index  index.php;
        #    fastcgi_param  SCRIPT_FILENAME  /scripts$fastcgi_script_name;
        #    include        fastcgi_params;
        #}

        # deny access to .htaccess files, if Apache's document root
        # concurs with nginx's one
        #
        #location ~ /\.ht {
        #    deny  all;
        #}
    }


    # another virtual host using mix of IP-, name-, and port-based configuration
    #
    #server {
    #    listen       8000;
    #    listen       somename:8080;
    #    server_name  somename  alias  another.alias;

    #    location / {
    #        root   html;
    #        index  index.html index.htm;
    #    }
    #}


    # HTTPS server
    #
    #server {
    #    listen       443 ssl;
    #    server_name  localhost;

    #    ssl_certificate      cert.pem;
    #    ssl_certificate_key  cert.key;

    #    ssl_session_cache    shared:SSL:1m;
    #    ssl_session_timeout  5m;

    #    ssl_ciphers  HIGH:!aNULL:!MD5;
    #    ssl_prefer_server_ciphers  on;

    #    location / {
    #        root   html;
    #        index  index.html index.htm;
    #    }
    #}

}
```

这里注意需要让user和启动的用户一致才能访问到绝对路径的文件夹，然后我在location中写的

```
charset utf-8;# 支持中文
root   /home/space/;
autoindex on;
types{
	video/webm mkv;# chrome能在线播放mkv
}
```

另外location还可以用正则等做一个网址规则的匹配

### 平滑升级

可以拷贝旧文件，然后复制新文件到目录，之后执行

```
kill -USR2 ${原nginx pid}
```

就可以平滑升级

### 反向代理的搭建

