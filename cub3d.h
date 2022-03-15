/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:58 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/15 15:34:01 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include "mlx.h"

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		height;
	int		width;
	int		player_direction;
	int		*floor;
	int		*ceiling;
	char	**map;
} t_map;

typedef struct s_player
{
	float	player_pos_X;
	float	player_pos_Y;
	float	view_dir_X;
	float	view_dir_Y;
	float	screen_plane_X;
	float	screen_plane_Y;
	float	point_on_plane_X;//cameraX
	float	point_on_plane_Y;//cameraY
	float	current_view_time;
	float	previous_view_time;
} t_player;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int		parse_init_map(t_map *map, char *file);
void	free_string(char **string);
void	ft_free_map(t_map *map);
void	free_and_exit(t_map *map, int exit_code);
int		error_message(char *string, char *name, int code);

#endif