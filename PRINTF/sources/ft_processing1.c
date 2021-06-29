#include "../includes/ft_printf.h"

int	processing_width(int width, int minus, int zero)
{
	int count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}

int	processing_char(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = processing_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}

static int processing_p1(int c, t_flags flags, va_list args, int count)
{
	int check;

	if (c == 'c')
		count = processing_char(va_arg(args, int), flags);
	else if (c == '%')
		count += processing_percent(flags);
	else if (c == 'p')
	{
		check = processing_pointer(va_arg(args, unsigned long long), flags);
		if (check == -1)
			return (-1);
		count += check;
	}
	else if (c == 's')
		count = processing_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
	{
		check = processing_int(va_arg(args, int), flags);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}

static int processing_p2(int c, t_flags flags, va_list args, int count)
{
	int check;

	if (c == 'x')
	{
		check = processing_x(va_arg(args, unsigned int), 1, flags);
		if (check == -1)
			return (-1);
		count += check;
	}
	else if (c == 'X')
	{
		check = processing_x(va_arg(args, unsigned int), 0, flags);
		if (check == -1)
			return (-1);
		count += check;
	}
	else if (c == 'u')
	{
		check = processing_uns_int((unsigned int)va_arg(args, unsigned int), flags);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}

int	processing(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c' || c == '%' || c == 's' || c == 'i' || c == 'd')
		count = processing_p1(c, flags, args, count);
	else if (c == 'x' || c == 'X' || c == 'u')
		count = processing_p2(c, flags, args, count);
	return (count);
}