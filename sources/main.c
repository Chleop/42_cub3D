/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:30 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/17 15:47:48 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->height = 0;
	map->width = 0;
	map->player_direction = 0;
	map->floor = 0;
	map->ceiling = 0;
	map->map = NULL;
	map->player = malloc(1 * sizeof(t_player));
	map->player->pos[0] = 0;
	map->player->pos[1] = 0;
	map->player->dir[0] = 0;
	map->player->dir[1] = 0;
	map->player->sideDistX = 0;
	map->player->sideDistY = 0;
	map->player->plane_left_X = 0;
	map->player->plane_left_Y = 0;
	map->player->plane_right_X = 0;
	map->player->plane_right_Y = 0;
	map->player->screen_plane_X = 0;
	map->player->screen_plane_Y = 0;
	// map->player->point_on_plane_X = 0;
	// map->player->point_on_plane_Y = 0;
	map->player->current_view_time = 0;
	map->player->previous_view_time = 0;
	map->data = malloc(1 * sizeof(t_data));
	map->data->win_ptr = NULL;
	map->data->mlx_ptr = NULL;
}

void 	init_window(t_map *map)
{
	map->data->mlx_ptr = mlx_init();
	if (!map->data->mlx_ptr)
		error_message("Mlx_init failed", NULL, 1);
	map->data->win_ptr = mlx_new_window(map->data->mlx_ptr, 60 * map->width, 60 * map->height, "cub3D");
	if (!map->data->win_ptr)
		error_message("Mlx_new_window failed", NULL, 1);
}

int	main(int argc, char *argv[])
{
	t_map		map;
	
	if (argc != 2)
		return (error_message("Expected format: ./cub3D < mapfile.cub >", NULL, 1));
	init_struct(&map);
	if (!parse_init_map(&map, argv[1]))
		free_and_exit(&map, 1);
	init_window(&map);
	display_game(&map);
	free_and_exit(&map, 0);
}
