#include "../includes/ft_printf.h"

static int	str_input(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.prec >= 0)
	{
		count += processing_width(flags.prec, ft_strlen(str), 0);
		count += ft_putwithprec(str, flags.prec);
	}
	else
		count += ft_putstr(str);
	return (count);
}

int	processing_string(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.prec >= 0 && flags.prec > ft_strlen(str))
		flags.prec = ft_strlen(str);
	if (flags.minus == 1)
		count += str_input(str, flags);
	if (flags.prec >= 0)
		count += processing_width(flags.width, flags.prec, flags.zero);
	else
		count += processing_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += str_input(str, flags);
	return (count);
}
