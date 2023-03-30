//参考链接:原文链接：https://blog.csdn.net/u010280075/article/details/88914424

//指针函数 ：本质是一个函数不过它的返回值是一个指针
//ret* func(args,..) func 一个函数 args 形参列表 ret* 一个整体是func函数的返回值 是一个指针的形式
#include <stdio.h>
#include <stdlib.h>
//函数指针
// 其实原因在于，一般的局部变量是存放于栈区的，当函数结束，
// 栈区的变量就会释放掉，如果我们在函数内部定义一个变量，
// 在使用一个指针去指向这个变量，当函数调用结束时，
// 这个变量的空间就已经被释放，这时就算返回了该地址的指针，也不一定会得到正确的值
int* func_sum(int n)
{
    if(n < 0)
    {
        printf("erro:must be > 0\n");
        exit(-1);//一会看一下


    }
    //需要使用静态变量  这个数据会保存到主程序结束
    static int sum = 0;
    int *p = &sum;
    for (int i = 0; i < n; i++)
    {
        sum +=i; 
    }
    return p;
    



}
int main()
{

    int num = 0;
    printf("please enter one number: ");
    scanf("%d",&num);
    int *p = func_sum(num);
    printf("sum: %d \n",*p);
    


    return 0;
}