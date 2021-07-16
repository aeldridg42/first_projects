#include "../includes/so_long.h"

// static void animate_coins1(t_game *game, int i, int i2)
// {

// }

int	render_next_frame(t_game *game)
{
	int i = 0;
	int i2 = 0;

	while(game->map.map[i])
	{
		i2 = 0;
		while(game->map.map[i][i2])
		{
			if(game->map.map[i][i2] == 'C' && game->count.countanim == 1)
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->images.grass, i2 * 50, i * 50);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->images.anim1, i2 * 50, i * 50);
			}
			// else if(game->map.map[i][i2] == 'W' && game->count.countanim == 1400)
			// {
			// 	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			// 		game->images.grass, i2 * 50, i * 50);
			// 	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			// 		game->images.anim2, i2 * 50, i * 50);
			// }
			else if(game->map.map[i][i2] == 'C' && game->count.countanim == 2800)
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->images.grass, i2 * 50, i * 50);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
					game->images.anim3, i2 * 50, i * 50);
			}
			// else if(game->map.map[i][i2] == 'W' && game->count.countanim == 4200)
			// {
			// 	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			// 		game->images.grass, i2 * 50, i * 50);
			// 	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			// 		game->images.anim4, i2 * 50, i * 50);
			// }
			i2++;
		}
		i++;
	}
	game->count.countanim++;
	if (game->count.countanim == 5600)
		game->count.countanim = 0;
	return (0);
}