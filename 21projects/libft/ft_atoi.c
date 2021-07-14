#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\r' || c == '\f' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	i;
	unsigned long	l_max;
	int				neg;

	i = 0;
	neg = 1;
	l_max = 9223372036854775807;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++ ;
	}
	while (ft_isdigit(*str))
	{
		i = i * 10 + *str++ - '0';
		if (i > l_max + 1 && neg == -1)
			return (0);
		if (i > l_max && neg == 1)
			return (-1);
	}
	return ((int) i * neg);
}
