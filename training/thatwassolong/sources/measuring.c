#include "../includes/so_long.h"

void	game_lenght(char *argv, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	game->map.lenght = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error(3, game);
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
			ft_error(2, game);
		++i;
	}
	return (count);
}
