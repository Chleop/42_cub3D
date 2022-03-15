/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:45:32 by cproesch          #+#    #+#             */
/*   Updated: 2022/03/15 17:04:16 by cproesch         ###   ########.fr       */
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

int	test()
{
	usleep(500);
	return (0);
}

void	display_game(t_map *map)
{
	mlx_loop_hook(map->data->mlx_ptr, &test, NULL);
	mlx_hook(map->data->win_ptr, 2, 1L<<0, &key_event, map);
	mlx_hook(map->data->win_ptr, 17, 0, &redcross_exit, map);
	mlx_loop(map->data->mlx_ptr);
}