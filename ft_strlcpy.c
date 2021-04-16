#include "libft.h"

size_t ft_strlcpy (char *restrict dst, const char * restrict src, size_t size)
{
    size_t i = 0;
    while(++i < size)
    {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
    src -= i-1;
    i = ft_strlen(src);
    return (i);
}