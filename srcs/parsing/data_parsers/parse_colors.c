/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:29:37 by bigo              #+#    #+#             */
/*   Updated: 2021/03/10 23:37:59 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	parse_color_component(char **color_str, double *color)
{
	char	*tmp;

	tmp = *color_str;
	if (*tmp == '+' || *tmp == '-')
		++tmp;
	if (!ft_isdigit(*tmp))
		return (FALSE);
	while (ft_isdigit(*tmp))
		++tmp;
	if (*tmp == ',' || !*tmp)
		*color = (double)ft_atoi(*color_str);
	else
		return (FALSE);
	if (*color < 0 || *color > 255)
		return (FALSE);
	if (*tmp == ',')
		*color_str = ++tmp;
	return (TRUE);
}

t_bool			parse_color(char *color_str, t_color *color)
{
	if (!(parse_color_component(&color_str, &color->r)))
		return (FALSE);
	if (!(parse_color_component(&color_str, &color->g)))
		return (FALSE);
	if (!(parse_color_component(&color_str, &color->b)))
		return (FALSE);
	color->r /= 255.0f;
	color->g /= 255.0f;
	color->b /= 255.0f;
	return (TRUE);
}
