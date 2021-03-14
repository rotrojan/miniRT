/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_orientation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:16:44 by bigo              #+#    #+#             */
/*   Updated: 2021/03/14 13:58:37 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool			parse_orientation(char *orientation_str,
													t_vector *orientation_vec)
{
	if (!parse_vector(orientation_str, orientation_vec))
		return (FALSE);
	if ((!orientation_vec->x && !orientation_vec->y && !orientation_vec->z)
		|| orientation_vec->x < -1 || orientation_vec->x > 1
		|| orientation_vec->y < -1 || orientation_vec->y > 1
		|| orientation_vec->z < -1 || orientation_vec->z > 1)
		return (FALSE);
	*orientation_vec = normalized_vector(*orientation_vec);
	return (TRUE);
}
