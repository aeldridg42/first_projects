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
	size_t	s1_count;
	size_t	s2_count;
	char	*arr;

	if (!s1 && !s2)
		return (NULL);
	l = -1;
	j = 0;
	s1_count = ft_strlen(s1);
	s2_count = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (s1_count + s2_count + 1));
	if (!arr)
		return (NULL);
	while (++l < s1_count)
		arr[l] = s1[l];
	while (j < s2_count)
		arr[l++] = s2[j++];
	arr[l] = '\0';
	free (s1);
	return (arr);
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
