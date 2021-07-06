#include "../includes/ft_printf.h"

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

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	buff;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{
		buff = str[i];
		str[i] = str[len];
		str[len] = buff;
		++i;
		--len;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		i1;
	char	*ptr;	

	i = ft_strlen(s1);
	i1 = 0;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	while (i--)
		ptr[i1++] = *s1++;
	ptr[i1] = '\0';
	return (ptr);
}
