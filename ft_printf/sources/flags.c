#include "../includes/ft_printf.h"

t_flags	initialize_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.prec = -1;
	return (flags);
}

t_flags	ft_minus_flag(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_digit_flag(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

t_flags	ft_width_flag(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int	ft_prec_flag(const char *str, int start, t_flags *flags, va_list args)
{
	int	i;

	i = start + 1;
	if (str[i] == '*')
	{
		flags->prec = va_arg(args, int);
		++i;
	}
	else
	{
		flags->prec = 0;
		while (ft_isdigit(str[i]))
		{
			flags->prec = (flags->prec * 10) + (str[i] - 48);
			++i;
		}
	}
	return (i);
}
