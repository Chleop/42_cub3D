/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:14:38 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/22 18:27:10 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	is_wall(int sideDist_X_X, int sideDist_X_Y, t_data *data)
// {
// 	printf("sideDist_X_X = %d, sideDist_X_Y = %d\n", sideDist_X_X, sideDist_X_Y);
// 	printf("data->map->width = %d, data->map->height = %d\n", data->map->width, data->map->height);
// 	printf("la case map[%d][%d] vaut %d\n", sideDist_X_Y, sideDist_X_X, data->map->map[sideDist_X_Y][sideDist_X_X]);
// 	if (((sideDist_X_X != 0) || (sideDist_X_X != 0))
// 		&& (sideDist_X_X >= 0) && (sideDist_X_X < data->map->width) 
// 		&& (sideDist_X_Y >= 0) && (sideDist_X_Y < data->map->height) 
// 		&& (data->map->map[sideDist_X_Y][sideDist_X_X] == 49))	// 49 corresponds to '1' in ascii tables
// 		return (1);
// 	return (0);
// }

void	get_rays(t_data *data)
{
	int	i;

	i = 0;
	printf("player angle = %f\n", data->player->angle);
	// while (!is_wall((int)data->player->sideDist_X_X, (int)data->player->sideDist_X_Y, data))
	// {
		
		if ((data->player->angle < PI / 2) || (data->player->angle > (3 * PI / 2)))			// looking right
		{
			data->player->sideDist_X_X = floor(data->player->pos[0] + 1 + i);
			data->player->sideDist_X_Y = data->player->pos[1] + ((data->player->sideDist_X_X - data->player->pos[0]) * (data->player->plane_left_Y - data->player->pos[1]) / (data->player->plane_left_X - data->player->pos[0]));
		}
		else if ((data->player->angle > PI / 2) || (data->player->angle < (3 * PI / 2)))	// looking left
		{
			data->player->sideDist_X_X = floor(data->player->pos[0] - i);
			data->player->sideDist_X_Y = data->player->pos[1] + ((data->player->sideDist_X_X - data->player->pos[0]) * (data->player->plane_left_Y - data->player->pos[1]) / (data->player->plane_left_X - data->player->pos[0]));
		}
		i++;
	// }
	// printf("trouve!\n");
	// while (!is_wall((int)player->sideDist_Y_Y, (int)player->sideDist_Y_X), data)
	// {
		// if (player->angle < PI)														// looking up
		// {
		// 	player->sideDist_Y_Y = floor(player->pos[1]) + 1;
		// 	player->sideDist_Y_X = player->pos[0] + ((player->sideDist_Y_Y - player->pos[1]) * (player->plane_left_X - player->pos[0]) / (player->plane_left_Y - player->pos[1]));
		// }
		// else if (player->angle > PI)												// looking down
		// {
		// 	player->sideDist_Y_Y = floor(player->pos[1]);
		// 	player->sideDist_Y_X = player->pos[0] + ((player->sideDist_Y_Y - player->pos[1]) * (player->plane_left_X - player->pos[0]) / (player->plane_left_Y - player->pos[1]));
		// }
		// i++;
	// }
}

void	get_view_points(t_data *data)
{
	data->player->dir[0] = data->player->pos[0] + data->player->dist * cos(data->player->angle);
	data->player->dir[1] = data->player->pos[1] + data->player->dist * sin(data->player->angle);
	data->player->plane_right_X = data->player->pos[0] + (data->player->dist * cos(data->player->angle + (11 * PI / 60)));
	data->player->plane_right_Y = data->player->pos[1] + (data->player->dist * sin(data->player->angle + (11 * PI / 60)));
	data->player->plane_left_X = data->player->pos[0] + (data->player->dist * cos(data->player->angle - (11 * PI / 60)));
	data->player->plane_left_Y = data->player->pos[1] + (data->player->dist * sin(data->player->angle - (11 * PI / 60)));
	get_rays(data);
	// printf("data->player position x = %f, data->player position y = %f\n", data->player->pos[0], data->player->pos[1]);
	// printf("sideDist_X_X = %f, sideDist_X_Y = %f\n", data->player->sideDist_X_X, data->player->sideDist_X_Y);
	// data->player->sideDist_Y_X = data->player->sideDist_Y_Y * data->player->plane_left_X / data->player->plane_left_Y;
	// printf("sideDist_Y_X = %f\n", data->player->sideDist_Y_X);

}
