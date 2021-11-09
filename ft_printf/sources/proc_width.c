#include "../includes/ft_printf.h"

int	processing_width(int width, int value, int zero)
{
	int	count;

	count = 0;
	while (width > value)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		--width;
		++count;
	}
	return (count);
}
