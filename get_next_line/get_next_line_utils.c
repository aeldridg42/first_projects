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

char		*strjoin_v2(char *leftchars, char *buffer)
{
	size_t	count_leftchars;
	size_t	count_buffer;
	size_t	length;
	char	*arr;

	if (!leftchars && !buffer)
		return (NULL);
	count_leftchars = ft_strlen(leftchars);
	count_buffer = ft_strlen(buffer);
	length = count_leftchars + count_buffer;
	arr = (char *)malloc(sizeof(char) * length + 1);
	if (!arr)
		return (NULL);
	ft_memmove(arr, leftchars, count_leftchars);
	ft_memmove(arr + count_leftchars, buffer, count_buffer);
	arr[length] = '\0';
	free(leftchars);
	return (arr);
}

int			has_return(char *str)
{
	int i;

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
