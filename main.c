/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:30 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/15 15:35:32 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_player *player, t_map *map)
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
	player->player_pos_X = 0;
	player->player_pos_Y = 0;
	player->view_dir_X = 0;
	player->view_dir_Y = 0;
	player->screen_plane_X = 0;
	player->screen_plane_Y = 0;
	player->point_on_plane_X = 0;
	player->point_on_plane_Y = 0;
	player->current_view_time = 0;
	player->previous_view_time = 0;
}

void 	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_message("Mlx_init failed", NULL, 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 360, 360, "cub3D");
	if (!data->win_ptr)
		error_message("Mlx_new_window failed", NULL, 1);
}

int	main(int argc, char *argv[])
{
	t_map		map;
	t_player	player;
	t_data		data;
	
	init_map(&player, &map);
	if (argc != 2)
		return (error_message("Expected format: ./cub3D < mapfile.cub >", NULL, 1));
	if (!parse_init_map(&map, argv[1]))
		free_and_exit(&map, 1);
	init_window(&data);


	free_and_exit(&map, 0);
}
