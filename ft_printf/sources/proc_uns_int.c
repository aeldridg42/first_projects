#include "../includes/ft_printf.h"

static int	ft_input(char *arr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.prec >= 0)
		count += processing_width(flags.prec - 1, ft_strlen(arr) - 1, 1);
	count += ft_putwithprec(arr, ft_strlen(arr));
	return (count);
}

static int	ft_put_uint(char *arr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input(arr, flags);
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
		count += ft_input(arr, flags);
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
	count = ft_put_uint(arr, flags);
	free(arr);
	return (count);
}
