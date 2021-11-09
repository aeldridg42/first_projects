#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	i;
	size_t	l;

	l = 0;
	i = ft_strlen(dst);
	if (size > i)
		res = i + ft_strlen(src);
	else
		return (ft_strlen(src) + size);
	while (src[l] && (i + 1) < size)
	{
		dst[i] = src[l];
		i++;
		l++;
	}
	dst[i] = '\0';
	return (res);
}
