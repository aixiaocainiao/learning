#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
//线程id 线程函数得到线程id
pthread_t pthread_self();
/*
线程创建函数:
      int pthread_create(pthread_t *thread,const pthread_attr_t *attr,
                        void *(*start_routinue)(void *) ,void*arg);
      thread: 传出参数，是无符号长整形数，线程创建成功，会将线程 ID 写入到这个指针指向的内存中
      attr: 线程的属性，一般情况下使用默认属性即可，写 NULL
      start_routine: 函数指针，创建出的子线程的处理动作，也就是该函数在子线程中执行。
      arg: 作为实参传递到 start_routine 指针指向的函数内部

      返回值：线程创建成功返回 0，创建失败返回对应的错误号
      注意：
            # pthread_create 函数的定义在某一个库中, 编译的时候需要加库名 pthread
            $ gcc pthread_create.c -lpthread
线程退出函数
      void pthread_exit(void *retval)
      参数：线程退出的时候携带的数据，当前子线程的主线程会得到该数据。如果不需要使用，指定为 NULL


*/

//子线程处理代码
struct Test
{
      int num;
      int age;
};
//第一种方式 
//struct Test t;//全局 变量 
void* callback(void* arg)
{

      for(int i = 0;i < 5;i++)
      {

         printf("子线程: i = %d\n",i);


      }
      printf("子线程:%ld\n",pthread_self());

      //struct Test t; 局部变量 函数执行完毕 自动释放 

      //第二种
      struct Test* t = (struct Test*)arg;
      t->num = 100;
      t->age = 6;

      //也要改变 此处不应该取地址 参数应该为t 而不是&t
      //pthread_exit(&t);
      
      //第二种
      pthread_exit(t);

      //下面这行代码不会执行的 因为子进程退出了

      return NULL;

}

int main()
{
      //第二种

      struct Test t;
      pthread_t tid;
      //第二种
      //pthread_create(&tid,NULL,callback,NULL);
      pthread_create(&tid,NULL,callback,&t);
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
