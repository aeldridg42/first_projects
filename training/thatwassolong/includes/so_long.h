#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
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

typedef struct	s_count {
	int         countmoves;
	int			countanim;
	int			exitflag;
}				t_count;

typedef struct	s_mlx {
	void    *mlx;
	void    *win;
}				t_mlx;

typedef struct	s_pics {
	void	*tomato;
	void	*carrot;
	void	*grass;
	void	*tree;
	void    *cola;
	void    *player;
	void 	*anim1;
	void 	*anim2;
	void 	*anim3;
	void 	*anim4;
	void	*o_exit;
	void	*c_exit;
}				t_pics;

typedef struct	s_game {
	t_map		map;
	t_player	players;
	t_count	count;
	t_mlx		mlx;
	t_pics		images;
    char        *num;
}				t_game;

void	ft_error(void);
void	ft_free(t_game *game);
int	ft_close(int keycode, t_game game);
void	winning(t_game *game);
void	loosing(t_game *game);
void	game_lenght(char *argv, t_game *game);
int	game_line(t_game *game);
void	validletter(char i);
void	mapcheck1(t_game *game);
void	mapcheck2(t_game *game);
void	parser(char **argv, t_game *game);
void	moveright(t_game *game);
void	moveleft(t_game *game);
void	moveup(t_game *game);
void	movedown(t_game *game);
void	keycode_d(t_game *game);
void	keycode_a(t_game *game);
void	keycode_w(t_game *game);
void	keycode_s(t_game *game);
int	key_hook(int keycode, t_game *game);
void	draw_exit(t_game *game);
void	draw1(t_game *game, int i, int i2);
void	draw2(t_game *game, int i, int i2);
void	draw3(t_game *game, int i, int i2);
void	mapdraw(t_game *game);
int	render_next_frame(t_game *game);
void	getimage(t_game *game);





#endif