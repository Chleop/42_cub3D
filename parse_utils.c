/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:03:16 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/14 16:54:12 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *file)
{
	int		i;

	i = ft_strlen(file);
	while (i > 0 && file[i] != '.')
		i--;
	if (ft_strncmp(".cub\0", &file[i], 5))
		return (0);
	return (1);
}

char	*get_path_texture(char *line)
{
	int		i;
	char	*path;

	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup(&line[i]);
	path[ft_strlen(path) - 1] = '\0';
	return (path);
}

int	*get_color(char *line)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * 3);
	if (!tab)
		printf("malloc error\n");
	i = 1;
	while (line[i] == ' ')
		i++;
	tab[0] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	tab[1] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	tab[2] = ft_atoi(&line[i]);
	return (tab);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		printf("Line[%d]:	%s\n", i, map->map[i]);
		i++;
	}
}

void	get_len(t_map *map, int fd)
{
	char	*line;
	int		width;

	line = get_next_line(fd);
	while (line)
	{
		width = ft_strlen(line);
		if (width > map->width)
			map->width = width;
		map->height++;
		free_string(&line);
		line = get_next_line(fd);
	}
}

char	*ft_realloc(char *line, int size)
{
	char	*new_line;

	new_line = ft_calloc(size, sizeof(char));
	if (!new_line)
	{
		error_message("Malloc failed", NULL, 0);
		return (NULL);
	}
	ft_strlcpy(new_line, line, ft_strlen(line));
	free_string(&line);
	return (new_line);
}
