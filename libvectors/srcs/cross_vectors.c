/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:29:47 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/22 16:53:22 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	cross_vectors(t_vector vec1, t_vector vec2)
{
	t_vector vec_ret;

	vec_ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec_ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec_ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (vec_ret);
}
