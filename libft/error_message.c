/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:17:13 by avan-bre          #+#    #+#             */
/*   Updated: 2022/03/19 19:17:33 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
