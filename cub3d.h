/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:58 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/11 15:15:25 by cproesch         ###   ########.fr       */
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
	int		*floor;
	int		*ceiling;
	char	**map;
} t_map;


int		parse_init_map(t_map *map, char *file);
void	free_string(char **string);
void	ft_free_map(t_map *map);
void	free_and_exit(t_map *map, int exit_code);
int		error_message(char *string, char *name, int code);

#endif