#include "../libft/libft.h"
#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

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
			*ptr = '\0';
			*line = ft_strdup(leftchars);
			++ptr;
			strcpy(leftchars, ptr);
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
	static char	*leftchars;

	// printf("!line - %s!\n", *line);
	check = 1 - ft_newline(leftchars, line);
	// printf("!Check = %d!\n", check);
	while (check > 0 && ((charsread = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		// printf("!charsread in while = %d!\n", charsread);
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
	// printf("!charsread = %d!\n", charsread);
	if (charsread > 0 || ft_strlen(leftchars) || ft_strlen(*line))
		return (1);
	else
		return (charsread);
}