//参考链接:原文链接：https://blog.csdn.net/u010280075/article/details/88914424

//函数指针的另一个应用
// 什么是回调函数？
// 回调函数就是一个通过指针函数调用的函数。其将函数指针作为一个参数，传递给另一个函数。
// 回调函数并不是由实现方直接调用，而是在特定的事件或条件发生时由另外一方来调用的。
// 同样我们来看一个回调函数的例子：
#include <stdio.h>
#include <stdlib.h>
//求和函数
int func_sum(int n)
{
    int sum = 0;
    if(n < 0)
    {
        printf("n 必须是大于0的数 \n");
        exit(-1);

    }
    for (int i = 0; i < n; i++)
    {
        sum += i;
    }
    return sum;

}
//这个函数是回调函数，其中第二个参数为一个函数指针，通过该函数指针来调用求和函数，并把结果返回给主调函数
int callback(int n,int (*p)(int))
{

    return p(n);

}
int main(int argc, char *argv[])
{
    int n = 0;
    printf("请输入一个数字: ");
    scanf("%d",&n);
    printf("从0 到 %d is %d",n,callback(n,func_sum));//此处直接调用回调函数，而不是直接调用func_sum函数 
    return 0;
}
