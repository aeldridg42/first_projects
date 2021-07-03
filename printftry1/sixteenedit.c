#include "libft/libft.h"
#include "libftprintf.h"

static int inputctr(unsigned int input)
{
    int i;

	i = 0;
    while (input)
    {
        input /= 16;
        ++i;
    }
	return (i);
}

void sixtnedit(unsigned int input, char x1)
{
    int i;
	int ctr;
	int buff;
	int loworupper;

	i = 0;
	loworupper = 0;
    if (x1 == 'X')
        loworupper = 32;
    ctr = inputctr(input);
    char arr[ctr + 1];
    while (input)
    {
        buff = input % 16;
        if (buff >= 10)
        {
            buff -= 10;
            arr[i++] = 97 - loworupper + buff;
        }
        else
            arr[i++] = buff + '0';
        input /= 16;
    }
    arr[i] = '\0';
    ft_putstr(ft_strrev(arr));
}