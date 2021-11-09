#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define LC_SIZE 4096

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		nl_check(char *str);
int		ft_strlen(const char *s);
int		ft_return(int charsread, char **line);

char	*strjoin_free(char *s1, char *s2);

#endif