#include "get_next_line.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (src[i] != '\0')
		i++;
	while (a <= i)
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

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

static int ft_newline(char *leftchars, char **line)
{
	int i;
	char *ptr;

	i = 0;
	if (leftchars)
	{
		if ((ptr = ft_strchr(leftchars, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(leftchars);
			++ptr;
			ft_strcpy(leftchars, ptr);
			// printf("!After strcpy - %s!\n", leftchars);
			++i;

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
	// printf("i = !%d!\n", i);
	return (i);
}

int get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			charsread;
	int			check;
	char		*tmpandsearch;
	static char	*leftchars = NULL;

	check = 1 - ft_newline(leftchars, line);
	while (check > 0 && ((charsread = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[charsread] = '\0';
		if ((tmpandsearch = ft_strchr(buffer, '\n')))
		{
			*tmpandsearch = '\0';
			leftchars = ft_strdup(tmpandsearch + 1);
			check = 0;
		}
		tmpandsearch = *line;
		*line = ft_strjoin(*line, buffer);
		free (tmpandsearch);
	}
	if ((charsread == 0 || charsread == -1) && (!(ft_strlen(*line))))
		return (charsread);
	else if (ft_strlen(*line) || charsread > 0 || ft_strlen(leftchars))
		return (1);
	else
		return (5);
}