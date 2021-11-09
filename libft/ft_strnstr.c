#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;

	if (!(ft_strlen(needle)) || (needle == NULL && haystack == NULL))
		return ((char *) haystack);
	while (len && *haystack)
	{
		i = 0;
		while (*haystack != *needle && *haystack && --len)
			haystack++;
		if (*haystack == *needle && len && *haystack)
		{
			while (*needle && *haystack == *needle && len && ++i)
				if (*haystack++ == *needle++)
					--len;
			if (*needle == '\0')
				return ((char *) haystack - i);
			needle -= i;
			len += i - 1;
			if (i)
				haystack -= i - 1;
		}
	}
	return (NULL);
}
