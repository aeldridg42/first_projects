#include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static char *ft_newline(char *leftchars, char **line)
{
	if (leftchars)
	{
		*line = ft_strdup(leftchars);
		free(leftchars);
	}
	else
		*line = ft_calloc(1, 1);
	return (*line);
}

int get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	int charsread;
	int check;
	char *tmpandsearch;
	static char *leftchars;

	check = 1;
	*line = ft_newline(leftchars, line);
	while (check && ((charsread = read(fd, buffer, 1))))
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
		free(tmpandsearch);
	}
	return (0);
}