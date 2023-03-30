#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>//里面包含了套接字的头文件
#define PORT 9999
int main()
{
    //1.创建通信的套接字 IPV4的tcp通信
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("socket");
        return -1;

    }
    //2.链接服务器 IP port
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);
    inet_pton(AF_INET,"192.168.124.71",&saddr.sin_addr.s_addr);
    int ret = connect(fd,(struct sockaddr*)&saddr,sizeof(saddr));
   
   
    if(ret == -1)
    {

        perror("connect");
        return -1;

    }
  
    int number = 0;
    //3 、通信
    while (1)
    {
        //发送数据
        char buff[1024];
        sprintf(buff,"你好,hello,world,%d..\n",number++);
        send(fd,buff,strlen(buff)+1,0);

        //接受数据
        memset(buff,0,sizeof(buff));//清空散户局
        int len = recv(fd,buff,sizeof(buff),0);
        if(len > 0)
        {

            printf("server say: %s \n",buff);
            

        }
        else if(len == 0)
        {

            printf("服务端已经断开了链接......\n");
            break;

        }
        else
        {

            perror("recv");
            break;

        }
        sleep(1);//秒

    }
    
    //关闭文件描述符
    close(fd);
    return 0;

}