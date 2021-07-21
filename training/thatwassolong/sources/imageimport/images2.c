#include "../../includes/so_long.h"

static void	heropics1(t_game *game)
{
	int	width;
	int	height;

	game->players.anim.herodown3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/down3.xpm", &width, &height);
	game->players.anim.herodown4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/down4.xpm", &width, &height);
	game->players.anim.heroleft1 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/left1.xpm", &width, &height);
	game->players.anim.heroleft2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/left2.xpm", &width, &height);
	game->players.anim.heroleft3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/left3.xpm", &width, &height);
	game->players.anim.heroleft4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/left4.xpm", &width, &height);
}

void	heropics(t_game *game)
{
	int	width;
	int	height;

	game->players.anim.heroup1 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/up1.xpm", &width, &height);
	game->players.anim.heroup2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/up2.xpm", &width, &height);
	game->players.anim.heroup3 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/up3.xpm", &width, &height);
	game->players.anim.heroup4 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/up4.xpm", &width, &height);
	game->players.anim.herodown1 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/down1.xpm", &width, &height);
	game->players.anim.herodown2 = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/player/down2.xpm", &width, &height);
	heropics1(game);
}
