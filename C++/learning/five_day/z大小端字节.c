// 如何判断大端、小端（字节序）呢？
// 思路：
// int a = 1;
// 将a的第一个字节内容拿出来，判断其是1还是0，1为小端，0为大端。
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    //写一个代码，判断当前机器采用大端还是小端

    int a = 1;
    /*
        思路:
            ox 00 00 00 01 ---16紧致显示
            低     高   小端
            01 00 00 00 
            高     低   大端
            00 00 00 01 
    */
    char* p = (char*)a;
    if(*p == 1)
    {
        printf("小端字节序\n");

    }
    else{
        printf("大端字节序\n");
    }

    return 0;
}
