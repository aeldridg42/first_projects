#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>

# define BUFFER_SIZE 12

int get_next_line(int fd, char **line);

# endif