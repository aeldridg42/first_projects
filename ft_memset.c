#include "libft.h"
#include <stdio.h>

void	*ft_memset (void *destination, int c, size_t n)
{
	unsigned char	*k;
	int				i;
	int				n1;

	k = (unsigned char *) destination;
	i = 0;
	n1 = (int) n;
	while (i < n1)
		k[i++] = c;
	return (destination);
}
