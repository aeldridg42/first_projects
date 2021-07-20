#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	symb;

	str = (unsigned char *)s;
	symb = (unsigned char)c;
	while (n--)
	{
		if (*str == symb)
			return (str);
		str++;
	}
	return (NULL);
}
