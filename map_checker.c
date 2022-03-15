/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:36:17 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/14 17:20:53 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls(t_map *map, int i, int j)
{
	printf("i %d j %d char %c\n", i, j, map->map[i][j]);
	// printf("H %d, w %d\n", map->height, map->width);
	if (i == 0 || i == map->height - 1)
	{
		if (!(map->map[i][j] == '1' || map->map[i][j] == ' '))
			return (0);
	}
	else if (!(map->map[i][j] != ' ' || map->map[i][j] != ' '))
	{
		if (map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' ' || map->map[i + 1][j] == '\0')
		{
		 	if (map->map[i][j] != '1')
	 			return (0);
		}
	}
	if (j == 0)
	{
		if (!(map->map[i][j] == '1' || map->map[i][j] == ' '))
			return (0);
	}
	else if (!(map->map[i][j] != ' ' || map->map[i][j] != '\0'))
	{
	 	if (map->map[i][j + 1] == ' ' || map->map[i][j + 1] == '\0' || map->map[i][j - 1] == ' ')
		{
	 		if (map->map[i][j] != '1')
	 			return (0);
		}
	}
	return (1);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{	
			if (!strchr("10NESW ", map->map[i][j]))
				return (0);
			if (map->map[i][j] == 'N' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'W' || map->map[i][j] == 'S')
			{
				if (map->player_direction)
					return (0);
				map->player_direction = map->map[i][j];
				map->player_x = j;
				map->player_y = i;
			}
			if (!check_walls(map, i, j))
				return (0);
			j++;
		}
		printf("Line %d done: %s\n", i, map->map[i]);
		i++;
	}
	if (!map->player_direction)
		return (0);
	return (1);
}

