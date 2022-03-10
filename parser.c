/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:39 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/10 18:24:31 by avan-bre         ###   ########.fr       */
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
		printf("malloc failed\n");
	//je me demande toujours si il faut proteger les mallocs avec un return (0) ou pas,
	//parce que si oui, il faut aussi proteger tout les ft_substr en dessous,
	//c'est beaucoup de code...
	i = 0;
	while (i < size)
	{
		map->map[i] = line;
		free_string(&line);
		line = get_next_line(fd);
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
		printf("Line: %s\n", map->map[i]);
		i++;
	}
}

void	get_map_data(t_map *map, int fd, int len)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!strncmp("NO ", line, 3))
			map->no = get_path_texture(line);
		else if (!strncmp("SO ", line, 3))
			map->so = get_path_texture(line);
		else if (!strncmp("WE ", line, 3))
			map->we = get_path_texture(line);
		else if (!strncmp("EA ", line, 3))
			map->ea = get_path_texture(line);
		else if (!strncmp("F ", line, 2))
			map->floor = get_color(line);
		else if (!strncmp("C ", line, 2))
			map->ceiling = get_color(line);
		else if (strncmp(line, "\n", 1))
			break ;
		free_string(&line);
		line = get_next_line(fd);
		i++;
	} 
	//si le path n'existe pas mlx_xpm_file_to_image == NULL, on a pas a faire le check ici. :)
	init_check_map(map, line, fd, len - i);
	print_map(map);
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
	int	i;
	int	len;

	len = 0;
	if (!check_extension(file))
	{
		printf("Invalid extension\n");
		return (0);
	}
	i = -1;
	while (++i < 2)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			printf("%s\n", strerror(errno));
			return (0);
		}
		if (i == 0)
			len = get_len(fd);
		else
			get_map_data(map, fd, len);
		close(fd);
	}
	return (1);
}
