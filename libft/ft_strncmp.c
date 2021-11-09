#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char *) s1;
	s21 = (unsigned char *) s2;
	i = 0;
	while (s11[i] == s21[i] && s11[i] && s21[i] && (size_t) i < n - 1)
		i++;
	if (n)
		i = (int) s11[i] - (int) s21[i];
	return (i);
}
