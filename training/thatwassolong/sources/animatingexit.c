#include "../includes/so_long.h"

static void	drawexit4(t_game *game, int i, int i2)
{
	if (game->count.exitflag == 6750)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit10, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.exitflag == 7500)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.o_exit, i * SCALE - 21, i2 * SCALE);
	}
}

static void	drawexit3(t_game *game, int i, int i2)
{
	if (game->count.exitflag == 4500)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit7, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.exitflag == 5250)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit8, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.exitflag == 6000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit9, i * SCALE - 21, i2 * SCALE);
	}
}

static void	drawexit2(t_game *game, int i, int i2)
{
	if (game->count.exitflag == 2250)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit4, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.exitflag == 3000)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit5, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.exitflag == 3750)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit6, i * SCALE - 21, i2 * SCALE);
	}
}

void	drawexit(t_game *game, int i, int i2)
{
	if (game->count.exitflag == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.c_exit, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.exitflag == 750)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit2, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.exitflag == 1500)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.exit3, i * SCALE - 21, i2 * SCALE);
	}
	drawexit2(game, i, i2);
	drawexit3(game, i, i2);
	drawexit4(game, i, i2);
}
