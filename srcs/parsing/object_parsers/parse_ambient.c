/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:07:01 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/08 00:28:42 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error				parse_ambient(char **token_array, t_main *main)
{
	if (main->scene.ambient.ratio != -1.0)
		return (AMB_TWICE_ERR);
	if (!token_array[1] || !token_array[2] || token_array[3])
		return (AMB_FMT_ERR);
	if (!(parse_ratio(token_array[1], &main->scene.ambient.ratio)))
		return (AMB_RATIO_ERR);
	if (!(parse_color(token_array[2], &main->scene.ambient.color)))
		return (AMB_COL_ERR);
	return (NO_ERROR);
}
