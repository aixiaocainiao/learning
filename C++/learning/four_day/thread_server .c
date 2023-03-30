#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// bzero函数是c++ string.h中的函数。
// 功能描述：置字节字符串前n个字节为零且包括‘\0’。
// 原型：extern void bzero（void *s, int n）;
// 参数说明：s 要置零的数据的起始地址； n 要置零的数据字节个数。
// 用法：#include <string.h>
// 功能：置字节字符串s的前n个字节为零且包括‘\0’。
// 说明：bzero无返回值，并且使用string.h头文件，string.h曾经是posix标准的一部分，但是在POSIX.1-2001标准里面，
//            这些函数被标记为了遗留函数而不推荐使用。在POSIX.1-2008标准里已经没有这些函数了。推荐使用memset替代bzero。
//原文链接：https://blog.csdn.net/chenlei0630/article/details/41800423
#include <arpa/inet.h>
#include <pthread.h>
#define PORT 9999
void* working(void*);
//定义信息结构体
struct SockInfo
{
    struct sockaddr_in addr;
    int fd;
};
struct SockInfo infos[512];

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
    saddr.sin_port = htons(PORT);//将小端（h主机）转化为大端n（因为sockaddr_in需要的是大端数据）
    //对于0来说 大端和小端是没有区别的因此不需要转换 其他情况 需要转化为大端
    saddr.sin_addr.s_addr = INADDR_ANY;//宏定义 0.0.0.0 意思是绑定的是本地ip(例如192.168.20.11 看本地IP是多少)

    int ret = bind(fd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret == -1)
    {

        perror("bind");
        return -1;

    }
    //3.设置监听 最多128 
    ret = listen(fd,128);
    if(ret == -1)
    {

        perror("listen");
        return -1;

    }
    //初始化结构体数组
    int max = sizeof(infos)/sizeof(infos[0]);
    for(int i = 0;i < max;i++)
    {

        bzero(&infos[i],sizeof(infos[i]));//初始化数组和memset一样的 少了一个参数
        infos[i].fd = -1;//文件描述符

    }


    //4.阻塞并等待客户端的链接
   
    int addrlen = sizeof(struct sockaddr_in);
    while (1)
    {
        struct SockInfo* pinfo;
        for(int i = 0;i < max;i++)
        {
            if(infos[i].fd == -1)
            {

                pinfo = &infos[i];
                break;

            }

        }
        //cfd子线程需要使用
        int cfd = accept(fd,(struct sockaddr*)&pinfo->addr,&addrlen);
        pinfo->fd = cfd;
        if(cfd == -1)
        {
            perror("accept");
            //continue;
            break;
             
        }
        //创建子线程
        pthread_t tid;
        pthread_create(&tid,NULL,working,pinfo);
        //不要使用阻塞函数 pthread_join()进行回收
        pthread_detach(tid);
    }
    

    close(fd);
    return 0;

}
void* working(void* arg)
{
    struct SockInfo* pinfo = (struct SockInfo*)arg;
    //连接建立成功 打印客户端的IP和端口信息
    char ip[32];
    printf("客户端的IP: %s ,端口:%d \n",inet_ntop(AF_INET,&pinfo->addr.sin_addr,ip,sizeof(ip)),
                            ntohs(pinfo->addr.sin_port));

    //5通信
    while (1)
    {
        //接受数据
        char buff[1024];
        //recv函数
        //参数1 accept 的返回值 
        int len = recv(pinfo->fd,&buff,sizeof(buff),0);

        if(len > 0)
        {

            printf("client say: %s \n",buff);
            send(pinfo->fd,buff,len,0);

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
    close(pinfo->fd);
    pinfo->fd = -1;//
    return NULL;

}