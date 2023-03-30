#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

#define MAX 50
// 全局变量
int number;

//定义读写锁
pthread_rwlock_t rwlock;
// 线程处理函数
void* readNum(void* arg)
{
    for(int i=0; i<MAX; ++i)
    {
        pthread_rwlock_rdlock(&rwlock);
        
        printf("Thread A, id = %lu, number = %d\n", pthread_self(), number);
        pthread_rwlock_unlock(&rwlock);
        usleep(rand()%5);
    }

    return NULL;
}

void* writeNum(void* arg)
{
    for(int i=0; i<MAX; ++i)
    {
        pthread_rwlock_wrlock(&rwlock);

        int cur = number;
        cur++;
        number = cur;
        printf("Thread B, id = %lu, number = %d\n", pthread_self(), number);
        pthread_rwlock_unlock(&rwlock);

        usleep(5);
    }

    return NULL;
}

int main(int argc, const char* argv[])
{
    pthread_t p1[5], p2[3];
    pthread_rwlock_init(&rwlock,NULL);

    // 创建
    for(int i = 0;i < 5;i++)
    {

            pthread_create(&p1[i], NULL,readNum, NULL);

    }
    for(int i = 0;i < 3;i++)
    {
        pthread_create(&p2[i], NULL, writeNum, NULL);

    }
   
    for(int i = 0;i < 5;i++)
    {

        pthread_join(p1[i], NULL);

    }
    for(int i = 0;i < 3;i++)
    {

        pthread_join(p2[i], NULL);

    }
    // 阻塞，资源回收
    
    
    return 0;
}


