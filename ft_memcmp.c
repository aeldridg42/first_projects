#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *ptr1 = (unsigned char *) s1;
    unsigned char *ptr2 = (unsigned char *) s2;
    size_t i = 0;
    while(i++ < n)
    {
        if(*ptr1 != *ptr2)
            return(*ptr1 - *ptr2);
        ptr1++;
        ptr2++;
    }
    return(0);
}