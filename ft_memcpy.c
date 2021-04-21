#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *) dst;
	src1 = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n--)
		*dst1++ = *src1++;
	return (dst);
}
