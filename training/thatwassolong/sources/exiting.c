#include "../includes/so_long.h"

void	ft_error(int i, t_game *game)
{
	if (i == 1)
	{
		ft_printf("Image importing error\n");
		ft_free(game);
	}
	if (i == 2)
	{
		ft_printf("Invalid map\n");
		ft_free(game);
	}
	if (i == 3)
		ft_printf("File reading error\n");
	if (i == 4)
		ft_printf("Wrong number of arguments\n");
	if (i == 5)
	{
		ft_printf("You have malloc error! Congratulations!\n");
		ft_free(game);
	}
	if (i == 6)
		ft_printf("Wrong map format\n");
	if (i == 7)
		ft_printf("Map is too big\n");
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
	ft_printf("Closing...\n");
	exit (0);
	return (0);
}

void	winning(t_game *game)
{
	ft_free(game);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	ft_printf("You WON! It took %d moves!\n", game->count.countmoves + 1);
	exit (0);
}

void	loosing(t_game *game)
{
	ft_free(game);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	ft_printf("You LOST! It took %d moves! Such a shame...\n",
		game->count.countmoves + 1);
	exit (0);
}
