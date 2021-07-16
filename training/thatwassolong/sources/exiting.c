#include "../includes/so_long.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (1);
}

void	ft_free(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		free (game->map.map[i]);
		++i;
	}
	free (game->map.map);
}

int	ft_close(int keycode, t_game game)
{
	game.map.map[0][0] = '1';
	if (keycode == 53)
	{
		mlx_destroy_window(game.mlx.mlx, game.mlx.win);
		ft_free(&game);
	}
	ft_printf("closing...\n");
	exit (0);
	return (0);
}

void	winning(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	ft_printf("You WON!\n");
	exit (0);
}

void	loosing(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	ft_printf("You have LOST! HA-HA\n");
	exit (0);
}
