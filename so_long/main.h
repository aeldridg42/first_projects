#ifndef MAIN_H
# define MAIN_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"

typedef struct	s_map {
    char **map;
    int lenght;
    int linesize;
}               t_map;

#endif