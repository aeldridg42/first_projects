#include "get_next_line.h"

int	ft_strlen1(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
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
	s1_count = ft_strlen1(s1);
	s2_count = ft_strlen1(s2);
	arr = (char *)malloc(sizeof(char) * (s1_count + s2_count + 1));
	if (!arr)
		return (NULL);
	while (++l < s1_count)
		arr[l] = s1[l];
	while (j < s2_count)
		arr[l++] = s2[j++];
	arr[l] = '\0';
	if (s1)
		free (s1);
	return (arr);
}

int	nl_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_return(int charsread, char **line)
{
	if (!line)
		return (-1);
	if (charsread == 0)
		return (0);
	return (1);
}
