#include "../includes/ft_printf.h"

static int	ft_input_uns_int(char *uns_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.prec >= 0)
		count += processing_width(flags.prec - 1, ft_strlen(uns_num) - 1, 1);
	count += ft_putwithprec(uns_num, ft_strlen(uns_num));
	return (count);
}

static int	ft_put_uns_int(char *uns_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input_uns_int(uns_num, flags);
	if (flags.prec >= 0 && flags.prec < ft_strlen(uns_num))
		flags.prec = ft_strlen(uns_num);
	if (flags.prec >= 0)
	{
		flags.width -= flags.prec;
		count += processing_width(flags.width, 0, 0);
	}
	else
		count += processing_width(flags.width, ft_strlen(uns_num), flags.zero);
	if (flags.minus == 0)
		count += ft_input_uns_int(uns_num, flags);
	return (count);
}

int			processing_uns_int(unsigned int number, t_flags flags)
{
	int		count;
	char	*uns_int;

	count = 0;
	number = (unsigned int)(4294967295 + 1 + number);
	if (flags.prec == 0 && number == 0)
	{
		count += processing_width(flags.width, 0, 0);
		return (count);
	}
	uns_int = ft_itoa(number);
	if (!uns_int)
		return (-1);
	count = ft_put_uns_int(uns_int, flags);
	free(uns_int);
	return (count);
}