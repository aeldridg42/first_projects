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
	int	count;

	i = 0;
	game->map.linesize = ft_strlen(game->map.map[i]);
	while (game->map.map[++i])
	{
		count = ft_strlen(game->map.map[i]);
		if (game->map.linesize != count)
			ft_error(2, game);
	}
	return (count);
}
