#include "libft.h"

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    size_t i = 0;
    unsigned char *dst1 = (unsigned char *) dst;
    unsigned char *src1 = (unsigned char *) src;
    while(i++ < n)
    {
        *dst1 = *src1;
        dst1++;
        src1++;
    }
    return(dst);   
}