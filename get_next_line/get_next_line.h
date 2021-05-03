#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 2

int get_next_line(int fd, char **line);

# endif