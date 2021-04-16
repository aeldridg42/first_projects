#include "libft.h"
#include <stdio.h>

void *ft_memset (void *destination, int c, size_t n)
{
    unsigned char *k = (unsigned char *) destination;
    int i = 0, n1 = (int) n;
    while(i < n1)
        k[i++] = c;
    return(destination);
}