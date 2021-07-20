#ifndef SO_LONG_H
# define SO_LONG_H
# define SCALE 42
# define HALF 21
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define BUFFER_SIZE 1

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map {
	char		**map;
	int			lenght;
	int			linesize;
	int			collectable;
}				t_map;

typedef struct s_pictures {
	void		*exit2;
	void		*exit3;
	void		*exit4;
	void		*exit5;
	void		*exit6;
	void		*exit7;
	void		*exit8;
	void		*exit9;
	void		*exit10;
	void		*enemy1;
	void		*enemy2;
	void		*enemy3;
	void		*enemy4;
	void		*enemy5;
	void		*enemy6;
	void		*enemy7;
	void		*enemy8;
	void		*heroleft1;
	void		*heroleft2;
	void		*heroleft3;
	void		*heroleft4;
	void		*heroup1;
	void		*heroup2;
	void		*heroup3;
	void		*heroup4;
	void		*herodown1;
	void		*herodown2;
	void		*herodown3;
	void		*herodown4;
}				t_pictures;

typedef struct s_player {
	t_pictures	anim;
	int			p_y;
	int			p_x;
	int			heroflag;
}				t_player;

typedef struct s_count {
	int			countmoves;
	int			countanim;
	int			counthero;
	int			countanim2;
	int			exitflag;
	int			checkflag;
}				t_count;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_coins {
	void		*coin1;
	void		*coin2;
	void		*coin3;
	void		*coin4;
	void		*coin5;
	void		*coin6;
}				t_coins;

typedef struct s_hero {
	void		*hero2;
	void		*hero3;
	void		*hero4;
}				t_hero;

typedef struct s_pics {
	t_hero		hero;
	t_coins		coins;
	void		*tree1;
	void		*grass;
	void		*wall;
	void		*cola;
	void		*player;
	void		*o_exit;
	void		*c_exit;
}				t_pics;

typedef struct s_game {
	t_map		map;
	t_player	players;
	t_count		count;
	t_mlx		mlx;
	t_pics		images;
	char		*num;
}				t_game;

int		ft_close(int keycode, t_game game);
void	ft_error(int i, t_game *game);
void	ft_free(t_game *game);
void	winning(t_game *game);
void	loosing(t_game *game);

int		game_line(t_game *game);
void	game_lenght(char *argv, t_game *game);
void	parser(char **argv, t_game *game);

int		key_hook(int keycode, t_game *game);
void	moveright(t_game *game);
void	moveleft(t_game *game);
void	moveup(t_game *game);
void	movedown(t_game *game);
void	keycode_d(t_game *game);
void	keycode_a(t_game *game);
void	keycode_w(t_game *game);
void	keycode_s(t_game *game);

void	getimage(t_game *game);
void	heropics(t_game *game);

int		render_next_frame(t_game *game);
void	mapdraw(t_game *game);
void	drawenemy(t_game *game, int	i, int i2);
void	drawexit(t_game *game, int	i, int i2);
void	animate_coins(t_game *game, int	i, int i2);
void	animate_heroright(t_game *game, int i, int i2);
void	animate_heroleft(t_game *game, int i, int i2);
void	animate_herodown(t_game *game, int i, int i2);
void	animate_heroup(t_game *game, int i, int i2);

int		get_next_line(int fd, char **line);
int		nl_check(char *str);
int		ft_strlen(const char *s);
int		ft_return(int charsread, char **line);
char	*strjoin_free(char *s1, char *s2);

#endif