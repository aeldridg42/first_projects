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
	char prikol[] = "qwerty";
	printf("memset - %s\n", ft_memset(prikol, 'l', 3));
	ft_bzero(mass1, 3);
	mass1[0] = 'k';
	mass1[1] = 'L';
	printf("bzero - %s\n", mass1);
	char mass3[] = "qwerty123";
	char mass4[] = "pouytrqwes";
	printf("strlen - %lu\n", ft_strlen(mass2));
	printf("strlcpy - %lu, %s\n", ft_strlcpy(mass3, mass2, 5), mass3);
	printf("!%s!%s!\n", mass3, mass4);
	printf("strlcat - %lu, %s\n", ft_strlcat(mass2, mass4, 6), mass2);
	printf("!%s!%s!\n", mass3, mass4);
	printf("memcpy - %s\n", ft_memcpy(mass3, mass4, 0));
	printf("!%s!%s!\n", mass4, mass2);
	printf("memmove - %s\n", memmove(mass2, mass4, 2)); 
	char mass5[] = "qwe";
	printf("!%s!\n", mass5);
	printf("!strchr! - %s\n", ft_strchr(mass5, '1'));
	printf("!%s!\n", mass5);
	printf("strRchr - %s\n", ft_strrchr(mass5, 'q'));
	printf("!%s!%s!\n", mass4, mass5);
	printf("strncmp - %d\n", ft_strncmp(mass4, mass5, 1));
	printf("!%s!\n", mass5);
	printf("!memchr - %s\n", ft_memchr(mass5, 'r', 3));
	char mass6[] = "qwer";
	char mass7[] = "qasd";
	printf("!%s!%s!\n", mass6, mass7);
	printf("strnstr - %s\n", ft_strnstr(mass6, mass7, 4));
	char mass8[40] = "\t\n \r-21312ddd";
	printf("!%s!\n", mass8);
	printf("atoi - %d\n", atoi(mass8));
	printf("ft_atoi - %d\n", ft_atoi(mass8));
	int size = 8539;
	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	printf("%d\n", memcmp(d1, d2, size * sizeof(int)));
	ft_putnbr_fd(215, 1);
	ft_putendl_fd(mass7, 1);
	unsigned char src[]="qwertyui!";
    unsigned char dst[22]="aaaabbbb";
	unsigned char dst1[22]="aaaabbbb";
    printf ("dst: %s\n", memccpy (dst, src,'e', 22));
	printf ("dst1: %s\n",ft_memccpy (dst1, src, 'e', 22));
	printf("!%s\n", dst);
	printf("!%s\n", dst1);
	char mass9[] = "bonjourno";
	printf("!%s!\n", mass9);
	printf("!memchr - %s\n", memchr(mass9, 'n', 2));
	printf("ft_strncmp - %d\n", ft_strncmp("abcdefgh", "", 0));
	printf("strncmp - %d\n", strncmp("abcdefgh", "", 0));
	char mass10[15] = "aaaaaaa\0qw";
	char mass11[15] = "aaaaaaa\0qw";
	//mass10[10] = 'a';
	//mass11[10] = 'a';
	char mass12[] = "lorem ipsum dolor sit amet";
	char mass13[] = "lorem ipsum dolor sit amet";
	printf("strlcat - %lu, %s\n", strlcat(mass10, mass12, 6), mass10);
	printf("ftstrlcat - %lu, %s\n", ft_strlcat(mass11, mass12, 6), mass10);
	printf("%s\n", ft_itoa(234));
	printf("%d\n", ft_atoi("-214748350000"));
	printf("%d\n", atoi("-214748350000"));
}