#include "psevdoliba.h"

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

char	*ft_uns_itoa(unsigned int n)
{
	unsigned long	num;
	char	*ptr;

	num = n;
	n = count(num);
	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	ptr[n] = '\0';
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