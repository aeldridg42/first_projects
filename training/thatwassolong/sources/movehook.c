#include "../includes/so_long.h"

void	keycode_d(t_game *game)
{
	if (game->map.map[game->players.p_y][game->players.p_x + 1] == 'C')
	{
		moveright(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y][game->players.p_x + 1] = 'P';
		game->players.p_x += 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->players.p_y][game->players.p_x + 1] == '0')
	{
		moveright(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y][game->players.p_x + 1] = 'P';
		game->players.p_x += 1;
	}
	else if (game->map.map[game->players.p_y][game->players.p_x + 1] == 'W')
		loosing(game);
	else if (game->map.map[game->players.p_y][game->players.p_x + 1] == 'E')
		if (game->map.collectable == 0)
			moveright(game);
}

void	keycode_a(t_game *game)
{
	if (game->map.map[game->players.p_y][game->players.p_x - 1] == '0')
	{
		moveleft(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y][game->players.p_x - 1] = 'P';
		game->players.p_x -= 1;
	}
	else if (game->map.map[game->players.p_y][game->players.p_x - 1] == 'C')
	{
		moveleft(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y][game->players.p_x - 1] = 'P';
		game->players.p_x -= 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->players.p_y][game->players.p_x - 1] == 'W')
		loosing(game);
	else if (game->map.map[game->players.p_y][game->players.p_x - 1] == 'E')
		if (game->map.collectable == 0)
			moveleft(game);
}

void	keycode_s(t_game *game)
{
	if (game->map.map[game->players.p_y + 1][game->players.p_x] == '0')
	{
		movedown(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y + 1][game->players.p_x] = 'P';
		game->players.p_y += 1;
	}
	else if (game->map.map[game->players.p_y + 1][game->players.p_x] == 'C')
	{
		movedown(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y + 1][game->players.p_x] = 'P';
		game->players.p_y += 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->players.p_y + 1][game->players.p_x] == 'W')
		loosing(game);
	else if (game->map.map[game->players.p_y + 1][game->players.p_x] == 'E')
		if (game->map.collectable == 0)
			movedown(game);
}

void	keycode_w(t_game *game)
{
	if (game->map.map[game->players.p_y - 1][game->players.p_x] == '0')
	{
		moveup(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y - 1][game->players.p_x] = 'P';
		game->players.p_y -= 1;
	}
	else if (game->map.map[game->players.p_y - 1][game->players.p_x] == 'C')
	{
		moveup(game);
		game->map.map[game->players.p_y][game->players.p_x] = '0';
		game->map.map[game->players.p_y - 1][game->players.p_x] = 'P';
		game->players.p_y -= 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->players.p_y - 1][game->players.p_x] == 'W')
		loosing(game);
	else if (game->map.map[game->players.p_y - 1][game->players.p_x] == 'E')
		if (game->map.collectable == 0)
			moveup(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_close(53, *game);
	if (keycode == 2)
		keycode_d(game);
	if (keycode == 1)
		keycode_s(game);
	if (keycode == 0)
		keycode_a(game);
	if (keycode == 13)
		keycode_w(game);
	if (game->map.collectable == 0 && !game->count.exitflag)
		game->count.exitflag = 1;
	game->num = ft_itoa(game->count.countmoves);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.wall, 0 - 21, 0);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.wall, SCALE - 21, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.win, 0, 0, 0x00FF00, game->num);
	free (game->num);
	return (0);
}
