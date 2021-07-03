#include "libftprintf.h"
#include <stdio.h>
#include "libft/libft.h"

int main()
{
    int i = 0;
    char arr[] = "%c,qwerty";
    counter("%sqwe%crt%uysda%p\n", "AAA", 'J', 12345, -2);
    printf("%p", arr);
    return (0);
}