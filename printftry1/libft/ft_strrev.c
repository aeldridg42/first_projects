#include "libft.h"

char	*ft_strrev(char *str)
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