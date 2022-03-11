/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:30 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/11 16:06:19 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// We need to initialize the structure in case the function returns before it is 
// filled in (ex: wrong extension -> we will try to free map's variables and
// they are not initialized nor allocated yet);
void	init_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->floor = 0;
	map->ceiling = 0;
	map->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_map	map;
	
	init_map(&map);
	if (argc != 2)
		return (error_message("Expected format: ./cub3D < mapfile.cub >", NULL, 1));
	if (!parse_init_map(&map, argv[1]))
		free_and_exit(&map, 1);
	free_and_exit(&map, 0);
}
