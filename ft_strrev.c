#include "libft.h"

char *ft_strrev(char *str)
{
    int i = 0, k = 0, l = 0;
    while(*str)
    {
        i++;
        str++;
    }
    str -= i;
    char copy[i+1];
    k = i - 1;
    while(l < i)
        copy[l++] = str[k--];
    copy[l] = '\0';
    l = -1;
    while(copy[++l])
        str[l] = copy[l];
    return(str);
}