#include "../includes/so_long.h"

void	moveright(t_game *game)
{
	if (game->map.map[game->players.p_y][game->players.p_x + 1] == 'E')
		winning(game);
	else if (game->map.map[game->players.p_y][game->players.p_x + 1] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->players.p_x + 1) * 50,
			game->players.p_y * 50);
	}
	else if (game->map.map[game->players.p_y][game->players.p_x + 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x + 1) * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->players.p_x + 1) * 50,
			game->players.p_y * 50);
	}
	ft_printf("Your moves - %d\n", game->count.countmoves += 1);
}

void	moveleft(t_game *game)
{
	if (game->map.map[game->players.p_y][game->players.p_x - 1] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->players.p_x - 1) * 50,
			game->players.p_y * 50);
	}
	if (game->map.map[game->players.p_y][game->players.p_x - 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x - 1) * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->players.p_x) * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->players.p_x - 1) * 50,
			game->players.p_y * 50);
	}
	if (game->map.map[game->players.p_y][game->players.p_x - 1] == 'E')
		winning(game);
	ft_printf("Your moves - %d\n", game->count.countmoves += 1);
}

void	moveup(t_game *game)
{
	if (game->map.map[game->players.p_y - 1][game->players.p_x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, game->players.p_x * 50,
			(game->players.p_y - 1) * 50);
	}
	else if (game->map.map[game->players.p_y - 1][game->players.p_x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * 50,
			(game->players.p_y - 1) * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player,
			game->players.p_x * 50, (game->players.p_y - 1) * 50);
	}
	else if (game->map.map[game->players.p_y - 1][game->players.p_x] == 'E')
		winning(game);
	ft_printf("Your moves - %d\n", game->count.countmoves += 1);
}

void	movedown(t_game *game)
{
	if (game->map.map[game->players.p_y + 1][game->players.p_x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->players.p_x * 50,
			game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, game->players.p_x * 50,
			(game->players.p_y + 1) * 50);
	}
	else if (game->map.map[game->players.p_y + 1][game->players.p_x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass,
			game->players.p_x * 50, (game->players.p_y + 1) * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass,
			game->players.p_x * 50, game->players.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player,
			game->players.p_x * 50, (game->players.p_y + 1) * 50);
	}
	else if (game->map.map[game->players.p_y + 1][game->players.p_x] == 'E')
		winning(game);
	ft_printf("Your moves - %d\n", game->count.countmoves += 1);
}

void	draw_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.grass,
		game->players.e_x * 50, game->players.e_y * 50);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.o_exit,
		game->players.e_x * 50, game->players.e_y * 50);
}
