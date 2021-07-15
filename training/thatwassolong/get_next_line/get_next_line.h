#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		nl_check(char *str);
int		ft_strlen1(const char *s);
int		ft_return(int charsread, char **line);

char	*strjoin_free(char *s1, char *s2);

#endif