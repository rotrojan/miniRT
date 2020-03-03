/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 06:08:07 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 11:58:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error				parse_resolution(char **token_array, t_mlx *mlx)
{
	char		*tmp;

	if (mlx->win_width || mlx->win_height)
		return (RES_TWICE_ERR);
	if (!token_array[1] || !token_array[2] || token_array[3])
		return (RES_FMT_ERR);
	tmp = token_array[1];
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (RES_X_FMT_ERR);
	tmp = token_array[2];
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (RES_Y_FMT_ERR);
	if ((mlx->win_width = fmin(WIN_X_MAX, ft_atoi(token_array[1]))) <= 0)
		return (RES_X_FMT_ERR);
	if ((mlx->win_height = fmin(WIN_Y_MAX, ft_atoi(token_array[2]))) <= 0)
		return (RES_X_FMT_ERR);
	return (NO_ERROR);
}
