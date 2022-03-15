/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:36:17 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/15 12:49:19 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls(t_map *map, int i, int j)
{
	if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
	{
		if (!(map->map[i][j] == '1' || map->map[i][j] == ' '))
			return (0);
	}
	else if (map->map[i][j] != ' ')
	{
		if (map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' '
			|| map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' ')
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
	while (map->map[i])
	{
		j = 0;
		map->map[i] = realloc_line(map->map[i], map->width + 1);
		while (map->map[i][j])
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
		i++;
	}
	if (!map->player_direction)
		return (0);
	return (1);
}

