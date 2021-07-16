#include "../includes/so_long.h"

static void	getimage2(t_game *game)
{
	int	width;
	int	height;

	game->images.anim1 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy1.xpm", &width, &height);
	game->images.anim2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy2.xpm", &width, &height);
	game->images.anim3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy3.xpm", &width, &height);
	game->images.anim4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/enemy4.xpm", &width, &height);
	if (!game->images.anim1 || !game->images.anim2 || !game->images.anim3
		|| !game->images.anim4)
		ft_error();
}

void	getimage(t_game *game)
{
	int	width;
	int	height;

	game->images.grass = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/grass.xpm", &width, &height);
	game->images.tomato = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/tomato.xpm", &width, &height);
	game->images.carrot = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/carrot.xpm", &width, &height);
	game->images.o_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/openexit.xpm", &width, &height);
	game->images.c_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/closedexit.xpm", &width, &height);
	game->images.tree = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/bigtree.xpm", &width, &height);
	game->images.cola = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/cocacola.xpm", &width, &height);
	game->images.player = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/heroright.xpm", &width, &height);
	if (!game->images.o_exit || !game->images.carrot || !game->images.grass
		|| !game->images.c_exit || !game->images.tree || !game->images.cola
		|| !game->images.player)
		ft_error();
}
