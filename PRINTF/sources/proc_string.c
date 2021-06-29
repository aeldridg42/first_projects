#include "../includes/ft_printf.h"

static int	ft_input_str(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += processing_width(flags.dot, ft_strlen(str), 0);
		count += ft_putwithprec(str, flags.dot);
	}
	else
		count += ft_putwithprec(str, ft_strlen(str));
	return (count);
}

int			processing_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_input_str(str, flags);
	if (flags.dot >= 0)
		count += processing_width(flags.width, flags.dot, 0);
	else
		count += processing_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_input_str(str, flags);
	return (count);
}