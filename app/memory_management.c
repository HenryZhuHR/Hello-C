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
