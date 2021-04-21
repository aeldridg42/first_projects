#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst1 < src1)
		while (len--)
			*dst1++ = *src1++;
	else
		while (len--)
			dst1[len] = src1[len];
	return (dst);
}