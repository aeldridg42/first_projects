#include "../includes/so_long.h"

static void	animate_player2(t_game *game, int i, int i2)
{
	if (game->count.countanim == 2400)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.hero.hero3, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.countanim == 3600)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.hero.hero4, i * SCALE - 21, i2 * SCALE);
	}
}

static void	animate_player(t_game *game, int i, int i2)
{
	if (game->count.countanim == 1)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, i * SCALE - 21, i2 * SCALE);
	}
	else if (game->count.countanim == 1200)
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i * SCALE - 21, i2 * SCALE);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.hero.hero2, i * SCALE - 21, i2 * SCALE);
	}
	animate_player2(game, i, i2);
}

void	checkcounters(t_game *game)
{
	if (game->count.exitflag)
		game->count.exitflag += 1;
	game->count.countanim += 1;
	if (game->count.countanim == 8000)
		game->count.countanim = 0;
	game->count.countanim2 += 1;
	if (game->count.countanim2 == 5500)
		game->count.countanim2 = 0;
}

int	render_next_frame(t_game *game)
{
	int	i;
	int	i2;

	i = -1;
	while (game->map.map[++i])
	{
		i2 = -1;
		while (game->map.map[i][++i2])
		{
			if (game->map.map[i][i2] == 'C')
				animate_coins(game, i2, i);
			if (game->map.map[i][i2] == 'P')
				animate_player(game, i2, i);
			if (game->map.map[i][i2] == 'W')
				drawenemy(game, i2, i);
			if (game->map.map[i][i2] == 'E' && game->count.exitflag != 0
				&& game->count.exitflag < 7501)
				drawexit(game, i2, i);
		}
	}
	checkcounters(game);
	return (0);
}
