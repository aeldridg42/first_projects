#include "libft.h"

static int	ctr(long n)
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
	char	tmp;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	k;
	char	*ptr;

	k = n;
	n = ctr(k);
	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	ptr[n] = '\0';
	if (k < 0)
	{
		ptr[n - 1] = '-';
		k *= -1;
	}
	n = 0;
	if (k == 0)
		ptr[n++] = '0';
	while (k)
	{
		ptr[n++] = k % 10 + '0';
		k /= 10;
	}
	return (ft_strrev(ptr));
}
