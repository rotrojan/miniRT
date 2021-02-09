/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/04 17:19:13 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		parse_coordinate(char **point_str, double *coordinate)
{
	char	*ptr;

	ptr = *point_str;
	if (!(ft_isdigit(*ptr) ||
		((*ptr == '+' || *ptr == '-'|| *ptr == '.') && ft_isdigit(*(ptr + 1)))))
		return (FALSE);
	while (ft_isdigit(*ptr) || *ptr == '+' || *ptr == '-' || *ptr == '.')
		ptr++;
	if (*ptr && *ptr != ',')
		return (FALSE);
	*coordinate = ft_atod(*point_str);
	if (!*ptr)
		*point_str = ptr;
	else
		*point_str = ++ptr;
	return (TRUE);
}

t_bool		parse_vector(char *point_str, t_vector *point)
{
	if (!parse_coordinate(&point_str, &(point->x)))
		return (FALSE);
	if (!parse_coordinate(&point_str, &(point->y)))
		return (FALSE);
	if (!parse_coordinate(&point_str, &(point->z)))
		return (FALSE);
	if (*point_str)
		return (FALSE);
	return (TRUE);
}

t_bool		parse_color(char *color_str, t_color *color)
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
	color->r /= 255.0f;
	color->g /= 255.0f;
	color->b /= 255.0f;
	return (TRUE);
}

t_bool		parse_length(char *length_str, double *length)
{
	char	*tmp;

	tmp = length_str;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp == '.')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (FALSE);
	*length = ft_atod(length_str);
	return (TRUE);
}

t_bool		parse_ratio(char *ratio_str, double *ratio)
{
	char	*tmp;

	tmp = ratio_str;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp == '.')
		tmp++;
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp)
		return (FALSE);
	*ratio = ft_atod(ratio_str);
	if (*ratio < 0.0 || *ratio > 1.0)
		return (FALSE);
	return (TRUE);
}

t_bool		parse_orientation(char *orientation_str, t_vector *orientation_vec)
{
	orientation_vec->x = ft_atod(orientation_str);
	if (orientation_vec->x < -1 || orientation_vec->x > 1)
		return (FALSE);
	while (ft_isdigit(*orientation_str) || *orientation_str == '+'
		|| *orientation_str == '-' || *orientation_str == '.')
		orientation_str++;
	if (*orientation_str++ != ',')
		return (FALSE);
	orientation_vec->y = ft_atod(orientation_str);
	if (orientation_vec->y < -1 || orientation_vec->y > 1)
		return (FALSE);
	while (ft_isdigit(*orientation_str) || *orientation_str == '+'
		|| *orientation_str == '-' || *orientation_str == '.')
		orientation_str++;
	if (*orientation_str++ != ',')
		return (FALSE);
	orientation_vec->z = ft_atod(orientation_str);
	if (orientation_vec->z < -1 || orientation_vec->z > 1)
		return (FALSE);
	while (ft_isdigit(*orientation_str) || *orientation_str == '+' ||
		*orientation_str == '-' || *orientation_str == '.')
		orientation_str++;
	if (*orientation_str)
		return (FALSE);
	return (TRUE);
}
