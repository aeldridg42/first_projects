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

static int ft_check(int i, t_flags flags, va_list args, const char *str)
{
	int count;

	count = 0;
	if (is_specificator(str[i]))
	{
		count = processing(flags, args);
		if (count == -1)
			return (-1);
	}
	else if (str[i])
		count = ft_putchar(str[i]);
	return (count);
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
	while (str[i])
	{
		flags = ft_initialize();
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_parse(str, ++i, &flags, args);
			check = ft_check(i, flags, args, str);
			if (check == -1)
				return (-1);
			count += check;
		}
		++i;
	}
	return (count);
}