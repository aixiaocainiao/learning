#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 9999
int main()
{
    //1.创建监听的套接字 IPV4的tcp通信
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("socket");
        return -1;

    }
    //2.绑定本地的IP地址 一会自己看一下这个结构体
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);//将小端（主机）转化为大端（因为sockaddr_in需要的是大端数据）
    //对于0来说 大端和小端是没有区别的因此不需要转换 其他情况 需要转化为大端
    saddr.sin_addr.s_addr = INADDR_ANY;//宏定义 0.0.0.0 意思是绑定的是本地ip(例如192.168.20.11 看本地IP是多少)

    int ret = bind(fd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret == -1)
    {

        perror("bind");
        return -1;

    }
    //设置监听 最多128 
    ret = listen(fd,128);
    if(ret == -1)
    {

        perror("listen");
        return -1;

    }
    //4.阻塞并等待客户端的链接
    struct sockaddr_in caddr;//大端
    int addrlen = sizeof(caddr);
    int cfd = accept(fd,(struct sockaddr*)&caddr,&addrlen);
    if(cfd == -1)
    {
        perror("accept");
        return -1;


    }
    //连接建立成功 打印客户端的IP和端口信息
    char ip[32];
    printf("客户端的IP: %s ,端口:%d \n",inet_ntop(AF_INET,&caddr.sin_addr.s_addr,ip,sizeof(ip)),ntohs(caddr.sin_port));

    //5通信
    while (1)
    {
        //接受数据
        char buff[1024];
        //recv函数
        //参数1 accept 的返回值 
        int len = recv(cfd,&buff,sizeof(buff),0);

        if(len > 0)
        {

            printf("client say: %s \n",buff);
            send(cfd,buff,len,0);

        }
        else if(len == 0)
        {

            printf("客户端已经断开了链接......\n");
            break;

        }
        else
        {

            perror("recv");
            break;

        }

    }
    
    //关闭文件描述符
    close(cfd);
    close(fd);
    return 0;

}