#include "../includes/ft_printf.h"

static int	processing_p1(int c, t_flags flags, va_list args, int count)
{
	if (c == 'c')
		count = processing_char(va_arg(args, int), flags);
	else if (c == '%')
		count = processing_char(c, flags);
	else if (c == 's')
		count = processing_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
	{
		count = processing_int(va_arg(args, int), flags);
		if (count == -1)
			return (-1);
	}
	else if (c == 'p')
	{
		count = processing_pointer(va_arg(args, void *), flags);
		if (count == -1)
			return (-1);
	}
	return (count);
}

static int	processing_p2(int c, t_flags flags, va_list args, int count)
{
	if (c == 'x')
	{
		count = processing_x(va_arg(args, unsigned int), 1, flags);
		if (count == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		count = processing_x(va_arg(args, unsigned int), 0, flags);
		if (count == -1)
			return (-1);
	}
	else if (c == 'u')
	{
		count = proc_uns_int((unsigned int)va_arg(args, unsigned int), flags);
		if (count == -1)
			return (-1);
	}
	else if (c == 's')
		count = processing_string(va_arg(args, char *), flags);
	return (count);
}

int	processing(t_flags flags, va_list args)
{
	int	count;
	int	c;

	c = flags.type;
	count = 0;
	if (c == 'c' || c == '%' || c == 'i' || c == 'd' || c == 'p')
		count = processing_p1(c, flags, args, count);
	else if (c == 'x' || c == 'X' || c == 'u' || c == 's')
		count = processing_p2(c, flags, args, count);
	return (count);
}
