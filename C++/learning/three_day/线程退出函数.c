#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void* callback(void* arg)
{

      for(int i = 0;i < 5;i++)
      {

         printf("子线程: i = %d\n",i);


      }
      printf("子线程:%ld\n",pthread_self());
      return NULL;

}

int main()
{
   
   
   pthread_t tid;
   pthread_create(&tid,NULL,callback,NULL);
   printf("主线程:%ld\n",pthread_self());

   //线程退出函数 不耽误子进程的继续执行
   pthread_exit(NULL);
   //
   //sleep(3);
   return 0;


}
