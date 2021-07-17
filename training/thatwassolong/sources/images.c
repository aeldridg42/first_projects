#include "../includes/so_long.h"

static void	enemypics(t_game *game)
{
	int	width;
	int	height;

	game->players.anim.enemy1 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.1.xpm", &width, &height);
	game->players.anim.enemy2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.2.xpm", &width, &height);
	game->players.anim.enemy3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.3.xpm", &width, &height);
	game->players.anim.enemy4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.4.xpm", &width, &height);
	game->players.anim.enemy5 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.5.xpm", &width, &height);
	game->players.anim.enemy6 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.6.xpm", &width, &height);
	game->players.anim.enemy7 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.7.xpm", &width, &height);
	game->players.anim.enemy8 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.8.xpm", &width, &height);
}

static void	exitpics(t_game *game)
{
	int	width;
	int	height;

	game->players.anim.exit2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit2.xpm", &width, &height);
	game->players.anim.exit3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit3.xpm", &width, &height);
	game->players.anim.exit4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit4.xpm", &width, &height);
	game->players.anim.exit5 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit5.xpm", &width, &height);
	game->players.anim.exit6 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit6.xpm", &width, &height);
	game->players.anim.exit7 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit7.xpm", &width, &height);
	game->players.anim.exit8 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit8.xpm", &width, &height);
	game->players.anim.exit9 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit9.xpm", &width, &height);
	game->players.anim.exit10 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit10.xpm", &width, &height);
}

static void	getimage2(t_game *game)
{
	int	width;
	int	height;

	game->images.coins.coin2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/coin2.xpm", &width, &height);
	game->images.coins.coin3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/coin3.xpm", &width, &height);
	game->images.coins.coin4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/coin4.xpm", &width, &height);
	game->images.coins.coin5 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/coin5.xpm", &width, &height);
	game->images.tree1 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/tree.xpm", &width, &height);
	game->images.hero.hero2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player2.xpm", &width, &height);
	game->images.hero.hero3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player3.xpm", &width, &height);
	game->images.hero.hero4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player4.xpm", &width, &height);
}

static void	checkimage(t_game *game)
{
	if (!game->images.grass || !game->images.coins.coin1 || !game->images.o_exit
		|| !game->images.c_exit || !game->images.wall || !game->images.player
		|| !game->images.coins.coin2 || !game->images.coins.coin3
		|| !game->images.coins.coin4 || !game->images.coins.coin5
		|| !game->images.tree1 || !game->images.hero.hero2
		|| !game->images.hero.hero3 || !game->images.hero.hero4
		|| !game->players.anim.exit2 || !game->players.anim.exit3
		|| !game->players.anim.exit4 || !game->players.anim.exit5
		|| !game->players.anim.exit6 || !game->players.anim.exit7
		|| !game->players.anim.exit8 || !game->players.anim.exit9
		|| !game->players.anim.exit10 || !game->players.anim.enemy1
		|| !game->players.anim.enemy2 || !game->players.anim.enemy3
		|| !game->players.anim.enemy4 || !game->players.anim.enemy5
		|| !game->players.anim.enemy6 || !game->players.anim.enemy7
		|| !game->players.anim.enemy8)
	{
		ft_printf("Image reading Error\n");
		ft_free(game);
		exit(0);
	}
}

void	getimage(t_game *game)
{
	int	width;
	int	height;

	game->images.grass = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/grassnew.xpm", &width, &height);
	game->images.coins.coin1 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/coin1.xpm", &width, &height);
	game->images.o_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit11.xpm", &width, &height);
	game->images.c_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/exit1.xpm", &width, &height);
	game->images.wall = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/bigwall.xpm", &width, &height);
	game->images.player = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player1.xpm", &width, &height);
	getimage2(game);
	enemypics(game);
	exitpics(game);
	checkimage(game);
}
