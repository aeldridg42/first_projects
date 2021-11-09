#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	k;
	size_t			i;

	i = 0;
	k = c;
	src1 = (unsigned char *) src;
	dst1 = (unsigned char *) dst;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		dst1[i] = src1[i];
		if (dst1[i] == k)
			return (dst + i + 1);
		++i;
	}
	return (NULL);
}
