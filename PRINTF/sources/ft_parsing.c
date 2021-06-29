#include "../includes/ft_printf.h"

static int	is_specificator(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'|| c == 'u' || c == 'x' || c == 'X' || c == '%')
        return (1);
    return (0);
}

static int	is_flag(int c)
{
	if (c == '.' || c == '*' || c == '0' || c == '-' || c == ' ')
        return (1);
    return (0);
}

t_flags	ft_initialize(t_flags flags)
{
	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	return (flags);
}

int	ft_parse(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!is_specificator(str[i]) && !is_flag(str[i]) && !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width_flag(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit_flag(str[i], *flags);
		if (is_specificator(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	processing_input(const char *str, va_list args)
{
	int		i;
	int		count;
	int		check;
	t_flags	flags;

	i = 0;
	count = 0;
	while (1)
	{
		flags = ft_initialize(flags);
		if (!str[i])
			break ;
		else if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse(str, ++i, &flags, args);
			if (is_specificator(str[i]))
			{
				check = processing((char)flags.type, flags, args);
				if (check == -1)
					return (-1);
				count += check;
			}
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}