#include "libft.h"

static int	count(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++i;
		n *= -1;
	}
	while (n)
	{
		++i;
		n /= 10;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	buff;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{
		buff = str[i];
		str[i] = str[len];
		str[len] = buff;
		++i;
		--len;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*ptr;

	num = n;
	n = count(num);
	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	ptr[n] = '\0';
	if (num < 0)
	{
		ptr[n - 1] = '-';
		num *= -1;
	}
	n = 0;
	if (num == 0)
		ptr[n++] = '0';
	while (num)
	{
		ptr[n++] = num % 10 + '0';
		num /= 10;
	}
	return (ft_strrev(ptr));
}
