#include "libftprintf.h"

int counter(const char *input1, ...)
{
	char *input;
	int i;
	va_list ptr;
	va_start(ptr, input1);

	input = (char *) input1;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			if (input[i + 1] == '%')
				ft_putchar(input[i]);
			else
			{
				if (input[i + 1] == 'c')
					ft_putchar(va_arg(ptr, int));
				else if (input[i + 1] == 's')
					ft_putstr(va_arg(ptr, char *));
				else if (input[i + 1] == 'u')
					ft_putnbr_fd(va_arg(ptr, unsigned int), 1);
				else if (input[i + 1] == 'x' || input[i + 1] == 'X')
					sixtnedit(va_arg(ptr, unsigned int), input[i + 1]);
				else if (input[i + 1] == 'p')
					ft_adress(va_arg(ptr, void *));
			}
			++i;
		}
		else
			ft_putchar(input[i]);
		++i;
	}
	return (0);
}

int ft_printf(const char *input1, ...)
{
	char *input = (char *) input1;
    ft_putstr(input);
	return (0);
}