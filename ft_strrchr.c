#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	while (*s1)
	{
		s1++;
		i++;
	}
	while (*s1 != c && i > 0)
	{
		i--;
		s1--;
	}
	if (*s1 == c)
		return (s1);
	return (NULL);
}
