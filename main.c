#include "libft.h"
#include <stdio.h>
#include <string.h> 


int main()
{
    char prikol[] = " 93sD";
    printf("ischar - %d\n", ft_ischar('a', 'a'));
    printf("isdigit - %d\n", ft_isdigit(prikol[0]));
    printf("islower - %d\n", ft_islower(prikol[2]));
    printf("isspace - %d\n", ft_isspace(prikol[2]));
    printf("isupper - %d\n", ft_isupper(prikol[0]));
    printf("strrev - %s\n", strrev(prikol));

}