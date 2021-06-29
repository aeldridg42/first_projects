#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
    int i;
    char *str;
    str = "%%%";
    // printf("%d%%%u % s%c%x\n", i, 123456123, "qwerty", 'c', );
    printf("%1sqwe%crt%uysda\n", "AAA", 'J', 12345);
    ft_printf("%sqwe%crt%uysda\n", "AAA", 'J', 12346);
    i = printf("%c\n", 'e');
    printf("!%d!\n", i);
    i = ft_printf("%c\n", 'e');
    printf("!ft%d!\n", i);
}