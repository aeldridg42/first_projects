#include "../includes/ft_printf.h"

static int	ft_input_uns_int(char *u_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
		count += processing_width(flags.dot - 1, ft_strlen(u_num) - 1, 1);
	count += ft_putwithprec(u_num, ft_strlen(u_num));
	return (count);
}

static int	ft_put_uns_int(char *u_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_input_uns_int(u_num, flags);
	if (flags.dot >= 0 && flags.dot < ft_strlen(u_num))
		flags.dot = ft_strlen(u_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += processing_width(flags.width, 0, 0);
	}
	else
		count += processing_width(flags.width, ft_strlen(u_num), flags.zero);
	if (flags.minus == 0)
		count += ft_input_uns_int(u_num, flags);
	return (count);
}

int			processing_uns_int(unsigned int number, t_flags flags)
{
	int		count;
	char	*u_int;

	count = 0;
	number = (unsigned int)(4294967295 + 1 + number);
	if (flags.dot == 0 && number == 0)
	{
		count += processing_width(flags.width, 0, 0);
		return (count);
	}
	u_int = ft_uns_itoa(number);
	if (!u_int)
		return (-1);
	count = ft_put_uns_int(u_int, flags);
	free(u_int);
	return (count);
}

int	processing_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putwithprec("%", 1);
	count += processing_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putwithprec("%", 1);
	return (count);
}