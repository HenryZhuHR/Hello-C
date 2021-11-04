#include "stdio.h"

int  global_variable = 0;
void print_formal_parameter(int formal_parameter) { printf("  formal parameter: %p\n", &formal_parameter); }
int  main(int argc, char const* argv[])
{
    static int static_variable  = 1;
    int        local_varibale_a = 2;
    int        local_varibale_b = 3;
    printf("address:\n");
    printf("  global variable : %p\n", &global_variable);
    printf("  static variable : %p\n", &static_variable);
    printf("  local varibale a: %p\n", &local_varibale_a);
    printf("  local varibale b: %p\n", &local_varibale_b);

    print_formal_parameter(local_varibale_a);

    printf("  main func main(): %p", &main);
    return 0;
}
