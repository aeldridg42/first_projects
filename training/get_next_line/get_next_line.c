#include "get_next_line.h"

static char	*ft_new(char *leftchars, int i)
{
	char	*new_lch;
	int		l;

	l = 0;
	new_lch = (char *)malloc(sizeof(char) * ((ft_strlen(leftchars) - i) + 1));
	if (!new_lch)
		return (NULL);
	++i;
	while (leftchars[i])
		new_lch[l++] = leftchars[i++];
	new_lch[l] = '\0';
	return (new_lch);
}

static char	*ft_leftchars(char *leftchars)
{
	char	*new_lchars;
	int		i;

	i = 0;
	if (!leftchars)
		return (NULL);
	while (leftchars[i] && leftchars[i] != '\n')
		++i;
	if (!leftchars[i])
	{
		free(leftchars);
		return (NULL);
	}
	new_lchars = ft_new(leftchars, i);
	if (!new_lchars)
		return (NULL);
	free(leftchars);
	return (new_lchars);
}

static char	*ft_line(char *leftchars)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftchars)
		return (NULL);
	while (leftchars[i] && leftchars[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (leftchars[i] && leftchars[i] != '\n')
	{
		line[i] = leftchars[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	ft_return(int charsread)
{
	if (charsread == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*leftchars;
	int				charsread;

	charsread = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (!nl_check(leftchars) && charsread != 0)
	{
		charsread = read(fd, buffer, BUFFER_SIZE);
		if (charsread == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[charsread] = '\0';
		leftchars = strjoin_free(leftchars, buffer);
	}
	free(buffer);
	*line = ft_line(leftchars);
	leftchars = ft_leftchars(leftchars);
	return (ft_return(charsread));
}
