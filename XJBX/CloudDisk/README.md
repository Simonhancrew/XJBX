### 一个基于fastdfs + nginx + fastcgi + redis + mysql的云盘
fastdfs作为文件储存系统，nginx反向代理相关请求到端口，通过fastcgi的后台进程持续处理。
mysql维护用户信息，redis维护登录的token减小存储的压力