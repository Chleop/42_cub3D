#include "cub3d.h"

#define CEILING 0x00ffff
#define FLOOR   0x00ff00

int	redcross_exit(t_map *map)
{
	exit(0);
}

int	key_event(int keypress, t_map *map)
{
	if (keypress == ESC)
		exit(0);
	return (0);
}

int screen_display ()
{
    printf("ca fonctionne\n");
}

int main(void)
{
    void	*mlx_ptr;
	void	*win_ptr;
    int     win_nb_x;
    int     win_nb_y;
    int     x;
    int     y;

    win_nb_x = 800;
    win_nb_y = 600;
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_nb_x, win_nb_y, "cub3D");
    y = 0;
    while (y < win_nb_y / 2)
    {
        x = -1;
        while (++x < win_nb_x)
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, CEILING);
        y++;
    }
    while (y < win_nb_y)
    {
        x = -1;
        while (++x < win_nb_x)
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, FLOOR);
        y++;
    }
    mlx_loop_hook(mlx_ptr, &screen_display, NULL);
    mlx_hook(win_ptr, 2, 1L<<0, &key_event, NULL);
    mlx_hook(win_ptr, 17, 0, &redcross_exit, NULL);
    mlx_loop(mlx_ptr);
    return (0);
}