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
//创建UDP套接字
struct sockaddr_in server_addr;
bzero(&server_addr,sizeof(server_addr));         //初始化结构占用内存
server_addr.sin_family=AF_INET;                  //设置地址传输层类型
server_addr.sin_addr.s_addr=htonl(INADDR_ANY);   //设置服务器地址
server_addr.sin_port=htons(SERVER_PORT);         //设置监听端口

//创建socket，设置服务器地址结构
int server_socket_fd=socket(AF_INET,SOCK_DGRAM,0);   //SOCK_DGRAM：数据报套接字
if(server_socket_fd==-1)
{
perror("create socket failed！");
exit(1);
}

//绑定套接口，     //bind()函数： int bind(int sockfd,struct sockaddr *my_addr,int addrlen)
if((bind(server_socket_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)))==-1)
{
perror("server bind failed");
exit(1);
}

//数据传输
while(1)
{
//定义一个地址，由于捕获客户端地址
struct sockaddr_in client_addr;
socklen_t client_addr_length=sizeof(client_addr);

//接收数据
char buffer[BUFFER_SIZE];
bzero(buffer,BUFFER_SIZE);   
//int recvfrom(int sockfd,void *buf,int len,unsigned flags,struct sockaddr *from,int *fromlen)
if(recvfrom(server_socket_fd,buffer,BUFFER_SIZE,0,(struct sockaddr*)&client_addr,&client_addr_length)==-1)
{
perror("receive data failed");
exit(1);
}

//从buffer中拷贝出file_name
char file_name[FILE_NAME_MAX_SIZE+1];
bzero(file_name,FILE_NAME_MAX_SIZE+1);
strncpy(file_name,buffer,strlen(buffer)>FILE_NAME_MAX_SIZE?FILE_NAME_MAX_SIZE:strlen(buffer));
printf("%s\n",file_name);

}

close(server_socket_fd);
return 0;

}
