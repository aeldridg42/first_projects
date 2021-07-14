#include "../includes/ft_printf.h"
#include <stdio.h>

static int	pointer_input(t_flags flags, char *str)
{
	int	count;

	count = ft_putstr("0x");
	if (flags.zero)
		count += processing_width(flags.width, ft_strlen(str) + 2, 1);
	if (flags.prec >= 0)
	{
		count += processing_width(flags.prec, ft_strlen(str), 1);
		count += ft_putwithprec(str, flags.prec);
	}
	else
		count += ft_putstr(str);
	return (count);
}

static int	proc_pointer_p2(int count, t_flags flags, unsigned long num)
{
	char	*str;

	str = ft_itoa_base(num, 16);
	if (!str)
		return (-1);
	str = ft_str_tolower(str);
	if (flags.prec < ft_strlen(str))
		flags.prec = ft_strlen(str);
	if (flags.minus == 1)
		count += pointer_input(flags, str);
	if (flags.zero == 0)
		count += processing_width(flags.width, ft_strlen(str) + 2, 0);
	if (flags.minus == 0)
		count += pointer_input(flags, str);
	free (str);
	return (count);
}

int	processing_pointer(void *adr, t_flags flags)
{
	int				count;
	int				check;
	unsigned long	num;

	num = (unsigned long) adr;
	count = 0;
	if (flags.prec == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
		{
			count = processing_width(flags.width - 2, 0, 0);
			count += ft_putstr("0x");
		}
		else
		{
			count = ft_putstr("0x");
			count += processing_width(flags.width - 2, 0, 0);
		}
		return (count);
	}
	check = proc_pointer_p2(count, flags, num);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
