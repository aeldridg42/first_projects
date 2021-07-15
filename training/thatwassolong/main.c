#include "includes/so_long.h"

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
	ft_printf("closing...\n");
	exit (0);
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
	ft_printf("You have LOST HA-HA\n");
	exit (0);
}

void	game_lenght(char *argv, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	game->map.lenght = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (get_next_line(fd, &line))
	{
		game->map.lenght++;
		free (line);
	}
	free (line);
	game->map.lenght += 2;
}

int	game_line(t_game *game)
{
	int	i;
	int	i2;
	int	count;
	int	count2;

	i = 0;
	i2 = -1;
	count = 0;
	while (game->map.map[i][++i2])
		count++;
	game->map.linesize = count;
	++i;
	while (game->map.map[i])
	{
		i2 = -1;
		count2 = 0;
		while (game->map.map[i][++i2])
			count2++;
		if (count != count2)
			ft_error();
		++i;
	}
	return (count);
}

void	parser(char **argv, t_game *game)
{
	char	*line;
	int		fd;
	int		i;
	int		check;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	check = 1;
	game_lenght(argv[1], game);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.lenght));
	if (!game->map.map)
		ft_error();
	while (check)
	{
		check = get_next_line(fd, &line);
		if (check == -1)
			ft_error();
		game->map.map[i++] = line;
	}
	game->map.map[i] = NULL;
	game_line(game);
}

void	moveright(t_game *game)
{
	if (game->map.map[game->player.p_y][game->player.p_x + 1] == 'E')
		winning(game);
	else if (game->map.map[game->player.p_y][game->player.p_x + 1] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->player.p_x) * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->player.p_x + 1) * 50,
			game->player.p_y * 50);
	}
	else if (game->map.map[game->player.p_y][game->player.p_x + 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->player.p_x) * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->player.p_x + 1) * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->player.p_x + 1) * 50,
			game->player.p_y * 50);
	}
	ft_printf("Your moves - %d\n", game->countmoves++);
}

void	moveleft(t_game *game)
{
	if (game->map.map[game->player.p_y][game->player.p_x - 1] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->player.p_x) * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->player.p_x - 1) * 50,
			game->player.p_y * 50);
	}
	if (game->map.map[game->player.p_y][game->player.p_x - 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->player.p_x - 1) * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, (game->player.p_x) * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, (game->player.p_x - 1) * 50,
			game->player.p_y * 50);
	}
	if (game->map.map[game->player.p_y][game->player.p_x - 1] == 'E')
		winning(game);
	ft_printf("Your moves - %d\n", game->countmoves++);
}

void	moveup(t_game *game)
{
	if (game->map.map[game->player.p_y - 1][game->player.p_x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->player.p_x * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, game->player.p_x * 50,
			(game->player.p_y - 1) * 50);
	}
	else if (game->map.map[game->player.p_y - 1][game->player.p_x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->player.p_x * 50,
			(game->player.p_y - 1) * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->player.p_x * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player,
			game->player.p_x * 50, (game->player.p_y - 1) * 50);
	}
	else if (game->map.map[game->player.p_y - 1][game->player.p_x] == 'E')
		winning(game);
	ft_printf("Your moves - %d\n", game->countmoves++);
}

void	movedown(t_game *game)
{
	if (game->map.map[game->player.p_y + 1][game->player.p_x] == '0')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, game->player.p_x * 50,
			game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, game->player.p_x * 50,
			(game->player.p_y + 1) * 50);
	}
	else if (game->map.map[game->player.p_y + 1][game->player.p_x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass,
			game->player.p_x * 50, (game->player.p_y + 1) * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass,
			game->player.p_x * 50, game->player.p_y * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player,
			game->player.p_x * 50, (game->player.p_y + 1) * 50);
	}
	else if (game->map.map[game->player.p_y + 1][game->player.p_x] == 'E')
		winning(game);
	ft_printf("Your moves - %d\n", game->countmoves++);
}

void	keycode_d(t_game *game)
{
	if (game->map.map[game->player.p_y][game->player.p_x + 1] == 'C')
	{
		moveright(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y][game->player.p_x + 1] = 'P';
		game->player.p_x += 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->player.p_y][game->player.p_x + 1] == '0')
	{
		moveright(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y][game->player.p_x + 1] = 'P';
		game->player.p_x += 1;
	}
	else if (game->map.map[game->player.p_y][game->player.p_x + 1] == 'W')
		loosing(game);
	else if (game->map.map[game->player.p_y][game->player.p_x + 1] == 'E')
		if (game->map.collectable == 0)
			moveright(game);
}

void	keycode_a(t_game *game)
{
	if (game->map.map[game->player.p_y][game->player.p_x - 1] == '0')
	{
		moveleft(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y][game->player.p_x - 1] = 'P';
		game->player.p_x -= 1;
	}
	else if (game->map.map[game->player.p_y][game->player.p_x - 1] == 'C')
	{
		moveleft(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y][game->player.p_x - 1] = 'P';
		game->player.p_x -= 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->player.p_y][game->player.p_x - 1] == 'W')
		loosing(game);
	else if (game->map.map[game->player.p_y][game->player.p_x - 1] == 'E')
		if (game->map.collectable == 0)
			moveleft(game);
}

void	keycode_s(t_game *game)
{
	if (game->map.map[game->player.p_y + 1][game->player.p_x] == '0')
	{
		movedown(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y + 1][game->player.p_x] = 'P';
		game->player.p_y += 1;
	}
	else if (game->map.map[game->player.p_y + 1][game->player.p_x] == 'C')
	{
		movedown(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y + 1][game->player.p_x] = 'P';
		game->player.p_y += 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->player.p_y + 1][game->player.p_x] == 'W')
		loosing(game);
	else if (game->map.map[game->player.p_y + 1][game->player.p_x] == 'E')
		if (game->map.collectable == 0)
			movedown(game);
}

void	keycode_w(t_game *game)
{
	if (game->map.map[game->player.p_y - 1][game->player.p_x] == '0')
	{
		moveup(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y - 1][game->player.p_x] = 'P';
		game->player.p_y -= 1;
	}
	else if (game->map.map[game->player.p_y - 1][game->player.p_x] == 'C')
	{
		moveup(game);
		game->map.map[game->player.p_y][game->player.p_x] = '0';
		game->map.map[game->player.p_y - 1][game->player.p_x] = 'P';
		game->player.p_y -= 1;
		game->map.collectable -= 1;
	}
	else if (game->map.map[game->player.p_y - 1][game->player.p_x] == 'W')
		loosing(game);
	else if (game->map.map[game->player.p_y - 1][game->player.p_x] == 'E')
		if (game->map.collectable == 0)
			moveup(game);
}

void	draw_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.grass,
		game->player.e_x * 50, game->player.e_y * 50);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.o_exit,
		game->player.e_x * 50, game->player.e_y * 50);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
		ft_free(game);
		ft_close(1, *game);
	}
	if (keycode == 2)
		keycode_d(game);
	if (keycode == 1)
		keycode_s(game);
	if (keycode == 0)
		keycode_a(game);
	if (keycode == 13)
		keycode_w(game);
	if (game->map.collectable == 0 && game->exitflag == 0)
	{
		game->exitflag = 1;
		draw_exit(game);
	}
	game->num = ft_itoa(game->countmoves);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.grass, 0, 0);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->images.tree, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.win, 0, 0, 0xFFFF, game->num);
	free (game->num);
	return (0);
}

void	getimage(t_game *game)
{
	int	width;
	int	height;

	game->images.grass = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/grass.xpm", &width, &height);
	game->images.col = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/carrot.xpm", &width, &height);
	game->images.o_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/openexit.xpm", &width, &height);
	game->images.c_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/closedexit.xpm", &width, &height);
	game->images.tree = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/bigtree.xpm", &width, &height);
	game->images.cola = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/cocacola.xpm", &width, &height);
	game->images.player = mlx_xpm_file_to_image(game->mlx.mlx,
			"images/heroright.xpm", &width, &height);
	if (!game->images.o_exit || !game->images.col || !game->images.grass
		|| !game->images.c_exit || !game->images.tree || !game->images.cola
		|| !game->images.player)
		ft_error();
}

void	gameinit(t_game *game)
{
	getimage(game);
	game->countmoves = 0;
	game->exitflag = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx, game->map.linesize * 50,
			(game->map.lenght - 1) * 50 - 15, "it took \"So long\"...");
}

void	draw1(t_game *game, int i, int i2)
{
	if (game->map.map[i][i2] == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.player, i2 * 50, i * 50);
		game->player.p_x = i2;
		game->player.p_y = i;
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
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.col, i2 * 50, i * 50);
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
		game->player.e_x = i2;
		game->player.e_y = i;
	}
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->images.grass, i2 * 50, i * 50);
}

void	mapdraw(t_game *game)
{
	int	i;
	int	i2;

	i = -1;
	game->map.collectable = 0;
	while (game->map.map[++i])
	{
		i2 = -1;
		while (game->map.map[i][++i2])
		{
			if (game->map.map[i][i2] == 'P' || game->map.map[i][i2] == '1')
				draw1(game, i, i2);
			else if (game->map.map[i][i2] == 'W' || game->map.map[i][i2] == 'C')
				draw2(game, i, i2);
			else if (game->map.map[i][i2] == 'E' || game->map.map[i][i2] == '0')
				draw3(game, i, i2);
		}
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error();
	parser(argv, &game);
	gameinit(&game);
	mapdraw(&game);
	mlx_string_put(game.mlx.mlx, game.mlx.win, 0, 0, 0xFFFF, "0");
	mlx_hook(game.mlx.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0, ft_close, &game);
	mlx_loop(game.mlx.mlx);
}
