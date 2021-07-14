#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
// #include <mlx.h>

typedef struct s_player {
	int p_y;
    int p_x;
}				t_player;

typedef struct	s_data {
	void	*img;
	void	*img2;
	void	*img3;
	void    *mlx;
	void    *win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int     size1;
	int		size2;
	int		y;
	int		x;
	int		color;
	int		move1;
	int		move2;
	int 	size;
	int		x1;
	int 	x2;
	int width;
	int height;
	int ilnur;
	int linesize;
	int lenght;
	t_map map;
	t_player player;
}				t_data;

void check_lenght(char *argv, t_map *map)
{
    int i;
	char *line;

    i = 0;
	map->lenght = 0;
	int fd = open(argv, O_RDONLY);
    while(get_next_line(fd, &line))
    {
        map->lenght++;
        free(line);
    }
	free(line);
	map->lenght += 2;
	printf("!count2 = %d!\n", map->lenght);
}

int check_line(t_map *map)
{
	int i;
	int i2;
	int count;
	int count2;

	i = 0, i2 = 0, count = 0;
	while(map->map[i][i2]) {
			count++;
			i2++;
	}
	map->linesize = count;
	printf("!count = %d!\n", count);
	++i;
	while(map->map[i])
	{
		i2 = 0;
		count2 = 0;
		while(map->map[i][i2++])
			count2++;
		if (count != count2)
			return (-1);
		++i;
	}
	printf("!count123 = %d!\n", count);
	return (count);
}

int parser(char **argv, t_map *map)
{
    char *line;
    int fd;
    int i;
    int check;

    fd = open(argv[1], O_RDONLY);
    i = 0;
    check = 1;
	check_lenght(argv[1], map);
    map->map = (char **)malloc(sizeof(char *) * (map->lenght + 2));
    while(check)
    {
        check = get_next_line(fd, &line);
        if (check == -1)
            return (-1);
        map->map[i++] = line;
        // free(line);
    }
    map->map[i] = NULL;
	check_line(map);
    return 0;
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void moveright(t_data *check)
{
	mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x - 63, check->player.p_y);
	mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x, check->player.p_y);
}

void moveleft(t_data *check)
{
	mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x + 63, check->player.p_y);
	mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x, check->player.p_y);
}

void moveup(t_data *check)
{
	mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x, check->player.p_y + 63);
	mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x, check->player.p_y);
}

void movedown(t_data *check)
{
	mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x, check->player.p_y - 63);
	mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x, check->player.p_y);
}

int	key_hook(int keycode, t_data *check)
{
	printf("keycode is - %d!\n", keycode);
	if (keycode == 53)
	{
		printf("closing...\n");
		mlx_destroy_window(check->mlx, check->win);
		exit(0);
	}
	if (keycode == 2 && check->player.p_x < (check->linesize - 1) * 63)
	{
		if (check->map[check->player.p_y][check->player.p_x+1] != '1')
		check->player.p_x += 63;
		moveright(check);
		// check->color += 64000;
	}
	if (keycode == 1 && check->player.p_y < (check->lenght - 3) * 63)
	{
		// check->x += 640;
		// check->y += 640;
		// mlx_clear_window(check->mlx, check->win);
		check->player.p_y += 63;
		movedown(check);
		// check->color -= 1;
		// printf("!%d, %d!\n", check->x1, check->x2);
	}
	if (keycode == 0 && check->player.p_x > 1){
		check->player.p_x -= 63;
		moveleft(check);
	}
	if (keycode == 13 && check->player.p_y > 1){
		check->player.p_y -= 63;
		moveup(check);
	}	
	return(0);
}

int close123(int keycode, t_data *check)
{
	if (keycode)
	{
		printf("closing...\n");
		exit(0);
	}
	return(0);
}

int render(t_data *check)
{
	check->x = 640;
	int buff = check->x;
	check->y = 640;
	int i = 1;
	while(check->y++ < check->size)
	{
		check->x = buff;
		while(check->x++ < check->size)
			my_mlx_pixel_put(check, check->x, check->y, check->color);
		// check->color-=1;
	}
	mlx_put_image_to_window(check->mlx, check->win, check->img, check->x1, check->x2);
	return(0);
}

int render2(t_data *check)
{
	mlx_clear_window(check->mlx, check->win);
	int y = 300;
	int x = 300;
	int check13 = 0;
	if (check->x1 > 271 && check->x1 < 391 && check->x2 > 269 && check->x2 < 376){
		check->color = 0xff123456;
		check->ilnur = 1;
	}
	else 
		while(y++ < 400)
		{
			x = 300;
			while(x++ < 400)
				mlx_pixel_put(check->mlx, check->win, x, y, check->color);
		}
	// if (check->ilnur)
	// 	while(y++ < 600)
	// 		{
	// 			x = 300;
	// 			while(x++ < 600)
	// 				mlx_pixel_put(check->mlx, check->win, x, y, check->color);
	// 		}
	mlx_put_image_to_window(check->mlx, check->win, check->img, check->x1, check->x2);
	return (0);
}

void zarisovka(t_map *map, t_data *check)
{
	int i;
	int i2;
	i = 0;
	i2 = 0;
	while(map->map[i])
	{
		i2 = 0;
		while(map->map[i][i2]) {
			if (map->map[i][i2] == 'P'){
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 63, i * 63);
				mlx_put_image_to_window(check->mlx, check->win, check->img, i2 * 63, i * 63);
				check->player.p_x = i2 * 63;
				check->player.p_y = i * 63;
			}
			else if(map->map[i][i2] == '1'){
				mlx_put_image_to_window(check->mlx, check->win, check->img3, i2 * 64, i * 64);
			}
			else
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 63, i * 63);
			printf("%c ", map->map[i][i2]);
			i2++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data check;
	t_map map;
	check.size1 = 800;
	check.size2 = 600;
	check.size = 300;
	check.x1 = 0;
	check.x2 = 0;
	int x = 300;
	int y = 300;
	int width;
	int height;
	check.color = 0xFFFFFF;
	check.ilnur = 0;
	// check.x = 640;
	// check.y = 640;
	parser(argv, &map);
	int i = 0;
	while(map.map[i])
		printf("%s\n", map.map[i++]);
	check.linesize = map.linesize;
	check.lenght = map.lenght;
	check.mlx = mlx_init();
	printf("!!%d, %d,(%d, %d)!!\n", map.linesize * 63, (map.lenght-2) * 63, map.linesize, map.lenght - 2);
	check.win = mlx_new_window(check.mlx, map.linesize * 63, (map.lenght-2) * 63, "Check123");
	check.img2 = mlx_xpm_file_to_image(check.mlx, "grass.xpm", &check.width, &check.height);
	// mlx_string_put(check.mlx, check.win, 0, 0, 0xFF, "0");
	check.img = mlx_xpm_file_to_image(check.mlx, "13.xpm", &check.width, &check.height);
	check.img3 = mlx_xpm_file_to_image(check.mlx, "2.xpm", &check.width, &check.height);
	check.addr = mlx_get_data_addr(check.img, &check.bits_per_pixel, &check.line_length,
								&check.endian);
	// mlx_loop_hook(check.mlx, render, &check);
	// mlx_loop_hook(check.mlx, render2, &check);
	zarisovka(&map, &check);
	printf("%d, %d CHECK\n", check.player.p_x, check.player.p_y);
	mlx_hook(check.win, 2, (1L<<0), key_hook, &check);
	mlx_hook(check.win, 17, 0, close123, &check);
	// render2(&check);
	// mlx_put_image_to_window(check.mlx, check.win, check.img, 0, 0);
	mlx_loop(check.mlx);
	// int i = 0;
	// while(map.map[i])
	// 	printf("%s\n", map.map[i++]);
	
	return(0);
}