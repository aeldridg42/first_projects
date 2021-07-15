#ifndef MAIN_H
# define MAIN_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct	s_map {
	char **map;
	int lenght;
	int linesize;
	int collectable;
}				t_map;

typedef struct	s_player {
	int p_y;
	int p_x;
	int e_y;
	int e_x;
}				t_player;

typedef struct	s_images {
	void	*col;
	void	*grass;
	void	*o_exit;
	void	*c_exit;
	void	*tree;
}				t_images;

typedef struct	s_mlxs {
	void    *mlx;
	void    *win;
}				t_mlxs;

typedef struct	s_game {
	t_mlxs		mlxs;
	t_images	images;
	t_player	player;
	t_map		map;
}				t_game;

#endif