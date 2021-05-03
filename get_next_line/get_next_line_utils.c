#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	i1;
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

void	*ft_memset (void *destination, int c, size_t n)
{
	unsigned char	*k;
	int				i;
	int				n1;

	k = (unsigned char *) destination;
	i = 0;
	n1 = (int) n;
	while (i < n1)
		k[i++] = (unsigned char) c;
	return (destination);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_memset (ptr, '\0', size * count);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*c;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (*s1)
		c[i++] = *s1++;
	while (*s2)
		c[i++] = *s2++;
	c[i] = '\0';
	return (c);
}