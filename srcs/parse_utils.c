/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/23 17:36:04 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	parse_vector(char *point_str, t_vector *point)
{
	point->x = ft_atod(point_str);
	while (ft_isdigit(*point_str)
		|| *point_str == '+' || *point_str == '-' || *point_str == '.')
		point_str++;
	if (*point_str != ',')
		return (FALSE);
	point_str++;
	point->y = ft_atod(point_str);
	while (ft_isdigit(*point_str)
		|| *point_str == '+' || *point_str == '-' || *point_str == '.')
		point_str++;
	if (*point_str != ',')
		return (FALSE);
	point_str++;
	point->z = ft_atod(point_str);
	while (ft_isdigit(*point_str)
		|| *point_str == '+' || *point_str == '-' || *point_str == '.')
		point_str++;
	if (*point_str)
		return (FALSE);
	point_str++;
	return (TRUE);
}

t_bool	parse_color(char *color_str, t_color *color)
{
	color->r = (double)ft_atoi(color_str);
	while (ft_isdigit(*color_str))
		color_str++;
	if (*color_str++ != ',' || color->r < 0 || color->r > 255)
		return (FALSE);
	color->g = (double)ft_atoi(color_str);
	while (ft_isdigit(*color_str))
		color_str++;
	if (*color_str++ != ',' || color->g < 0 || color->g > 255)
		return (FALSE);
	color->b = (double)ft_atoi(color_str);
	while (ft_isdigit(*color_str))
		color_str++;
	if (*color_str || color->b < 0 || color->b > 255)
		return (FALSE);
	*color /= 255.0f;
	return (TRUE);
}

t_bool	parse_length(char *length_str, double *length)
{
	*length = ft_atod(length_str);
	while (*length_str)
	{
		if (!ft_isdigit(*length_str) && *length_str != '.')
			return (FALSE);
		length_str++;
	}
	return (TRUE);
}
