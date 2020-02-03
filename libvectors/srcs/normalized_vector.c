/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalized_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:10:51 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/28 13:11:02 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	normalized_vector(t_vector vec)
{
	double		norm_vec;
	t_vector	returned_vec;

	norm_vec = norm_vector(vec);
	returned_vec.x = vec.x / norm_vec;
	returned_vec.y = vec.y / norm_vec;
	returned_vec.z = vec.z / norm_vec;
	return (returned_vec);
}
