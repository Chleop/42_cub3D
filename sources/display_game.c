/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:32 by cproesch          #+#    #+#             */
/*   Updated: 2022/03/16 17:56:23 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_to_image(t_map *map)
{
	int	w;
	int	h;

	w = 45;
	h = 45;
	map->data->pic_back = mlx_xpm_file_to_image(map->data->mlx_ptr, PIC_BACK, &w, &h);
	map->data->pic_wall = mlx_xpm_file_to_image(map->data->mlx_ptr, PIC_WALL, &w, &h);
	// map->data->pic_exit = mlx_xpm_file_to_image(map->data->mlx_ptr, PIC_EXIT, w, h);
	// if (!map->data->pic_exit)
	// 	error_message("Error\nMlx_xpm_file_to_image exit failed\n", data);
	// map->data->pic_coll = mlx_xpm_file_to_image(map->data->mlx_ptr, PIC_COLL, w, h);
	// if (!map->data->pic_coll)
	// 	error_message("Error\nMlx_xpm_file_to_image coll failed\n", data);
	// map->data->pic_player = mlx_xpm_file_to_image(map->data->mlx_ptr, PIC_PLAYER, w, h);
	// if (!map->data->pic_player)
	// 	error_message("Error\nMlx_xpm_file_to_image player failed\n", data);
}

void	rotate_right(t_map *map)
{
	double	oldDirX;
	double	rotSpeed;

	oldDirX = map->player->view_dir_X;
	rotSpeed = 0.02;
	map->player->view_dir_X = map->player->view_dir_X * cos(-rotSpeed) - map->player->view_dir_Y * sin(-rotSpeed);
    map->player->view_dir_Y = oldDirX * sin(-rotSpeed) + map->player->view_dir_Y * cos(-rotSpeed);
}

int	key_event(int keypress, t_map *map)
{
	printf("keypress = %d\n", keypress);
	if (keypress == ESC)
		free_and_exit(map, 0);
	if (keypress == W)
	{
		map->player->player_pos_Y = map->player->player_pos_Y - 1;
		map->player->view_dir_Y = map->player->view_dir_Y -1;
	}
	if (keypress == A)
	{
		map->player->player_pos_X = map->player->player_pos_X - 1 ;
		map->player->view_dir_X = map->player->view_dir_X -1;
	}
	if (keypress == S)
	{
		map->player->player_pos_Y = map->player->player_pos_Y + 1;
		map->player->view_dir_Y = map->player->view_dir_Y + 1;
	}
	if (keypress == D)
	{
		map->player->player_pos_X = map->player->player_pos_X + 1;
		map->player->view_dir_X = map->player->view_dir_X + 1;
	}
	if (keypress == RIGHT)
		rotate_right(map);
	// if (keypress == LEFT)
	// 	rotate_left(map);

	return (0);
}

int	redcross_exit(t_map *map)
{
	free_and_exit(map, 0);
	return (1);
}

int	player_funct(t_map *map)
{
	int	x;
	int y;
	char	code;
	void	*mlx;
	void	*win;

	mlx = map->data->mlx_ptr;
	win = map->data->win_ptr;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			code = map->map[y][x];
			if (code == '0')
				mlx_put_image_to_window(mlx, win, map->data->pic_back, x * 60, y * 60);
			if (code == '1')
				mlx_put_image_to_window(mlx, win, map->data->pic_wall, x * 60, y * 60);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < 20)
	{
		x = 0;
		while (x < 20)
		{
			mlx_pixel_put(map->data->mlx_ptr, map->data->win_ptr, map->player->player_pos_X * 10 + x, map->player->player_pos_Y * 10 + y, 0xFF0000);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < 20)
	{
		x = 0;
		while (x < 20)
		{
			mlx_pixel_put(map->data->mlx_ptr, map->data->win_ptr, map->player->view_dir_X * 10 + x, map->player->view_dir_Y * 10 + y, 0xFF0000);
			x++;
		}
		y++;
	}
	return (0);
}

void	display_game(t_map *map)
{
	file_to_image(map);
	mlx_loop_hook(map->data->mlx_ptr, &player_funct, map);
	mlx_hook(map->data->win_ptr, 2, 1L<<0, &key_event, map);
	mlx_hook(map->data->win_ptr, 17, 0, &redcross_exit, map);
	mlx_loop(map->data->mlx_ptr);
}

// int	key_event(int keypress, t_map *map)
// {
// 	if (keypress == ESC)
// 		free_and_exit(map, 0);
// 	// if (keypress == W)
// 	// 	map->player->player_pos_X = map->player->player_pos_Y - 1;
// 	// if (keypress == A)
// 	// 	map->player->player_pos_X = map->player->player_pos_X - 1 ;
// 	// if (keypress == S)
// 	// 	map->player->player_pos_X = map->player->player_pos_Y + 1;
// 	// if (keypress == D)
// 	// 	map->player->player_pos_X = map->player->player_pos_X + 1;
// 	return (0);
// }

// int	redcross_exit(t_map *map)
// {
// 	free_and_exit(map, 0);
// 	return (1);
// }

// int	player_funct(t_map *map)
// {
// 	int	i;
// 	int j;

// 	j = 0;
// 	while (j < 20)
// 	{
// 		i = 0;
// 		while (i < 20)
// 		{
// 			mlx_pixel_put(map->data->mlx_ptr, map->data->win_ptr, (int)map->player->player_pos_X * 100 + i, (int)map->player->player_pos_Y * 100 + j, 0xFF0000);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (0);
// }
