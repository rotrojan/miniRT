/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:05:52 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/11 16:59:22 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error		free_and_return(t_error error, t_object *object)
{
	free(object);
	object = NULL;
	return (error);
}

t_bool		parse_coordinate(char **point_str, double *coordinate)
{
	char	*tmp;

	tmp = *point_str;
	if (*tmp == '+' || *tmp == '-')
		++tmp;
	if (!ft_isdigit(*tmp))
		return (FALSE);
	while (ft_isdigit(*tmp))
		++tmp;
	if (*tmp == '.')
		++tmp;
	if (ft_isdigit(*tmp))
		while (ft_isdigit(*tmp))
			++tmp;
	if (!*tmp || *tmp == ',')
		*coordinate = ft_atod(*point_str);
	else
		return (FALSE);
	if (*tmp == ',')
		*point_str = ++tmp;
	return (TRUE);
}

t_bool		parse_vector(char *point_str, t_vector *point)
{
	if (!parse_coordinate(&point_str, &point->x))
		return (FALSE);
	if (!parse_coordinate(&point_str, &point->y))
		return (FALSE);
	if (!parse_coordinate(&point_str, &point->z))
		return (FALSE);
	return (TRUE);
}

t_bool		parse_color_component(char **color_str, double *color)
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

t_bool		parse_color(char *color_str, t_color *color)
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

t_bool		parse_length(char *length_str, double *length)
{
	char	*tmp;

	tmp = length_str;
	if (*tmp == '+' ||  *tmp == '-')
		++tmp;
	if (!ft_isdigit(*tmp))
		return (FALSE);
	while (ft_isdigit(*tmp))
		++tmp;
	if (*tmp == '.')
		++tmp;
	if (ft_isdigit(*tmp))
		while (ft_isdigit(*tmp))
			++tmp;
	if (*tmp)
		return (FALSE);
	*length = ft_atod(length_str);
	if (*length < 0)
		return (FALSE);
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
	if (!parse_coordinate(&orientation_str, &orientation_vec->x))
		return (FALSE);
	if (orientation_vec->x < -1 || orientation_vec->x > 1)
		return (FALSE);
	if (!parse_coordinate(&orientation_str, &orientation_vec->y))
		return (FALSE);
	if (orientation_vec->y < -1 || orientation_vec->y > 1)
		return (FALSE);
	if (!parse_coordinate(&orientation_str, &orientation_vec->z))
		return (FALSE);
	if (orientation_vec->z < -1 || orientation_vec->z > 1)
		return (FALSE);
	return (TRUE);
}
