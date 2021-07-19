#include "../includes/so_long.h"

static int	validletter(char i)
{
	if (i != '1' && i != '0' && i != 'E' && i != 'W' && i != 'P' && i != 'C')
		return (1);
	if (i == 'C')
		return (2);
	return (0);
}

static void	mapcheck1(t_game *game)
{
	int	i;
	int	i2;
	int	playercount;
	int	exitcount;

	i = -1;
	playercount = 0;
	exitcount = 0;
	while (game->map.map[++i])
	{
		i2 = -1;
		while (game->map.map[i][++i2])
		{
			if (validletter(game->map.map[i][i2]) == 1)
				ft_error(2, game);
			if (validletter(game->map.map[i][i2]) == 2)
				game->map.collectable += 1;
			if (game->map.map[i][i2] == 'P')
				++playercount;
			if (game->map.map[i][i2] == 'E')
				++exitcount;
			if (exitcount > 1 || playercount > 1)
				ft_error(2, game);
		}
	}
}

static void	mapcheck2(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.map[0][++i])
		if (game->map.map[0][i] != '1')
			ft_error(2, game);
	i = -1;
	while (game->map.map[++i])
		if (game->map.map[i][0] != '1')
			ft_error(2, game);
	i = -1;
	while (game->map.map[game->map.lenght - 2][++i])
		if (game->map.map[game->map.lenght - 2][i] != '1')
			ft_error(2, game);
	i = -1;
	while (game->map.map[++i])
		if (game->map.map[i][game->map.linesize - 1] != '1')
			ft_error(2, game);
	if (game->map.collectable == 0)
		ft_error(2, game);
	if (game->map.linesize > 62 || game->map.lenght > 34)
		ft_error(7, game);
}

void	parser(char **argv, t_game *game)
{
	char	*line;
	int		fd;
	int		i;
	int		check;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(3, game);
	i = 0;
	check = 1;
	game_lenght(argv[1], game);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.lenght));
	if (!game->map.map)
		ft_error(5, game);
	while (check)
	{
		check = get_next_line(fd, &line);
		if (check == -1)
			ft_error(5, game);
		game->map.map[i++] = line;
	}
	game->map.map[i] = NULL;
	game_line(game);
	mapcheck1(game);
	mapcheck2(game);
}
