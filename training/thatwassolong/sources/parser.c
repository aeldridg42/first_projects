#include "../includes/so_long.h"

void	validletter(char i)
{
	if (i != '1' && i != '0' && i != 'E' && i != 'W' && i != 'P' && i != 'C')
		ft_error();
}

void	mapcheck1(t_game *game)
{
	int	i;
	int	i2;
	int	p;
	int	e;

	i = -1;
	p = 0;
	e = 0;
	while (game->map.map[++i])
	{
		i2 = -1;
		while (game->map.map[i][++i2])
		{
			validletter(game->map.map[i][i2]);
			if (game->map.map[i][i2] == 'P')
				++p;
			if (game->map.map[i][i2] == 'E')
				++e;
			if (e > 1 || p > 1)
				ft_error();
		}
	}
}

void	mapcheck2(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.map[0][++i])
		if (game->map.map[0][i] != '1')
			ft_error();
	i = -1;
	while (game->map.map[++i])
		if (game->map.map[i][0] != '1')
			ft_error();
	i = -1;
	while (game->map.map[game->map.lenght - 2][++i])
		if (game->map.map[game->map.lenght - 2][i] != '1')
			ft_error();
	i = -1;
	while (game->map.map[++i])
		if (game->map.map[i][game->map.linesize - 1] != '1')
			ft_error();
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
	mapcheck1(game);
	mapcheck2(game);
}
