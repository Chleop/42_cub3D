/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:30 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/15 13:01:42 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
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
}

int	main(int argc, char *argv[])
{
	t_map	map;

	init_map(&map);
	if (argc != 2)
		return (error_message("Expected format: ./cub3D < mapfile.cub >",
				NULL, 1));
	if (!parse_init_map(&map, argv[1]))
		free_and_exit(&map, 1);
	free_and_exit(&map, 0);
}
