/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:58 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/15 13:00:02 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_direction;
	int		*floor;
	int		*ceiling;
	char	**map;
} t_map;


//general
void	free_string(char **string);
void	ft_free_map(t_map *map);
void	free_and_exit(t_map *map, int exit_code);
int		error_message(char *string, char *name, int code);

//parsing
int		parse_init_map(t_map *map, char *file);
int		check_extension(char *file);
char	*get_path_texture(char *line);
int		*get_color(char *line);
void	print_map(t_map *map);
void	get_len(t_map *map, int fd);
int		check_map(t_map *map);
char	*realloc_line(char *line, int size);

#endif