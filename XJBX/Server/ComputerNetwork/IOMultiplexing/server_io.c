#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/tcp.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define BUFFER_LENGTH 1024
#define EPOLL_SIZE 1024
//select的实现,大于一定数量的时候会急剧下降,为什么很多人把这个数值定在1024左右？
//一个经验值，其实和很多方面相关,select检测所有的fd，所以效率是比较低的

int main(){
    //server的信息
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0) return -1;

    int port = 6016;

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6016);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    //bind失败，端口被占用了
    if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr_in)) < 0){
        perror("bind");
        return 2;
    }

    if(listen(sockfd,5) < 0){
        perror("listen");
        return -3;
    }
#if 0
    //select的写法
    fd_set rfds,rset;
    //bit 0
    FD_ZERO(&rfds);
    //bit 3置1
    FD_SET(sockfd,&rfds);
    //用于做循环
    int maxfd = sockfd + 1;
    //不断检测io是否有数据
    while(1){
        //用同一个好像会乱啊？
        rset = rfds;
        //maxfd = 
        //            可读 可写  出错 多长时间询问一次(时间戳)
        int nready = select(maxfd,&rset,NULL,NULL,NULL);//有io的
        if(nready < 0) continue;
        //当前fd是否设置到了关注的集合中
        if(FD_ISSET(sockfd,&rset)){//connect
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
            int clientfd = accept(sockfd,(struct sockaddr*)&client_addr,client_len);
            if(clientfd <= 0) continue;

            FD_SET(clientfd,&rfds);
            if(clientfd > maxfd) maxfd = clientfd;
            printf("sockfd:%d,max_fd:%d,client_fd:%d\n",sockfd,maxfd,clientfd);
            if(--nready == 0) continue;
        }
        int i = 0;
        //close会处理循环的使用问题
        for(int i = sockfd + 1;i <= maxfd;i++){
            if(FD_ISSET(i,&rset)){
                char buffer[BUFFER_LENGTH] = {0};
                int ret = recv(i,buffer,BUFFER_LENGTH,0);
                if(ret < 0){//多线程被其余的读完了（惊群）
                    if(errno == EAGAIN || errno == EWOULDBLOCK){
                        printf("read all data");
                    }
                    FD_CLR(i,&rfds);
                    close(i);
                }else if(ret == 0){
                    printf("disconnect:%d",i);
                    FD_CLR(i,&rfds);
                    close(i);
                }else{
                    printf("recv:%s,%d bytes",buffer,ret);

                }
                if(--nready == 0){
                    break;
                }
            }
        }
    }
#else
    //红黑树+链表，没有epoll，linux服务器根本不可能作为首选的server os
    //select数量少的时候性能足够使用，但是数量大的时候epoll一定是被考虑的
    //epoll_creat()，红黑树初始
    //epoll_ctl()
    //epoll_wait()
    
    //creat的参数只有大于0和小于0的区别
    int epfd = epoll_create(1);//即在红黑树又在队列里
    struct epoll_event ev,events[EPOLL_SIZE] = {0};

    ev.events = EPOLLIN;
    ev.data.fd = sockfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev);//还传一个sockfd是把这个当key用

    while(1){
        int nready = epoll_wait(epfd,events,EPOLL_SIZE,-1);
        if(nready == -1) continue;
        int i = 0;
        for(int i = 0;i < nready;++i){
            if(events[i].data.fd == sockfd){
                struct sockaddr_in client_addr;
                socklen_t client_len = sizeof(client_addr);
                int clientfd = accept(sockfd,(struct sockaddr*)&client_addr,&client_len);
                if(clientfd <= 0) continue;

                char str[INET_ADDRSTRLEN] = {0};
				printf("recvived from %s at port %d, sockfd:%d, clientfd:%d\n", inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
					ntohs(client_addr.sin_port), sockfd, clientfd);
                //et从无到有触发一次，大块数据用lt
                ev.events = EPOLLIN | EPOLLET;

                ev.data.fd = clientfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,clientfd,&ev);
            }else{
                int clientfd = events[i].data.fd;
                char buffer[BUFFER_LENGTH] = {0};
                int ret = recv(clientfd,buffer,BUFFER_LENGTH,0);
                if(ret < 0){
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
						printf("read all data");
					}
					
					close(clientfd);
					
					ev.events = EPOLLIN | EPOLLET;
					ev.data.fd = clientfd;
                    epoll_ctl(epfd, EPOLL_CTL_DEL, clientfd, &ev);
                }else if(ret == 0){
                    printf(" disconnect %d\n", clientfd);
					
					close(clientfd);

					ev.events = EPOLLIN | EPOLLET;
					ev.data.fd = clientfd;
					epoll_ctl(epfd, EPOLL_CTL_DEL, clientfd, &ev);
                    break;
                }else{
                    printf("Recv: %s, %d Bytes\n", buffer, ret);
                }
            }
        }
    }


#endif
    return 0;
}