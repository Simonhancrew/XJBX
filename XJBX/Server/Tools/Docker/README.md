## Docker

Docker的出现提升了软件开发的效率。和虚拟机相比，少了一层guest os，docker可以直接使用硬件资源。当然隔离性就不会有虚拟机那么好了。

### 基本构成

主要分成三个部分

1. 镜像：就相当于是⼀个root ⽂件系统。⽐如官⽅镜像 ubuntu:16.04 就包含了完整的⼀套Ubuntu16.04 最⼩系统的root ⽂件系统。
2. 容器：镜像（Image）和容器（Container）的关系，就像是⾯向对象程序设计中的类 和实例⼀样，镜像是静态的定义，容器是镜像运⾏时的实体。容器可以被创建、启动、停⽌、删除、暂 停等。
3. 仓库：仓库可看成⼀个代码控制中⼼，⽤来保存镜像。

### 安装

首先卸载旧版本的docker,我实在16.04上操作的

```
sudo apt-get remove docker docker-engine docker.io containerd runc
```

Ubuntu 16.04 + 上的Docker CE 默认使⽤ `overlay2 `存储层驱动,⽆需⼿动配置。

首先做一点预备工作

```
sudo apt-get update

han@ubuntu:~$ sudo apt-get install \
>      apt-transport-https \
>      ca-certificates \
>      curl \
>      software-properties-common
```

为了确认下载包的合法性，添加软件园GPG密钥，替换成为国内源

```
han@ubuntu:~$ curl -fsSL https://mirrors.ustc.edu.cn/docker-ce/linux/ubuntu/gpg | sudo apt-key add -
OK
```

向 source.list 中添加Docker 软件源

```
sudo add-apt-repository \
     "deb [arch=amd64] https://mirrors.ustc.edu.cn/docker-ce/linux/ubuntu \
     $(lsb_release -cs) \
     stable"
```

以上命令会添加稳定版本的Docker CE APT 镜像源。之后开始安装

```
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io
```

成功之后看看docker

```
han@ubuntu:~$ docker -v
Docker version 20.10.7, build f0df350
```

想要卸载的话

```
sudo apt-get purge docker-ce docker-ce-cli containerd.io
sudo rm -rf /var/lib/docker # 删除残留
```

最后附加启动docker

```
sudo systemctl enable docker # 开机启动
sudo systemctl start docker # 启动docker
```

### 启用

默认情况下，docker 命令会使⽤Unix socket 与Docker 引擎通讯。⽽只有 root ⽤户和 docker 组的⽤户才可以访问Docker 引擎的Unix socket。出于安全考虑，⼀般Linux 系统上不会直接使⽤ root ⽤户。因此，更好地做法是将需要使⽤ docker 的⽤户加⼊ docker ⽤户组。但其实ubuntu下都帮你做了。

```
sudo groupadd docker # 建立docker组
sudo usermod -aG docker $USER # 将当前用户加入docker组
```

之后推出重新登一下shell，测试一下,失败一次的话可能是网络原因，重试几次。

```
han@ubuntu:~$ docker run hello-world
Unable to find image 'hello-world:latest' locally
latest: Pulling from library/hello-world
b8dfde127a29: Pull complete 
Digest: sha256:df5f5184104426b65967e016ff2ac0bfcd44ad7899ca3bbcf8e44e4461491a9e
Status: Downloaded newer image for hello-world:latest

Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
    (amd64)
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://hub.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/get-started/
```

### 操作docker镜像

[docker hub](https://hub.docker.com/explore/)上有很多高质量的镜像，获取：

```
docker pull [选项] [Docker Registry 地址[:端⼝号]/]仓库名[:标签]
```

具体操作看

```
han@ubuntu:~$ docker pull --help 

Usage:  docker pull [OPTIONS] NAME[:TAG|@DIGEST]

Pull an image or a repository from a registry

Options:
  -a, --all-tags                Download all tagged images in the repository
      --disable-content-trust   Skip image verification (default true)
      --platform string         Set platform if server is multi-platform capable
  -q, --quiet                   Suppress verbose output
```

比如,默认地址就是前面提到的hub

```
han@ubuntu:~$ docker pull redis:6.0.8
6.0.8: Pulling from library/redis
bb79b6b2107f: Pull complete 
1ed3521a5dcb: Pull complete 
5999b99cee8f: Pull complete 
3f806f5245c9: Pull complete 
f8a4497572b2: Pull complete 
eafe3b6b8d06: Pull complete 
Digest: sha256:21db12e5ab3cc343e9376d655e8eabbdbe5516801373e95a8a9e66010c5b8819
Status: Downloaded newer image for redis:6.0.8
docker.io/library/redis:6.0.8
```

### 运行docker镜像

在前面一个基础上，启动里面的bash并交互操作的话

```
han@ubuntu:~$ docker run -it --rm redis:6.0.8 bash
root@3bae0ce122a3:/data#
```

+ -it：这是两个参数，⼀个是 -i：交互式操作，⼀个是 -t 终端。我们这⾥打算进⼊ bash 执⾏ ⼀些命令并查看返回结果，因此我们需要交互式终端。
+ --rm：这个参数是说容器退出后随之将其删除。默认情况下，为了排障需求，退出的容器并不会⽴即 删除，除⾮⼿动 docker rm。我们这⾥只是随便执⾏个命令，看看结果，不需要排障和保留结果， 因此使⽤ --rm 可以避免浪费空间。
+ bash：放在镜像名后的是命令，这⾥我们希望有个交互式Shell，因此⽤的是 bash。

```
root@3bae0ce122a3:/data# redis-server 
9:C 19 Jul 2021 02:27:14.677 # oO0OoO0OoO0Oo Redis is starting oO0OoO0OoO0Oo
9:C 19 Jul 2021 02:27:14.677 # Redis version=6.0.8, bits=64, commit=00000000, modified=0, pid=9, just started
9:C 19 Jul 2021 02:27:14.677 # Warning: no config file specified, using the default config. In order to specify a config file use redis-server /path/to/redis.conf
                _._                                                  
           _.-``__ ''-._                                             
      _.-``    `.  `_.  ''-._           Redis 6.0.8 (00000000/0) 64 bit
  .-`` .-```.  ```\/    _.,_ ''-._                                   
 (    '      ,       .-`  | `,    )     Running in standalone mode
 |`-._`-...-` __...-.``-._|'` _.-'|     Port: 6379
 |    `-._   `._    /     _.-'    |     PID: 9
  `-._    `-._  `-./  _.-'    _.-'                                   
 |`-._`-._    `-.__.-'    _.-'_.-'|                                  
 |    `-._`-._        _.-'_.-'    |           http://redis.io        
  `-._    `-._`-.__.-'_.-'    _.-'                                   
 |`-._`-._    `-.__.-'    _.-'_.-'|                                  
 |    `-._`-._        _.-'_.-'    |                                  
  `-._    `-._`-.__.-'_.-'    _.-'                                   
      `-._    `-.__.-'    _.-'                                       
          `-._        _.-'                                           
              `-.__.-'                                               

9:M 19 Jul 2021 02:27:14.678 # WARNING: The TCP backlog setting of 511 cannot be enforced because /proc/sys/net/core/somaxconn is set to the lower value of 128.
9:M 19 Jul 2021 02:27:14.678 # Server initialized
9:M 19 Jul 2021 02:27:14.678 # WARNING overcommit_memory is set to 0! Background save may fail under low memory condition. To fix this issue add 'vm.overcommit_memory = 1' to /etc/sysctl.conf and then reboot or run the command 'sysctl vm.overcommit_memory=1' for this to take effect.
9:M 19 Jul 2021 02:27:14.678 * Ready to accept connections
^C9:signal-handler (1626661635) Received SIGINT scheduling shutdown...
9:M 19 Jul 2021 02:27:15.889 # User requested shutdown...
9:M 19 Jul 2021 02:27:15.889 * Saving the final RDB snapshot before exiting.
9:M 19 Jul 2021 02:27:15.891 * DB saved on disk
9:M 19 Jul 2021 02:27:15.891 # Redis is now ready to exit, bye bye...
root@3bae0ce122a3:/data# exit
exit
```

exit就可以退出环境

### 查看本地已有镜像

```
han@ubuntu:~$ docker image ls
REPOSITORY    TAG       IMAGE ID       CREATED        SIZE
hello-world   latest    d1165f221234   4 months ago   13.3kB
redis         6.0.8     16ecd2772934   8 months ago   104MB
```

### 删除本地镜像

```
docker image rm [选项] <镜像1> [<镜像2> ...]
```

这里不知道为啥删不掉,只能force了

```
han@ubuntu:~$ docker image rm hello-world:latest 
Error response from daemon: conflict: unable to remove repository reference "hello-world:latest" (must force) - container 500497c6f50b is using its referenced image d1165f221234
han@ubuntu:~$ docker container ls
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES
han@ubuntu:~$ docker image rm hello-world:latest  -f
Untagged: hello-world:latest
Untagged: hello-world@sha256:df5f5184104426b65967e016ff2ac0bfcd44ad7899ca3bbcf8e44e4461491a9e
Deleted: sha256:d1165f2212346b2bab48cb01c1e39ee8ad1be46b87873d9ca7a4e434980a7726
```

关于untagged和delete，镜像的唯⼀标识是其ID 和摘要，⽽⼀个镜像可以有多个标签，令删除镜像的时候，实际上是在要求删除某个标签的镜像

### 具体操作一把

先pull到nginx

```
han@ubuntu:~$ docker pull nginx:latest
latest: Pulling from library/nginx
b4d181a07f80: Pull complete 
66b1c490df3f: Pull complete 
d0f91ae9b44c: Pull complete 
baf987068537: Pull complete 
6bbc76cbebeb: Pull complete 
32b766478bc2: Pull complete 
Digest: sha256:353c20f74d9b6aee359f30e8e4f69c3d7eaea2f610681c4a95849a2fd7c497f9
Status: Downloaded newer image for nginx:latest
docker.io/library/nginx:latest

```

启动

```
han@ubuntu:~$ docker pull nginx:latest
latest: Pulling from library/nginx
b4d181a07f80: Pull complete 
66b1c490df3f: Pull complete 
d0f91ae9b44c: Pull complete 
baf987068537: Pull complete 
6bbc76cbebeb: Pull complete 
32b766478bc2: Pull complete 
Digest: sha256:353c20f74d9b6aee359f30e8e4f69c3d7eaea2f610681c4a95849a2fd7c497f9
Status: Downloaded newer image for nginx:latest
docker.io/library/nginx:latest
```

查看所有容器

```
han@ubuntu:~$ docker ps -a
CONTAINER ID   IMAGE          COMMAND                  CREATED         STATUS                   PORTS                                   NAMES
c65a7db873f5   nginx          "/docker-entrypoint.…"   5 minutes ago   Up 34 seconds            0.0.0.0:8080->80/tcp, :::8080->80/tcp   nginx
500497c6f50b   d1165f221234   "/hello"                 4 hours ago     Exited (0) 4 hours ago                                           zen_cerf
```

停止,重启，进入容器

```
docker stop $container
docker restart 
#docker attach
```

容器不退出，返回宿主机 ctrl + p + q

如果要导出某个容器,在外部

```
docker export df9c17f558df > ubuntu.tar
```

另外还有exec命令

```
docker exec -it 243c32535da7 /bin/bash
```

之后可以导出容器,docker export

```
han@ubuntu:~$ docker exec -it c65a7db873f5  bash
root@c65a7db873f5:/# exit
exit
han@ubuntu:~$ docker export c65a7db873f5  > nginx.tar
han@ubuntu:~$ ls
clash  cloudDisk  examples.desktop  fastdfs  nginx.tar  project  share  software  study.sql  XJBX  公共的  模板  视频  图片  文档  下载  音乐  桌面
```

导入容器就是

```
cat nginx.tar | docker import - XXXXX
```

最后不用的容器，stop之后删除

```
han@ubuntu:~$ docker stop c65a7db873f5
c65a7db873f5
han@ubuntu:~$ docker rm c65a7db873f5
c65a7db873f5
```

### 利用commit理解镜像构成

docker commit 命令除了学习之外，还有⼀些特殊的应⽤场合，⽐如被⼊侵后保存现场等。但 是，不要使⽤ docker commit 定制镜像，定制镜像应该使⽤ Dockerfile 来完成。

这个有点类似git，一层层的commit。

### 使用dockerfile定制镜像

镜像的定制实际上就是定制每⼀层所添加的配置、文件。Dockerfile 是⼀个⽂本⽂件，其内包含了⼀条条的指令(Instruction)，每⼀条指令构建⼀层，因此每⼀条 指令的内容，就是描述该层应当如何构建。

制作一个nginx镜像为例

```
mkdir mynginx
cd mynginx
touch Dockerfile
```

之后在Dockerfile中

```
From nginx
Run echo '<h1>Hello  docker</h1>' > /usr/share/nginx/html/idex.html
```

之后在当前目录下执行编译

```
han@ubuntu:~/nginx$ docker build -t mynginx .
Sending build context to Docker daemon  2.048kB
Step 1/2 : From nginx
latest: Pulling from library/nginx
b4d181a07f80: Pull complete 
66b1c490df3f: Pull complete 
d0f91ae9b44c: Pull complete 
baf987068537: Pull complete 
6bbc76cbebeb: Pull complete 
32b766478bc2: Pull complete 
Digest: sha256:353c20f74d9b6aee359f30e8e4f69c3d7eaea2f610681c4a95849a2fd7c497f9
Status: Downloaded newer image for nginx:latest
 ---> 4cdc5dd7eaad
Step 2/2 : Run echo '<h1>Hello  docker</h1>' > /usr/share/nginx/html/idex.html
 ---> Running in 9d567d3224e8
Removing intermediate container 9d567d3224e8
 ---> a19401ff2eef
Successfully built a19401ff2eef
Successfully tagged mynginx:latest
```

看一下新的镜像

```
han@ubuntu:~/nginx$ docker image ls 
REPOSITORY   TAG       IMAGE ID       CREATED          SIZE
mynginx      latest    a19401ff2eef   42 seconds ago   133MB
nginx        latest    4cdc5dd7eaad   12 days ago      133MB
redis        6.0.8     16ecd2772934   8 months ago     104MB
```

定制镜像，一定是以一个镜像为基础的， FROM 就是指定基础镜像，因此⼀个 Dockerfile 中 FROM 是必备的指令，并且必须是第⼀条指令。

如果没有找到对应服务的镜像，官⽅镜像中还提供了⼀些更为基础的操作系统镜像，如 ubuntu、 debian、centos、fedora、alpine 等，这些操作系统的软件库为我们提供了更⼴阔的扩展空 间。

RUN 指令是⽤来执⾏命令⾏命令的。每一个run都是一个commit，需要注意的是可以多条合并的。

```
FROM debian:jessie

 RUN buildDeps='gcc libc6-dev make' \
     && apt-get update \
     && apt-get install -y $buildDeps \
     && wget -O redis.tar.gz "http://download.redis.io/releases/re dis-3.2.5.tar.gz" \
     && mkdir -p /usr/src/redis \
     && tar -xzf redis.tar.gz -C /usr/src/redis --strip-components =1 \
     && make -C /usr/src/redis \
     && make -C /usr/src/redis install \
     && rm -rf /var/lib/apt/lists/* \
     && rm redis.tar.gz \
     && rm -r /usr/src/redis \
     && apt-get purge -y --auto-remove $buildDeps
```

命令的最后添加了清理⼯作的命令，删除了为了编译构建所需要的软件，清理了 所有下载、展开的⽂件，并且还清理了 apt 缓存⽂件。这是很重要的⼀步，我们之前说过，镜像是多层 存储，每⼀层的东⻄并不会在下⼀层被删除，会⼀直跟随着镜像。因此镜像构建时，⼀定要确保每⼀层只 添加真正需要添加的东⻄，任何⽆关的东⻄都应该清理掉。

这里参数很多，用到的时候再查文档吧
