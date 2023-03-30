#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<netdb.h>
#include<unistd.h>
#include<stdarg.h>
#include<string.h>

#define SERVER_PORT 8000
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main()
{
//服务端地址
struct sockaddr_in server_addr;
bzero(&server_addr,sizeof(server_addr));
server_addr.sin_family=AF_INET;
server_addr.sin_addr.s_addr=inet_addr("192.168.32.175");//
server_addr.sin_port=htons(SERVER_PORT);

//创建socket
int client_socket_fd=socket(AF_INET,SOCK_DGRAM,0);
if(client_socket_fd<0)
{
perror("create socket failed！");
exit(1);
}

//输入文件名到缓冲区
char file_name[FILE_NAME_MAX_SIZE+1];
bzero(file_name,FILE_NAME_MAX_SIZE+1);
printf("please input file name on server:\t");
scanf("%s",file_name);

char buffer[BUFFER_SIZE];
bzero(buffer,BUFFER_SIZE);
strncpy(buffer,file_name,strlen(file_name)>BUFFER_SIZE?BUFFER_SIZE:strlen(file_name));

//发送文件名
//int sendto(int sockfd,const void *mesg,int len,unsigned int flags,const struct sockaddr *to,int tolen)
if(sendto(client_socket_fd,buffer,BUFFER_SIZE,0,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)
{
perror("send file name failed！");
exit(1);
}

close(client_socket_fd);
return 0;

}
