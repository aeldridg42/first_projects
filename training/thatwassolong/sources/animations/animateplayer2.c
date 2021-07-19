#include "../includes/so_long.h"

static void	animate_herodown1(t_game *game, int i, int i2)
{
	if (game->count.counthero == 2400 && game->players.heroflag == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.herodown3, i * SCALE - HALF, i2 * SCALE);
	}
	else if (game->count.counthero == 3600 && game->players.heroflag == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.herodown4, i * SCALE - HALF, i2 * SCALE);
	}
}

void	animate_herodown(t_game *game, int i, int i2)
{
	if (game->count.counthero == 1 && game->players.heroflag == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.herodown1, i * SCALE - HALF, i2 * SCALE);
	}
	else if (game->count.counthero == 1200 && game->players.heroflag == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.herodown1, i * SCALE - HALF, i2 * SCALE);
	}
	else
		animate_herodown1(game, i, i2);
}

static void	animate_heroup1(t_game *game, int i, int i2)
{
	if (game->count.counthero == 2400 && game->players.heroflag == 3)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroup3, i * SCALE - HALF, i2 * SCALE);
	}
	else if (game->count.counthero == 3600 && game->players.heroflag == 3)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroup4, i * SCALE - HALF, i2 * SCALE);
	}
}

void	animate_heroup(t_game *game, int i, int i2)
{
	if (game->count.counthero == 1 && game->players.heroflag == 3)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroup1, i * SCALE - HALF, i2 * SCALE);
	}
	else if (game->count.counthero == 1200 && game->players.heroflag == 3)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - HALF, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->players.anim.heroup2, i * SCALE - HALF, i2 * SCALE);
	}
	else
		animate_heroup1(game, i, i2);
}
