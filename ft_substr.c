#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	len += (size_t) start;
	while (start < len)
	{
		s1[i] = s[start];
		i++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}
