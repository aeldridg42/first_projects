#include "../includes/ft_printf.h"

static int	ft_input_int(char *arr, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (num < 0 && flags.prec >= 0)
		ft_putchar('-');
	if (flags.prec >= 0)
		count += processing_width(flags.prec - 1, ft_strlen(arr) - 1, 1);
	count += ft_putwithprec(arr, ft_strlen(arr));
	return (count);
}

static int	ft_proc_int_p2(char *arr, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input_int(arr, num, flags);
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
		count += ft_input_int(arr, num, flags);
	free(arr);
	return (count);
}

int	processing_int(int i, t_flags flags)
{
	char	*arr;
	int		num;
	int		count;

	num = i;
	count = 0;
	if (flags.prec == 0 && i == 0)
		return (count += processing_width(flags.width, 0, 0));
	if (i < 0 && (flags.prec >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.prec == -1)
			ft_putwithprec("-", 1);
		i *= -1;
		flags.zero = 1, --flags.width, ++count;
		if (i == -2147483648)
			arr = ft_strdup("2147483648");
		else
			arr = ft_itoa(i);
	}
	else
		arr = ft_itoa(i);
	if (arr == NULL)
		return (-1);
	count += ft_proc_int_p2(arr, num, flags);
	return (count);
}
