#include "../includes/so_long.h"

static void	animate_heroright1(t_game *game, int i, int i2)
{
	if (game->count.counthero == 2400 && game->players.heroflag == 2)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.hero.hero3, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.counthero == 3600 && game->players.heroflag == 2)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.hero.hero4, i * SCALE - 21, i2 * SCALE);
	}
}

void	animate_heroright(t_game *game, int i, int i2)
{
	if (game->count.counthero == 1 && game->players.heroflag == 2)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.counthero == 1200 && game->players.heroflag == 2)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.hero.hero2, i * SCALE - 21, i2 * SCALE);
	}
	else
		animate_heroright1(game, i, i2);
}

static void	animate_heroleft1(t_game *game, int i, int i2)
{
	if (game->count.counthero == 2400 && game->players.heroflag == 0)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroleft3, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.counthero == 3600 && game->players.heroflag == 0)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroleft4, i * SCALE - 21, i2 * SCALE);
	}
}

void	animate_heroleft(t_game *game, int i, int i2)
{
	if (game->count.counthero == 1 && game->players.heroflag == 0)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroleft1, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.counthero == 1200 && game->players.heroflag == 0)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroleft2, i * SCALE - 21, i2 * SCALE);
	}
	else
		animate_heroleft1(game, i, i2);
}
