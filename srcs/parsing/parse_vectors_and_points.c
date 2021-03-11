/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vectors_and_points.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:16:44 by bigo              #+#    #+#             */
/*   Updated: 2021/03/10 23:40:38 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	parse_coordinate(char **point_str, double *coordinate)
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

t_bool			parse_vector(char *point_str, t_vector *point)
{
	if (!parse_coordinate(&point_str, &point->x))
		return (FALSE);
	if (!parse_coordinate(&point_str, &point->y))
		return (FALSE);
	if (!parse_coordinate(&point_str, &point->z))
		return (FALSE);
	return (TRUE);
}

t_bool			parse_orientation(char *orientation_str,
													t_vector *orientation_vec)
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
	if (!orientation_vec->x && !orientation_vec->y && !orientation_vec->z)
		return (FALSE);
	*orientation_vec = normalized_vector(*orientation_vec);
	return (TRUE);
}
