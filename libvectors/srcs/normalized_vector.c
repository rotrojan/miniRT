/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalized_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:10:51 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/28 13:03:32 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	normalized_vector(t_vector vec)
{
	double	norm_vec;

	norm_vec = norm_vector(vec);
	return (get_vector(vec.x / norm_vec, vec.y / norm_vec, vec.z / norm_vec));
}
