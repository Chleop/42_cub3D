/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:30 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/10 17:52:53 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_string(char **string)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
}

void	ft_free(t_map *map)
{
	int i;

	i = -1;
	while (++i < 3)
		map->floor[i] = 0;
	free(map->floor);
	while (++i < 3)
		map->ceiling[i] = 0;
	free(map->ceiling);
	free_string(&map->no);
	free_string(&map->so);
	free_string(&map->we);
	free_string(&map->ea);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	
	if (argc != 2)
	{
		printf("Expected format: ./cub3D < mapfile.cub >\n");
		return (1);
	}
	if (!parse_init_map(&map, argv[1]))
		return (1);
	ft_free(&map);
}
