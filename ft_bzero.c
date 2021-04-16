#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    unsigned char *p = (unsigned char *) s;
    int l = 0, r = (int) n;
    while(l < r)
        p[l++] = '\0'; 
}