/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:36:17 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/17 18:12:08 by avan-bre         ###   ########.fr       */
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

void	init_player(t_map *map, int i, int j)
{
	map->player->pos[0] = (double)j + 0.5;
	map->player->pos[1] = (double)i + 0.5;
	map->player->len_camera = 2;
	if (map->player_direction == 'N')
		map->player->player_angle = PI + PI / 2;
	else if (map->player_direction == 'S')
		map->player->player_angle = (PI / 2);
	else if (map->player_direction == 'E')
		map->player->player_angle = PI / 2;
	else if (map->player_direction == 'W')
		map->player->player_angle = 0;
	get_view_points(map);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
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
				init_player(map, i, j);
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

