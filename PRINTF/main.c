#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
    int i;
    unsigned int i2;
    char *str;

    str = "wqerty";
    i2 = 5;
    i2 = 4294967295 + 1 + i2;
    i = -2147483648;
    i2 = (unsigned int)i;
    i2 *= -1;
    // printf("%d%%%u % s%c%x\n", i, 123456123, "qwerty", 'c', );
    // printf("%1sqwe%crt%uysda\n", "AAA", 'J', 12345);
    // ft_printf("%sqwe%crt%uysda\n", "AAA", 'J', 12346);
    // i = printf("%12");
    // printf("res real = !%d!\n", i);
    // printf("%12");
    // ft_printf("%12");
    // printf("res ft = !%d!\n", i);
    printf("%020d\n",i);
    ft_printf("%020d\n",i);;
    // ft_printf("%p\n", str);
    // i = ft_printf("%015dqwe\n", i2);
    // printf("!%d!\n", i);
    // i = printf("%015dqwe\n", i2);
    // printf("!%d!\n", i);
    // i = (unsigned int)(4294967295 + 1 + i);
    // printf("%d", i);
}
