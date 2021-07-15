#ifndef SO_LONG_H
# define SO_LONG_H

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
    void    *cola;
    void    *player;
}				t_images;

typedef struct	s_mlx {
	void    *mlx;
	void    *win;
}				t_mlx;

typedef struct	s_game {
	t_mlx		mlx;
	t_images	images;
	t_player	player;
	t_map		map;
    int         countmoves;
    int         exitflag;
    char        *num;
}				t_game;

#endif