#include "../includes/so_long.h"

void	draw1(t_game *game, int i, int i2)
{
	if (game->map.map[i][i2] == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, i2 * 50, i * 50);
		game->players.p_x = i2;
		game->players.p_y = i;
	}
	else if (game->map.map[i][i2] == '1')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.tree, i2 * 50, i * 50);
	}
}

void	draw2(t_game *game, int i, int i2)
{
	if (game->map.map[i][i2] == 'W')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.cola, i2 * 50, i * 50);
	}
	else if (game->map.map[i][i2] == 'C')
	{
		game->map.collectable += 1;
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
		if (i2 % 2 == 1)
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
				game->images.tomato, i2 * 50, i * 50);
		else
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
				game->images.carrot, i2 * 50, i * 50);
	}
}

void	draw3(t_game *game, int i, int i2)
{
	if (game->map.map[i][i2] == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.c_exit, i2 * 50, i * 50);
		game->players.e_x = i2;
		game->players.e_y = i;
	}
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
}

void	mapdraw(t_game *game)
{
	int	i;
	int	i2;
	int	c;

	i = -1;
	c = 0;
	while (game->map.map[++i])
	{
		i2 = -1;
		while (game->map.map[i][++i2])
		{
			if (game->map.map[i][i2] == 'P' || game->map.map[i][i2] == '1')
				draw1(game, i, i2);
			else if (game->map.map[i][i2] == 'W' || game->map.map[i][i2] == 'C')
			{
				if (game->map.map[i][i2] == 'C')
					++c;
				draw2(game, i, i2);
			}
			else if (game->map.map[i][i2] == 'E' || game->map.map[i][i2] == '0')
				draw3(game, i, i2);
		}
	}
	if (c == 0)
		ft_error();
}
