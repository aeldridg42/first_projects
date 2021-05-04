#include "get_next_line.h"

#define BUFFER_SIZE 1

void	ft_zerozero(char *s)
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
			*ptr++ = '\0';
			*line = ft_strdup(leftchars);
			ft_memmove(leftchars, ptr, (ft_strlen(ptr) + 1));
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
	return (i);
}

int get_next_line(int fd, char **line)
{
	char		*buffer;
	int			charsread;
	int			check;
	char		*tmpandsearch;
	static char	*leftchars = NULL;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	charsread = 1;
	check = 1 - ft_newline(leftchars, line);
	while (check > 0 && ((charsread = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[charsread] = '\0';
		if ((tmpandsearch = ft_strchr(buffer, '\n')))
		{
			*tmpandsearch = '\0';
			if (!leftchars)
				free (leftchars);
			leftchars = ft_strdup(tmpandsearch + 1);
			check = 0;
		}
		tmpandsearch = *line;
		*line = ft_strjoin(tmpandsearch, buffer);
		free (tmpandsearch);
	}
	free (buffer);
	if (ft_strlen(leftchars) || charsread || ft_strlen(*line))
		return (1);
	else if (charsread == 0 && !(ft_strlen(leftchars)))
		return (0);
	else
		return (charsread);
}