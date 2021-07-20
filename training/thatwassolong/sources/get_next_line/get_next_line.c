#include "so_long.h"

static int	i_search(char *leftchars)
{
	int	i;

	i = 0;
	while (leftchars[i] && leftchars[i] != '\n')
		++i;
	return (i);
}

static char	*ft_leftchars(char *leftchars)
{
	char	*new_lch;
	int		i;
	int		l;

	i = i_search(leftchars);
	if (!leftchars[i])
	{
		free (leftchars);
		return (NULL);
	}
	l = 0;
	new_lch = (char *)malloc(sizeof(char) * ((ft_strlen(leftchars) - i) + 1));
	if (!new_lch)
		return (NULL);
	while (leftchars[++i])
		new_lch[l++] = leftchars[i];
	new_lch[l] = '\0';
	if (leftchars)
		free (leftchars);
	return (new_lch);
}

static char	*ft_line(char *leftchars)
{
	int		i;
	char	*line;

	i = i_search(leftchars);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (leftchars[i] && leftchars[i] != '\n')
	{
		line[i] = leftchars[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

static int	ft_error(int fd, char *buffer, int charsread)
{
	int	i;

	i = read(fd, 0, 0);
	if (!buffer)
		return (1);
	if ((fd != 0 && fd < 3) || charsread == -1 || i == -1)
	{
		free (buffer);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*leftchars;
	int				charsread;

	charsread = 1;
	if (!line || BUFFER_SIZE < 1)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (ft_error(fd, buffer, charsread))
		return (-1);
	while (nl_check(leftchars) && charsread != 0)
	{
		charsread = read(fd, buffer, BUFFER_SIZE);
		if (ft_error(fd, buffer, charsread))
			return (-1);
		buffer[charsread] = '\0';
		leftchars = strjoin_free(leftchars, buffer);
		if (!leftchars)
			return (-1);
	}
	free (buffer);
	*line = ft_line(leftchars);
	leftchars = ft_leftchars(leftchars);
	return (ft_return(charsread, line));
}
