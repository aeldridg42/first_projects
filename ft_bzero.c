#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			l;

	p = (unsigned char *) s;
	l = 0;
	while (l < n)
		p[l++] = '\0';
}
