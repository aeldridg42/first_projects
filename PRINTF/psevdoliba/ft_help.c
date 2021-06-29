#include "psevdoliba.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_putchar(char c)
{
	int i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_putwithprec(char *str, int precision)
{
	int i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

char	*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int	i;
	int	i1;
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