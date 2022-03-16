/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:32 by cproesch          #+#    #+#             */
/*   Updated: 2022/03/16 15:55:51 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	key_event(int keypress, t_map *map)
{
	if (keypress == ESC)
		free_and_exit(map, 0);
	return (0);
}

int	redcross_exit(t_map *map)
{
	free_and_exit(map, 0);
	return (1);
}

int	player_funct(t_map *map)
{
	int	i;
	int j;

	j = 0;
	while (j < 20)
	{
		i = 0;
		while (i < 20)
		{
			mlx_pixel_put(map->data->mlx_ptr, map->data->win_ptr, 500 + i, 500 + j, 0xFF0000);
			i++;
		}
		j++;
	}
	return (0);
}

void	display_game(t_map *map)
{
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