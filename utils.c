/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:09:23 by cproesch          #+#    #+#             */
/*   Updated: 2022/03/14 16:57:16 by avan-bre         ###   ########.fr       */
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

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map->floor)
	{
		while (++i < 3)
			map->floor[i] = 0;
		free(map->floor);
	}
	i = -1;
	if (map->ceiling)
	{
		while (++i < 3)
			map->ceiling[i] = 0;
		free(map->ceiling);
	}
	if (map->no)
		free_string(&map->no);
	if (map->so)
		free_string(&map->so);
	if (map->we)
		free_string(&map->we);
	if (map->ea)
		free_string(&map->ea);
	i = -1;
	while (map->map[++i])
	{
		free_string(&map->map[i]);
		map->map[i] = NULL;
	}
	free(map->map);
	map->map = NULL;
}

void	free_and_exit(t_map *map, int exit_code)
{
	ft_free_map(map);
	exit(exit_code);
}

int	error_message(char *string, char *name, int code)
{
	ft_printf("Error : ", 2);
	if (name)
		ft_printf("%s: %s", 2, string, name);
	else
		ft_printf("%s", 2, string);
	ft_printf("\n", 2);
	return (code);
}
