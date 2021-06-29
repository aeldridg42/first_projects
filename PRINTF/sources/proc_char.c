#include "../includes/ft_printf.h"

int	processing_char(char c, t_flags *flags)
{
	int count;

	count = 0;
	if (flags->minus == 1)
		ft_putchar(c);
	count = processing_width(flags->width, 1, 0);
	if (flags->minus == 0)
		ft_putchar(c);
	return (count + 1);
}