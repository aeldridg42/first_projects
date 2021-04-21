#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	int				l;
	int				r;

	p = (unsigned char *) s;
	l = 0;
	r = (int) n;
	while (l < r)
		p[l++] = '\0';
}
