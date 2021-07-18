#include "../includes/so_long.h"

static void	animate_player(t_game *game, int i, int i2)
{
	if (game->players.heroflag == 2)
		animate_heroright(game, i, i2);
	if (game->players.heroflag == 1)
		animate_herodown(game, i, i2);
	if (game->players.heroflag == 3)
		animate_heroup(game, i, i2);
	if (game->players.heroflag == 0)
		animate_heroleft(game, i, i2);
}

static void	checkcounters(t_game *game)
{
	if (game->count.exitflag)
		game->count.exitflag += 1;
	game->count.countanim += 1;
	if (game->count.countanim == 8000)
		game->count.countanim = 0;
	game->count.countanim2 += 1;
	if (game->count.countanim2 == 5500)
		game->count.countanim2 = 0;
	game->count.counthero += 1;
	if (game->count.counthero == 6000)
		game->count.counthero = 0;
}

int	render_next_frame(t_game *game)
{
	int	i;
	int	i2;

	i = -1;
	while (game->map.map[++i])
	{
		i2 = -1;
		while (game->map.map[i][++i2])
		{
			if (game->map.map[i][i2] == 'C')
				animate_coins(game, i2, i);
			if (game->map.map[i][i2] == 'P')
				animate_player(game, i2, i);
			if (game->map.map[i][i2] == 'W')
				drawenemy(game, i2, i);
			if (game->map.map[i][i2] == 'E' && game->count.exitflag != 0
				&& game->count.exitflag < 7501)
				drawexit(game, i2, i);
		}
	}
	checkcounters(game);
	return (0);
}
