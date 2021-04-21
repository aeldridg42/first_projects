#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	while (*s1 != c && *s1)
		s1++;
	if (*s1 == c)
		return (s1);
	return (NULL);
}
