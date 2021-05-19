#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	if (!dst && !src)
		return (NULL);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst1 < src1)
		while (len--)
			*dst1++ = *src1++;
	else
		while (len--)
			dst1[len] = src1[len];
	return (dst);
}

char	*strjoin_free(char *s1, char *s2)
{
	size_t	l;
	size_t	j;
	size_t	s11;
	size_t	s21;
	char	*c;

	if (!s1 && !s2)
		return (NULL);
	l = -1;
	j = 0;
	s11 = ft_strlen(s1);
	s21 = ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (s11 + s21 + 1));
	if (!c)
		return (NULL);
	while (++l < s11)
		c[l] = s1[l];
	while (j < s21)
		c[l++] = s2[j++];
	c[l] = '\0';
	free (s1);
	return (c);
}

int	nl_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
