#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		nl_check(char *str);

size_t	ft_strlen(const char *s);

char	*strjoin_free(char *s1, char *s2);

void	*ft_memmove(void *dst, const void *src, size_t len);

#endif