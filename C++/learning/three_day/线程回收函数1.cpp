#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>


//子线程处理代码
struct Test
{
      int num;
      int age;
};
//第一种方式 
struct Test t;//全局 变量 
void* callback(void* arg)
{

      for(int i = 0;i < 5;i++)
      {

         printf("子线程: i = %d\n",i);


      }
      printf("子线程:%ld\n",pthread_self());

      //struct Test t; 局部变量 函数执行完毕 自动释放 

      
      t.num = 100;
      t.age = 6;

      
      pthread_exit(&t);
    
      //下面这行代码不会执行的 因为子进程退出了

      return NULL;

}

int main()
{
      

      
      pthread_t tid;
      
      pthread_create(&tid,NULL,callback,NULL);
      
      printf("主线程:%ld\n",pthread_self());

      // void pthread_exit(void *retval) 二级指针
      // 参数：线程退出的时候携带的数据，当前子线程的主线程会得到该数据。如果不需要使用，指定为 NULL

      void* ptr;
      pthread_join(tid,&ptr);
      //强制类型转换 因为void* 是任意的函数类型指针
      struct Test* pt = (struct Test*)ptr;
      printf("子线程的的num: %d ,age = %d \n",pt->num,pt->age);
      
      return 0;


}
