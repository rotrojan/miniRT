/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:08:07 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 21:26:07 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error				parse_resolution(char **token_array, t_main *main)
{
	char		*tmp;

	if (main->mlx.win_width || main->mlx.win_height)
		return (RES_TWICE_ERR);
	if (!token_array[1] || !token_array[2] || token_array[3])
		return (RES_FMT_ERR);
	tmp = token_array[1];
	if (!(check_int(&tmp)))
		return (RES_X_FMT_ERR);
	if (*tmp)
		return (RES_X_FMT_ERR);
	tmp = token_array[2];
	if (!(check_int(&tmp)))
		return (RES_Y_FMT_ERR);
	if (*tmp)
		return (RES_Y_FMT_ERR);
	main->mlx.win_width = (unsigned int)ft_atoi(token_array[1]);
	if (ft_atoll(token_array[1]) != main->mlx.win_width || main->mlx.win_width
		<= 0)
		return (RES_X_FMT_ERR);
	main->mlx.win_height = (unsigned int)ft_atoi(token_array[2]);
	if (ft_atoll(token_array[2]) != main->mlx.win_height || main->mlx.win_height
		<= 0)
		return (RES_Y_FMT_ERR);
	return (NO_ERROR);
}
