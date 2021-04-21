#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*hs;
	char	*nd;

	i = 0;
	hs = (char *) haystack;
	nd = (char *) needle;
	if (!(ft_strlen(nd)) || (nd == NULL && hs == NULL))
		return (hs);
	while (len && *hs)
	{
		while (*hs != *nd && *hs && --len)
			hs++;
		if (*hs == *nd && len && *hs)
		{
			while (*nd && *hs++ == *nd && len-- && ++i)
				nd++;
			if (*nd == '\0')
				return (hs -= i);
			nd -= i;
			i = 0;
		}
	}
	return (NULL);
}
