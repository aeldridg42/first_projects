#include "includes/so_long.h"

static void	gameinit(t_game *game)
{
	getimage(game);
	game->count.countmoves = 0;
	game->map.collectable = 0;
	game->count.countanim = 0;
	game->count.countanim2 = 0;
	game->count.exitflag = 0;
	game->count.checkflag = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx,
			game->map.linesize * SCALE - 42,
			(game->map.lenght - 1) * SCALE2,
			"it took \"So long\" to understand how mlx works");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error();
	parser(argv, &game);
	gameinit(&game);
	mapdraw(&game);
	mlx_string_put(game.mlx.mlx, game.mlx.win, 0, 0, 0x00FF00, "0");
	mlx_hook(game.mlx.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0, ft_close, &game);
	mlx_loop_hook(game.mlx.mlx, render_next_frame, &game);
	mlx_loop(game.mlx.mlx);
}
