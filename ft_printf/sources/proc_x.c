#include "../includes/ft_printf.h"

static int	x_input(char *x, t_flags flags)
{
	int	ctr;

	ctr = 0;
	if (flags.prec >= 0)
		ctr += processing_width(flags.prec, ft_strlen(x), 1);
	ctr += ft_putstr(x);
	return (ctr);
}

static int	proc_x_p2(char *arr, t_flags flags)
{
	int	ctr;

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

int	processing_x(unsigned int input, int lowercase, t_flags flags)
{
	int		ctr;
	char	*arr;

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
	ctr = proc_x_p2(arr, flags);
	free (arr);
	return (ctr);
}
