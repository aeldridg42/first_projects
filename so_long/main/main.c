#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
//     void    *mlx.win;
//     char    *img_data;

// 	mlx = mlx_init();
// 	// img = mlx_new_image(mlx, 800, 600);
//     mlx.win = mlx_new_window(mlx, 1920, 1080, "check");
//     // img_data =  mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
//     mlx_loop(mlx);

// }

typedef struct	s_data {
	void	*img;
    void *img2;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void *mlx;
    void *win;
    int w;
    int h;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	key_hook(int keycode, t_data *img)
// {
//     if ((mlx_mouse_show()))
//         printf("Hello!\n");
// 	printf("Hello from key_hook!\n");
//     return (0);
// }

int	close(int keycode, t_data *img)
{
    printf("Key is - %d\n", keycode);
	if (keycode == 53) {
        mlx_destroy_window(img->mlx, img->win);
        exit (0);
    }
    if (keycode == 14)
        mlx_clear_window(img->mlx, img->win);
    return (0);
}

int	close2(int keycode, t_data *img)
{
    if (keycode)
        exit (0);
    return (0);    
}

// int	render_next_frame(void *YourStruct)
// {

// }

int	main(void)
{
	// void	*mlx;
	// void	*mlx.win;
	t_data	img;
    int i = 0;
    int i2 = 999;
    int i3 = 150;
    int d150 = 1000;
    int d1502 = 1000;
    int d0 = 0;
    int w = 500, h = 500;
    int tmp1, tmp2;
    int color = 0xFF00;
    char	*relative_path = "~/Downloads/check.xpm";

    // img.line_length = 5000;
    // img.bits_per_pixel = 300;
    // img.endian = 0;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "check");
    img.img = mlx_new_image(img.mlx, 800, 600);
    // if(!(img.img = mlx_xpm_file_to_image(img.mlx, relative_path, &img.w, &img.h))) {
    //     printf("error:(\n");
    //     exit (2);
    // }
    // mlx_png_file_to_image(img.mlx, "~/Downloads/check.xpm", &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, color);
    // while (i < 1000) {                    
    //     my_mlx_pixel_put(&img, i, 0, color);
    //     my_mlx_pixel_put(&img, i++, 1000, color);
    //     my_mlx_pixel_put(&img, 0, i2, color);
    //     my_mlx_pixel_put(&img, 1000, i2--, color);
    // }
    // break ;
        // color = 0xFF;
        // i = tmp1;
        // i2 = tmp2;
        // d0++;
        // d150--;
        // d1502--;
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    // mlx_key_hook(mlx.win, key_hook, &img);
    mlx_hook(img.win, 2, 1L<<0, close, &img);
    mlx_hook(img.win, 17, 0, close2, &img);
    // mlx_hook(img.win, 7, 1L<<4, close, &img);
    // mlx_mouse_hook (img.win, close, &img);
    // mlx_loop_hook(img.mlx, render_next_frame, img);
	mlx_loop(img.mlx);
    return 0;
}