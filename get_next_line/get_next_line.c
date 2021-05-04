#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	while (*s1 != (char) c && *s1)
		s1++;
	if (*s1 == (char) c)
		return (s1);
	return (NULL);
}

static void	ft_zerozero(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

static char	*ft_strdup(const char *s1)
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

static int ft_newline(char *leftchars, char **line)
{
	int i;
	char *ptr;

	i = 0;
	if (leftchars)
	{
		if ((ptr = ft_strchr(leftchars, '\n')))
		{
			*ptr++ = '\0';
			*line = ft_strdup(leftchars);
			ft_memmove(leftchars, ptr, (ft_strlen(ptr) + 1));
			i = 2;
		}
		else
		{
			*line = ft_strdup(leftchars);
			ft_zerozero(leftchars);
			i = -1;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (i);
}

int get_next_line(int fd, char **line)
{
	char		*buffer;
	int			charsread;
	int			check;
	char		*tmpandsearch;
	static char	*leftchars = NULL;
	int kek = 0;

	if (fd < 0)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	charsread = 1;
	check = 1 - ft_newline(leftchars, line);
	// if ((check = 1 - ft_newline(leftchars, line)) == 2)
	// 	free (leftchars);
	while (check > 0 && ((charsread = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[charsread] = '\0';
		if ((tmpandsearch = ft_strchr(buffer, '\n')))
		{
			*tmpandsearch = '\0';
			if (leftchars != NULL)
				free (leftchars);
			leftchars = ft_strdup(tmpandsearch + 1);
			check = 0;
			kek = 1;
		}
		tmpandsearch = *line;
		*line = ft_strjoin(tmpandsearch, buffer);
		free (tmpandsearch);
	}
	free (buffer);
	if (kek != 1 || check == 2)
		free (leftchars);
	if (charsread == 0) {
		return (0);
	}
	else if (charsread || ft_strlen(*line))
		return (1);
	else
		return (charsread);
	// return (1);
}