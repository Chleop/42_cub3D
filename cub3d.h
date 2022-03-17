/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:58 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/17 10:18:49 by avan-bre         ###   ########.fr       */
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
# include <math.h>
# include "mlx.h"

# include <sys/types.h>
# include <sys/wait.h>

# define PIC_BACK "./images/back.xpm"
# define PIC_WALL "./images/wall.xpm"
# define PI 3.14159265358979323846

enum e_enum
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	RIGHT = 65363,
	LEFT = 65361
};

typedef struct s_map
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				height;
	int				width;
	int				player_direction;
	int				*floor;
	int				*ceiling;
	char			**map;
	struct s_player	*player;
	struct s_data	*data;
} t_map;

typedef struct s_player
{
	double	player_pos_X;
	double	player_pos_Y;
	double	player_angle;
	double	len_camera;
	double	view_dir_X;
	double	view_dir_Y;
	double	screen_plane_X;
	double	screen_plane_Y;
	double	point_on_plane_X;//cameraX
	double	point_on_plane_Y;//cameraY
	double	current_view_time;
	double	previous_view_time;
} t_player;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*pic_back;
	void	*pic_wall;
}	t_data;

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

//game display
void	display_game(t_map *map);
void	get_view_points(t_map *map);

#endif