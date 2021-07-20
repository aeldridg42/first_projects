#include "../includes/so_long.h"

void	ft_error(int i, t_game *game)
{
	if (i == 1)
	{
		printf("Image importing error\n");
		ft_free(game);
	}
	if (i == 2)
	{
		printf("Invalid map\n");
		ft_free(game);
	}
	if (i == 3)
		printf("File reading error\n");
	if (i == 4)
		printf("Wrong number of arguments\n");
	if (i == 5)
	{
		printf("You have \"MALLOC\" error! Congratulations!\n");
		ft_free(game);
	}
	if (i == 6)
		printf("Wrong map format\n");
	if (i == 7)
		printf("Map is too big\n");
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
	// game.map.map[0][0] = '1';
	if (keycode == 53)
	{
		mlx_destroy_window(game.mlx.mlx, game.mlx.win);
		ft_free(&game);
	}
	printf("Closing...\n");
	exit (0);
	return (0);
}

void	winning(t_game *game)
{
	ft_free(game);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	printf("Your moves - %d\nYou WON!\n", game->count.countmoves + 1);
	exit (0);
}

void	loosing(t_game *game)
{
	ft_free(game);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	printf("Your moves - %d\nYou LOST! Such a shame...\n",
		game->count.countmoves + 1);
	exit (0);
}
