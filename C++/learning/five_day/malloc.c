#include <malloc.h>
#include <stdio.h>
int main()
{
    int i = 5;//分配了4个字节 静态分配
    int* p = (int*)malloc(sizeof(int));//指针变量P 为静态分配，malloc开辟的空间为动态分配
    *p = 5;//*p 代表的就是一个int 变量,指针变量p表示 的是一个int类型的地址为内容的变量
    free(p);//free(p)表示的把p所指向的内存给释放掉p本身的内存是静态的，不能由程序员手动释放
    //p本身的内存只能在P变量所在的函数运行终止时由系统自动释放



    return 0;
}