#include "libft.h"

size_t	ft_strlcpy (char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ctr;

	if (dst == NULL || src == NULL)
		return (0);
	ctr = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		if (i < size)
			dst[i] = '\0';
	}
	return (ctr);
}
