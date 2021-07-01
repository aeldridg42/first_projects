#include "psevdoliba.h"

int	ft_strlen(const char *s)
{
	int	i;

    if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}