// int  n = 0;
// void test(int a, int b) { printf("形式参数a的地址是：%d\n形式参数b的地址是：%d\n", &a, &b); }
// int  _tmain(int argc, _TCHAR* argv[])
// {
//     static int m = 0;
//     int        a = 0;
//     int        b = 0;
//     printf("自动变量a的地址是：%d\n自动变量b的地址是：%d\n", &a, &b);
//     printf("全局变量n的地址是：%d\n静态变量m的地址是：%d\n", &n, &m);
//     test(a, b);
//     printf("_tmain函数的地址是：%d", &_tmain);
//     getchar();
// }

#include "stdio.h"

int  global_variable = 0;
void print_formal_parameter(int formal_parameter) { printf("address of formal parameter: %p\n", &formal_parameter); }
int  main(int argc, char const* argv[])
{
    static int static_variable  = 1;
    int        local_varibale_a = 2;
    int        local_varibale_b = 3;

    printf("address of global variable : %p\n", &global_variable);
    printf("address of static variable : %p\n", &static_variable);
    printf("address of local varibale a: %p\n", &local_varibale_a);
    printf("address of local varibale b: %p\n", &local_varibale_b);

    print_formal_parameter(local_varibale_a);

    printf("address of main(): %p", &main);
    return 0;
}
