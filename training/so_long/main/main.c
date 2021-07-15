#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
// #include <mlx.h>

typedef struct s_player {
	int p_y;
    int p_x;
	int e_y;
	int e_x;
}				t_player;

typedef struct	s_data {
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*pleft;
	void	*exit2;
	void	*spaceimg;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
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
	int countmoves;
	t_map map;
	t_player player;
}				t_data;

void check_lenght(char *argv, t_data *check)
{
    int i;
	char *line;

    i = 0;
	check->map.lenght = 0;
	int fd = open(argv, O_RDONLY);
    while(get_next_line(fd, &line))
    {
        check->map.lenght++;
        free(line);
    }
	free(line);
	check->map.lenght += 2;
	printf("!count2 = %d!\n", check->map.lenght);
}

int check_line(t_data *check)
{
	int i;
	int i2;
	int count;
	int count2;

	i = 0, i2 = 0, count = 0;
	while(check->map.map[i][i2]) {
			count++;
			i2++;
	}
	check->map.linesize = count;
	printf("!count = %d!\n", count);
	++i;
	while(check->map.map[i])
	{
		i2 = -1;
		count2 = 0;
		while(check->map.map[i][++i2])
			count2++;
		if (count != count2)
		{
			printf("Wrong size map! Error\n");
			exit (0);	
		}
		++i;
	}
	printf("!count123 = %d!\n", count);
	return (count);
}

// void check_map(t_data *check)
// {
// 	int player;
// 	int exitcount;
// 	int col_count;
// 	int i;
// 	int i2;

// 	player = 0, exitcount = 0, col_count = 0, i = 0, i2 = 0;
// 	while(check->map.map[i])
// 	{
// 		i2 = 0;
// 		while(check->map.map[i][i2])
// 		{
// 			if(check->map.map[i][i2] == 'P')
// 				player++;
// 			if(check->map.map[i][i2] == 'E')
// 				exitcount++;
// 			if(check->map.map[i][i2] == 'C')
// 				col_count++;
// 			i2++;
// 		}
// 		i++;
// 	}
// 	i = 0, i2 = 0;
// 	while(check->map.map[0][i2] == 1 && check->map.map[0][i2])
// 		i2++;
// 	if(check->map.map[0][i2] != '\0')
// 	{
// 		printf("Map Error!");
// 		exit (0);
// 	}
// 	while(check->map.map[check->map.lenght][i] == 1 && check->map.map[check->map.lenght])
// 		i++;
// 	if(check->map.map[check->map.lenght][i] != '\0')
// 	{
// 		printf("Map Error!");
// 		exit (0);
// 	}
// }

int parser(char **argv, t_data *check)
{
    char *line;
    int fd;
    int i;
    int check1;

    fd = open(argv[1], O_RDONLY);
    i = 0;
    check1 = 1;
	check_lenght(argv[1], check);
    check->map.map = (char **)malloc(sizeof(char *) * (check->map.lenght + 2));
    while(check1)
    {
        check1 = get_next_line(fd, &line);
        if (check1 == -1)
            return (-1);
        check->map.map[i++] = line;
        // free(line);
    }
    check->map.map[i] = NULL;
	check_line(check);
	// check_map(check);
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
	if (check->map.map[check->player.p_y][check->player.p_x+1] == 'E')
	{
		printf("You WON!\n");
		exit (0);
	}
	else if (check->map.map[check->player.p_y][check->player.p_x+1] == '0'){
		mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.p_x) * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img, (check->player.p_x+1) * 50, check->player.p_y * 50);
	}
	else if (check->map.map[check->player.p_y][check->player.p_x+1] == 'C'){
		mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.p_x) * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.p_x+1) * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img, (check->player.p_x+1) * 50, check->player.p_y * 50);
	}
	else{
		mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.p_x-1) * 50, check->player.p_y * 50);
	}
	printf("Your moves - %d\n", check->countmoves+=1);
}

void moveleft(t_data *check)
{
	if (check->map.map[check->player.p_y][check->player.p_x-1] == '0'){
		mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.p_x) * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->pleft, (check->player.p_x-1) * 50, check->player.p_y * 50);
		// mlx_string_put(check.mlx, check.win, 0, 0, 0xFF, "0");
		printf("Your moves - %d\n", check->countmoves+=1);
	}
	if (check->map.map[check->player.p_y][check->player.p_x-1] == 'C'){
		mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.p_x-1) * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.p_x) * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->pleft, (check->player.p_x-1) * 50, check->player.p_y * 50);
	}
	if (check->map.map[check->player.p_y][check->player.p_x-1] == 'E')
	{
		printf("You WON!\n");
		exit (0);
	}
}

void moveup(t_data *check)
{
	if (check->map.map[check->player.p_y-1][check->player.p_x] == '0'){
		mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x * 50, (check->player.p_y-1) * 50);
	}
	else if (check->map.map[check->player.p_y-1][check->player.p_x] == 'C'){
		mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x * 50, (check->player.p_y-1) * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x * 50, check->player.p_y * 50);
		mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x * 50, (check->player.p_y-1) * 50);
	}
	else if (check->map.map[check->player.p_y-1][check->player.p_x] == 'E')
	{
		printf("You WON!\n");
		exit (0);
	}
	printf("Your moves - %d\n", check->countmoves+=1);
}

void movedown(t_data *check)
{
	if (check->map.map[check->player.p_y+1][check->player.p_x] != '1')
	{
		if (check->map.map[check->player.p_y+1][check->player.p_x] == '0')
		{
			mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x * 50, check->player.p_y * 50);
			mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x * 50, (check->player.p_y+1) * 50);
		}
		else if (check->map.map[check->player.p_y+1][check->player.p_x] == 'C')
		{
			mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x * 50, (check->player.p_y+1) * 50);
			mlx_put_image_to_window(check->mlx, check->win, check->img2, check->player.p_x * 50, check->player.p_y * 50);
			mlx_put_image_to_window(check->mlx, check->win, check->img, check->player.p_x * 50, (check->player.p_y+1) * 50);
		}
		else if (check->map.map[check->player.p_y+1][check->player.p_x] == 'E')
		{
			printf("You WON!\n");
			exit (0);
		}
		printf("Your moves - %d\n", check->countmoves+=1);
	}
}

void keycode_d(t_data *check)
{
	if (check->map.map[check->player.p_y][check->player.p_x + 1] == 'E')
	{
		if(check->map.collectable == 0)
		moveright(check);
	}
	else if (check->map.map[check->player.p_y][check->player.p_x + 1] == 'C')
	{
		moveright(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y][check->player.p_x + 1] = 'P';
		check->player.p_x += 1;
		check->map.collectable -= 1;
	}
	else if (check->map.map[check->player.p_y][check->player.p_x + 1] == '0'){
		moveright(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y][check->player.p_x + 1] = 'P';
		check->player.p_x += 1;
	}
}

void keycode_a(t_data *check)
{
	if (check->map.map[check->player.p_y][check->player.p_x - 1] == '0')
	{
		moveleft(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y][check->player.p_x - 1] = 'P';
		check->player.p_x -= 1;
	}
	else if (check->map.map[check->player.p_y][check->player.p_x - 1] == 'C')
	{
		moveleft(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y][check->player.p_x - 1] = 'P';
		check->player.p_x -= 1;
		check->map.collectable -= 1;
	}
	else if (check->map.map[check->player.p_y][check->player.p_x - 1] == 'E'){
		if(check->map.collectable == 0)
			moveleft(check);
	}
}

void keycode_s(t_data *check)
{
	if (check->map.map[check->player.p_y+1][check->player.p_x] == '0')
	{
		movedown(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y+1][check->player.p_x] = 'P';
		check->player.p_y += 1;
	}
	else if (check->map.map[check->player.p_y+1][check->player.p_x] == 'C')
	{
		movedown(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y+1][check->player.p_x] = 'P';
		check->player.p_y += 1;
		check->map.collectable -= 1;
	}
	else if (check->map.map[check->player.p_y+1][check->player.p_x] == 'E')
		if (check->map.collectable == 0)
			movedown(check);
	
}

void keycode_w(t_data *check)
{
	if(check->map.map[check->player.p_y - 1][check->player.p_x] == '0')
	{
		moveup(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y-1][check->player.p_x] = 'P';
		check->player.p_y -= 1;
	}
	else if(check->map.map[check->player.p_y - 1][check->player.p_x] == 'C')
	{
		moveup(check);
		check->map.map[check->player.p_y][check->player.p_x] = '0';
		check->map.map[check->player.p_y-1][check->player.p_x] = 'P';
		check->player.p_y -= 1;
		check->map.collectable -= 1;
	}
	else if (check->map.map[check->player.p_y-1][check->player.p_x] == 'E'){
		if (check->map.collectable == 0)
			moveup(check);
	}else if (check->map.map[check->player.p_y-1][check->player.p_x] == 'W')
	{
		printf("YOU LOST! HA-HA\n");
		exit (0);
	}
	
}

void draw_exit(t_data *check)
{
	mlx_put_image_to_window(check->mlx, check->win, check->img2, (check->player.e_x) * 50, check->player.e_y * 50);
	mlx_put_image_to_window(check->mlx, check->win, check->exit2, (check->player.e_x) * 50, check->player.e_y * 50);
}

int	key_hook(int keycode, t_data *check)
{
	int i;

	i = 0;
	if (keycode == 53)
	{
		printf("closing...\n");
		mlx_destroy_window(check->mlx, check->win);
		exit(0);
	}
	if (keycode == 2)
		keycode_d(check);
	if (keycode == 1)
		keycode_s(check);
	if (keycode == 0)
		keycode_a(check);
	if (keycode == 13)
		keycode_w(check);
	if (check->map.collectable == 0 && i == 0)
	{
		i = 1;
		draw_exit(check);
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

// int render(t_data *check)
// {
// 	while(check->map.collectable)
// 		mlx_put_image_to_window(check->mlx, check->win, check->img2, 0, 0);
// 		mlx_put_image_to_window(check->mlx, check->win, check->enemy1,  0, 0);
// 		mlx_put_image_to_window(check->mlx, check->win, check->img2, 0, 0);
// 		mlx_put_image_to_window(check->mlx, check->win, check->enemy2,  0, 0);
// 		mlx_put_image_to_window(check->mlx, check->win, check->img2,  0, 0);
// 		mlx_put_image_to_window(check->mlx, check->win, check->enemy3, 0, 0);
// 		mlx_put_image_to_window(check->mlx, check->win, check->img2,  0, 0);
// 		mlx_put_image_to_window(check->mlx, check->win, check->enemy4, 0, 0);
// 	return(0);
// }

// int render2(t_data *check)
// {
// 	mlx_clear_window(check->mlx, check->win);
// 	int y = 300;
// 	int x = 300;
// 	int check13 = 0;
// 	if (check->x1 > 271 && check->x1 < 391 && check->x2 > 269 && check->x2 < 376){
// 		check->color = 0xff123456;
// 		check->ilnur = 1;
// 	}
// 	else 
// 		while(y++ < 400)
// 		{
// 			x = 300;
// 			while(x++ < 400)
// 				mlx_pixel_put(check->mlx, check->win, x, y, check->color);
// 		}
// 	// if (check->ilnur)
// 	// 	while(y++ < 600)
// 	// 		{
// 	// 			x = 300;
// 	// 			while(x++ < 600)
// 	// 				mlx_pixel_put(check->mlx, check->win, x, y, check->color);
// 	// 		}
// 	mlx_put_image_to_window(check->mlx, check->win, check->img, check->x1, check->x2);
// 	return (0);
// }

void zarisovka(t_map *map, t_data *check)
{
	int i;
	int i2;
	i = 0;
	i2 = 0;
	check->map.collectable = 0;
	while(check->map.map[i])
	{
		i2 = 0;
		while(check->map.map[i][i2]) {
			if (check->map.map[i][i2] == 'P'){
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 50, i * 50);
				mlx_put_image_to_window(check->mlx, check->win, check->img, i2 * 50, i * 50);
				check->player.p_x = i2;
				check->player.p_y = i;
			}
			else if(check->map.map[i][i2] == '1'){
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 50, i * 50);
				mlx_put_image_to_window(check->mlx, check->win, check->img3, i2 * 50, i * 50);
			}
			else if(check->map.map[i][i2] == 'W'){
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 50, i * 50);
				mlx_put_image_to_window(check->mlx, check->win, check->enemy1, i2 * 50, i * 50);
			}
			else if(check->map.map[i][i2] == 'C'){
				check->map.collectable += 1;
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 50, i * 50);
				mlx_put_image_to_window(check->mlx, check->win, check->img4, i2 * 50, i * 50);
			}
			else if(check->map.map[i][i2] == 'E'){
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 50, i * 50);
				mlx_put_image_to_window(check->mlx, check->win, check->spaceimg, i2 * 50, i * 50);
				check->player.e_x = i2;
				check->player.e_y = i;
			}
			else
				mlx_put_image_to_window(check->mlx, check->win, check->img2, i2 * 50, i * 50);
			printf("%c ", check->map.map[i][i2]);
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
	check.countmoves = 0;
	// check.x = 500;
	// check.y = 500;
	parser(argv, &check);
	// int i = 0;
	// while(check.map.map[i])
	// 	printf("%s\n", check.map.map[i++]);
	// check.linesize = map.linesize;
	// check.lenght = map.lenght;
	check.mlx = mlx_init();
	// printf("!!%d, %d,(%d, %d)!!\n", map.linesize * 50, (map.lenght-2) * 50, map.linesize, map.lenght - 2);
	check.win = mlx_new_window(check.mlx, check.map.linesize * 50, (check.map.lenght-1) * 50 -15, "Check123");
	check.img2 = mlx_xpm_file_to_image(check.mlx, "grass.xpm", &check.width, &check.height);
	check.img = mlx_xpm_file_to_image(check.mlx, "fotki/heroright.xpm", &check.width, &check.height);
	check.img3 = mlx_xpm_file_to_image(check.mlx, "fotki/bigtree.xpm", &check.width, &check.height);
	check.img4 = mlx_xpm_file_to_image(check.mlx, "fotki/carrot.xpm", &check.width, &check.height);
	check.exit2 = mlx_xpm_file_to_image(check.mlx, "fotki/openexit.xpm", &check.width, &check.height);
	check.spaceimg = mlx_xpm_file_to_image(check.mlx, "fotki/closedexit.xpm", &check.width, &check.height);
	check.pleft = mlx_xpm_file_to_image(check.mlx, "fotki/heroleft.xpm", &check.width, &check.height);
	check.enemy1 = mlx_xpm_file_to_image(check.mlx, "fotki/cocacola.xpm", &check.width, &check.height);
	// check.enemy2 = mlx_xpm_file_to_image(check.mlx, "fotki/enemy2.xpm", &check.width, &check.height);
	// check.enemy3 = mlx_xpm_file_to_image(check.mlx, "fotki/enemy3.xpm", &check.width, &check.height);
	// check.enemy4 = mlx_xpm_file_to_image(check.mlx, "fotki/enemy4.xpm", &check.width, &check.height);
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