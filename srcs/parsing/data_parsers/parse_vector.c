/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:16:44 by bigo              #+#    #+#             */
/*   Updated: 2021/03/17 02:03:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**	Points and vectors are handled the exact same way.
*/

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
	{
		++tmp;
		if (!ft_isdigit(*tmp))
			return (FALSE);
		while (ft_isdigit(*tmp))
			++tmp;
	}
	if (!*tmp || *tmp == ',')
		*coordinate = ft_atod(*point_str);
	else
		return (FALSE);
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
