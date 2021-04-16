#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <stddef.h>
#include <ctype.h>

int main()
{
	char mass1[] = "CHeck1";
	char mass2[] = "QWER";
	printf("memcmp - %d\n", ft_memcmp(mass1, mass2, 4));
	printf("tolower - %c\n", ft_tolower(mass1[1]));
	printf("toupper - %c\n", ft_toupper(mass1[2]));
	printf("isascii - %d\n", ft_isascii('-'));
	printf("isdigit - %d\n", ft_isdigit(mass1[5]));
	printf("isalpha - %d\n", ft_isalpha(mass1[5]));
	printf("isalnum - %d\n", ft_isalnum('0'));
	printf("isprint - %d\n", ft_isprint('0'));
	printf("memset - %s\n", ft_memset(mass1, '?', 3));
	ft_bzero(mass1, 3);
	mass1[0] = 'k';
	mass1[2] = 'L';
	printf("bzero - %s\n", mass1);
	char mass3[] = "qwerty123";
	char mass4[] = "pouytrqwe";
	printf("strlen - %lu\n", ft_strlen(mass2));
	printf("strlcpy - %lu, %s\n", ft_strlcpy(mass3, mass2, 5), mass3);
	printf("!%s!%s!\n", mass3, mass4);
	printf("strlcat - %lu, %s\n", ft_strlcat(mass2, mass4, 6), mass2);
	printf("!%s!%s!\n", mass3, mass4);
	printf("memcpy - %s\n", memcpy(mass3, mass4, 2));
	printf("!%s!%s!\n", mass4, mass2);
	printf("memmove - %s\n", memmove(mass2, mass4, 2));

}