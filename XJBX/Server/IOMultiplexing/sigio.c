//proactor可以通过信号量实现
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int socketfd;

//没有可读可写的状态,这里是异步的操作
//但这种方法不能大量的用
void do_sigio(int sig){
    char buffer[256] = {0};
    struct sockaddr_in cli_addr;
    int client  = sizeof(struct sockaddr_in);
    //buffer放到全局保存起来
    int len = recvfrom(socketfd,buffer,256,0,(struct sockaddr *)&cli_addr,(socklen_t*)&client);
    int slen = sendto(socketfd,buffer,len,0,(struct sockaddr*)&cli_addr, client);
}


int main(){
    
    //
    struct sigaction sigio_action;//ctrl + c -> kill -7
    sigio_action.sa_flags = 0;  
    sigio_action.sa_handler = do_sigio;
    //针对一个回调函数
    sigaction(SIGIO,&sigio_action,NULL);
    
    //拿到sockfd
    socketfd = socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6016);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    bind(socketfd,(struct sockaddr_in*)&serv_addr,sizeof(serv_addr));

    fcntl(socketfd,F_SETOWN,getpid());

    int flags = fcntl(socketfd,F_GETFL,0);
    flags |= O_ASYNC | O_NONBLOCK;

    fcntl(socketfd,F_SETFL,flags);

    while(1) sleep(1);

    close(socketfd);

    return 0;
}
