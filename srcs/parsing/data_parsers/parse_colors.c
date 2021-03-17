/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:29:37 by bigo              #+#    #+#             */
/*   Updated: 2021/03/17 10:41:06 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	parse_color_component(char **color_str, double *color)
{
	char	*tmp;

	tmp = *color_str;
	if (!(check_int(&tmp)))
		return (FALSE);
	if (*tmp == ',' || !*tmp)
		*color = (double)ft_atoi(*color_str);
	else
		return (FALSE);
	if (*color < 0 || *color > 255)
		return (FALSE);
	*color_str = tmp;
	return (TRUE);
}

t_bool			parse_color(char *color_str, t_color *color)
{
	if (!(parse_color_component(&color_str, &color->r)))
		return (FALSE);
	if (*color_str++ != ',')
		return (FALSE);
	if (!(parse_color_component(&color_str, &color->g)))
		return (FALSE);
	if (*color_str++ != ',')
		return (FALSE);
	if (!(parse_color_component(&color_str, &color->b)))
		return (FALSE);
	if (*color_str)
		return (FALSE);
	color->r /= 255.0f;
	color->g /= 255.0f;
	color->b /= 255.0f;
	return (TRUE);
}
