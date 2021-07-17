#include "../includes/so_long.h"

static void	drawenemy3(t_game *game, int i, int i2)
{
	if (game->count.countanim == 6000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy7, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.countanim == 7000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy8, i * SCALE - 21, i2 * SCALE);
	}
}

static void	drawenemy2(t_game *game, int i, int i2)
{
	if (game->count.countanim == 3000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy4, i * SCALE - 21, i2 * SCALE);
	}
	if (game->count.countanim == 4000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy5, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.countanim == 5000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy6, i * SCALE - 21, i2 * SCALE);
	}
}

void	drawenemy(t_game *game, int i, int i2)
{
	if (game->count.countanim == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy1, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.countanim == 1000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy2, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.countanim == 2000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.enemy3, i * SCALE - 21, i2 * SCALE);
	}
	drawenemy2(game, i, i2);
	drawenemy3(game, i, i2);
}
