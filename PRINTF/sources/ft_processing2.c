#include "../includes/ft_printf.h"

static int	ft_x_input(char *x, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += processing_width(flags.dot - 1, ft_strlen(x) - 1, 1);
	}
	count += ft_putwithprec(x, ft_strlen(x));
	return (count);
}

static int	ft_put_x(char *x, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_x_input(x, flags);
	if (flags.dot >= 0 && flags.dot < ft_strlen(x))
		flags.dot = ft_strlen(x);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += processing_width(flags.width, 0, 0);
	}
	else
	{
		count += processing_width(flags.width, ft_strlen(x), flags.zero);
	}
	if (flags.minus == 0)
		count += ft_x_input(x, flags);
	return (count);
}

int			processing_x(unsigned int number, int lowercase, t_flags flags)
{
	char	*x;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count += processing_width(flags.width, 0, 0);
		return (count);
	}
	x = ft_utl_base((unsigned long long)number, 16);
	if (x == NULL)
		return (-1);
	if (lowercase == 1)
		x = ft_str_tolower(x);
	count += ft_put_x(x, flags);
	free(x);
	return (count);
}

static int	ft_input_ptr(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += ft_putwithprec("0x", 2);
	if (flags.dot >= 0)
	{
		count += processing_width(flags.dot, ft_strlen(pointer), 1);
		count += ft_putwithprec(pointer, flags.dot);
	}
	else
		count += ft_putwithprec(pointer, ft_strlen(pointer));
	return (count);
}

int			processing_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*ptr;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			(((count += processing_width(flags.width - 2, 0, 0))
			|| 1) && ((count += ft_putwithprec("0x", 2)) || 1));
		else
			(((count += ft_putwithprec("0x", 2)) || 1) &&
			((count += processing_width(flags.width - 2, 0, 0)) || 1));
		return (count);
	}
	ptr = ft_utl_base(num, 16);
	if (ptr == NULL)
		return (-1);
	ptr = ft_str_tolower(ptr);
	if (flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		count += ft_input_ptr(ptr, flags);
	count += processing_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		count += ft_input_ptr(ptr, flags);
	free(ptr);
	return (count);
}