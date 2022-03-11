/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:39 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/11 17:03:05 by cproesch         ###   ########.fr       */
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

void	init_check_map(t_map *map, char *line, int fd, int size)
{
	int	i;

	map->map = malloc(sizeof(char *) * size + 1);
	if (map->map == NULL)
		printf("Malloc failed\n");
	//je me demande toujours si il faut proteger les mallocs avec un return (0) ou pas,
	//parce que si oui, il faut aussi proteger tout les ft_substr en dessous,
	//c'est beaucoup de code...
	i = 0;
	map->map[i] = line;
	if ((ft_strchr(map->map[i], '\n')))
		*(ft_strchr(map->map[i], '\n')) = '\0';
	i++;
	while (i < size)
	{
		map->map[i] = get_next_line(fd);
		if ((ft_strchr(map->map[i], '\n')))
			*(ft_strchr(map->map[i], '\n')) = '\0';
		i++;
	}
	map->map[i] = NULL;
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

int	get_map_data(t_map *map, int fd, int len)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (strncmp(line, "\n", 1))
		{
			if (!map->no && !strncmp("NO ", line, 3))
				map->no = get_path_texture(line);
			else if (!map->so && !strncmp("SO ", line, 3))
				map->so = get_path_texture(line);
			else if (!map->we && !strncmp("WE ", line, 3))
				map->we = get_path_texture(line);
			else if (!map->ea && !strncmp("EA ", line, 3))
				map->ea = get_path_texture(line);
			else if (!map->floor && !strncmp("F ", line, 2))
				map->floor = get_color(line);
			else if (!map->ceiling && !strncmp("C ", line, 2))
				map->ceiling = get_color(line);
			else if (map->no && map->so && map->we && map->ea && map->floor && map->ceiling)
			{
				init_check_map(map, line, fd, len - i);
				break;
			}
			else
				return (0);
		}
		free_string(&line);
		line = get_next_line(fd);
		i++;
	} 
	//si le path n'existe pas mlx_xpm_file_to_image == NULL, on a pas a faire le check ici. :)
	return (1);
}

int	get_len(fd)
{
	char	*line;
	int		len;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free_string(&line);
		line = get_next_line(fd);
	}
	return (len);
}

int	parse_init_map(t_map *map, char *file)
{
	int	fd;
	int	len;

	len = 0;
	if (!check_extension(file))
		return (error_message("Invalid extension", NULL, 0));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_message(strerror(errno), NULL, 0));
	len = get_len(fd);
	close(fd);
	// c'est tres laid mais il faut open deux fois sinon line est a la fin du fichier
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_message(strerror(errno), NULL, 0));
	if (!get_map_data(map, fd, len))
		return (error_message("We found invalid data in ", file, 0));
	print_map(map);
	close(fd);

	return (1);
}
