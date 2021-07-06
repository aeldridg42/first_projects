#include "../includes/ft_printf.h"

static int	uns_int_input(char *arr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.prec >= 0)
		count += processing_width(flags.prec, ft_strlen(arr), 1);
	count += ft_putstr(arr);
	return (count);
}

static int	proc_uns_int_p2(char *arr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += uns_int_input(arr, flags);
	if (flags.prec >= 0 && flags.prec < ft_strlen(arr))
		flags.prec = ft_strlen(arr);
	if (flags.prec >= 0)
	{
		flags.width -= flags.prec;
		count += processing_width(flags.width, 0, 0);
	}
	else
		count += processing_width(flags.width, ft_strlen(arr), flags.zero);
	if (flags.minus == 0)
		count += uns_int_input(arr, flags);
	return (count);
}

int	proc_uns_int(unsigned int number, t_flags flags)
{
	int		count;
	char	*arr;

	count = 0;
	if (flags.prec == 0 && number == 0)
		return (count += processing_width(flags.width, 0, 0));
	arr = ft_uns_itoa(number);
	if (arr == NULL)
		return (-1);
	count = proc_uns_int_p2(arr, flags);
	free(arr);
	return (count);
}
