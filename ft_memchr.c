#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s1;

	s1 = (char *) s;
	while (*s1 != c && n-- && *s1)
		s1++;
	if (*s1 == c && n)
		return (s1);
	return (NULL);
}
