#include "../includes/ft_printf.h"

// static int	ft_x_input(char *x, t_flags flags)
// {
// 	int ctr;

// 	ctr = 0;
// 	if (flags.prec >= 0)
// 	{
// 		ctr += processing_width(flags.prec, ft_strlen(x), 1);
// 	}
// 	ctr += ft_putwithprec(x, ft_strlen(x));
// 	return (ctr);
// }

// static int	ft_put_x(char *x, t_flags flags)
// {
// 	int ctr;

// 	ctr = 0;
// 	if (flags.minus == 1)
// 		ctr += ft_x_input(x, flags);
// 	if (flags.prec >= 0 && flags.prec < ft_strlen(x))
// 		flags.prec = ft_strlen(x);
// 	if (flags.prec >= 0)
// 	{
// 		flags.width -= flags.prec;
// 		ctr += processing_width(flags.width, 0, 0);
// 	}
// 	else
// 	{
// 		ctr += processing_width(flags.width, ft_strlen(x), flags.zero);
// 	}
// 	if (flags.minus == 0)
// 		ctr += ft_x_input(x, flags);
// 	return (ctr);
// }

// int			processing_x(unsigned int number, int lowercase, t_flags flags)
// {
// 	char	*x;
// 	int		ctr;

// 	number = (unsigned int)(4294967295 + 1 + number);
// 	ctr = 0;
// 	if (flags.prec == 0 && number == 0)
// 	{
// 		ctr += processing_width(flags.width, 0, 0);
// 		return (ctr);
// 	}
// 	x = ft_itoa_base((unsigned long)number, 16);
// 	if (x == NULL)
// 		return (-1);
// 	if (lowercase == 1)
// 		x = ft_str_tolower(x);
// 	ctr += ft_put_x(x, flags);
// 	free(x);
// 	return (ctr);
// }

static int	x_input(char *x, t_flags flags)
{
	int ctr;

	ctr = 0;
	if (flags.prec >= 0)
		ctr += processing_width(flags.prec, ft_strlen(x), 1);
	ctr += ft_putstr(x);
	return (ctr);
}

static int ft_x_input(char *arr, t_flags flags)
{
	int ctr;

	ctr = 0;
	if (flags.minus == 1)
		ctr += x_input(arr, flags);
	if (flags.prec >= 0 && flags.prec < ft_strlen(arr))
		flags.prec = ft_strlen(arr);
	if (flags.prec >= 0)
	{	
		flags.width -= flags.prec;
		ctr += processing_width(flags.width, 0, 0);
	}
	else
		ctr += processing_width(flags.width, ft_strlen(arr), flags.zero);
	if (flags.minus == 0)
		ctr += x_input(arr, flags);
	return (ctr);
}

int			processing_x(unsigned int input, int lowercase, t_flags flags)
{
	int ctr;
	char *arr;

	if (flags.prec == 0 && input == 0)
	{
		ctr = processing_width(flags.width, 0, 0);
		return (ctr);
	}
	arr = ft_itoa_base(input, 16);
	if (arr == NULL)
		return (-1);
	if (lowercase)
		arr = ft_str_tolower(arr);
    ctr = ft_x_input(arr, flags);
	free (arr);
	return (ctr);
}