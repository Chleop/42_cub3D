/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:39 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/10 15:36:40 by avan-bre         ###   ########.fr       */
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

int	parse_init_map(char *file)
{
	if (!check_extension(file))
	{
		printf("Invalid extension\n");
		return (0);
	}
	return (1);
}
