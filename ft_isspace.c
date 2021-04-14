#include "libft.h"

int ft_isspace(char a)
{
    if(a == ' ' || a == '\t' || a == '\v' || a == '\n' || a == '\f' || a == '\r')
        return(8192);
    return(0);
}