#include "libft.h"

size_t  ft_strlen(const char *s)
{
    size_t i = 0;
    while(*s)
    {
        i++;
        s++;
    }
    return(i);
}