#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\r' || c == '\f' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
