#include "libft.h"

size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t i = ft_strlen(dst) + ft_strlen(src), k;
    if(ft_strlen(dst) > dstsize)
        i = ft_strlen(src) + dstsize;
    k = ft_strlen(dst);
    while(*dst)
        dst++;
    while(++k < dstsize)
    {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
    return(i); 
}