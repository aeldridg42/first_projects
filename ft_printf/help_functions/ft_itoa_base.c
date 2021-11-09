#include "../includes/ft_printf.h"

static char	*ft_base(unsigned long number, int base, int i, char *str)
{
	while (number != 0)
	{
		if ((number % base) < 10)
			str[i - 1] = (number % base) + 48;
		else
			str[i - 1] = (number % base) + 55;
		number /= base;
		i--;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long number, int base)
{
	unsigned long	tmp;
	int				i;
	char			*str;

	tmp = number;
	i = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= base;
		++i;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	str = ft_base(tmp, base, i, str);
	return (str);
}
