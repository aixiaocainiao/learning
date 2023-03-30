#include <stdio.h>
#include <malloc.h>
//void* malloc (size_t size)
//但是，对于malloc开辟空间失败，则会返回一个空指针（NULL）！
void f(void *arg)
{
    int* q = (int*)arg;
    *q = 200;//这里内存已经发生改变 如果下面释放掉 就会出现问题
    //free(q); 执行了第二个printf("%d \n",*p); 为0


}
int main()
{
    int* p = (int*)malloc(sizeof(int));
    *p = 10;
    
    printf("%d \n",*p);
    f(p);
    printf("%d \n",*p);


    return 0;
}