/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:11:42 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/24 00:18:59 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	add_vectors(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}

t_vector	sub_vectors(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}

t_vector	mul_vector(t_vector vec, double nb)
{
	t_vector	result;

	result.x = vec.x * nb;
	result.y = vec.y * nb;
	result.z = vec.z * nb;
	return (result);
}

t_vector	div_vector(t_vector vec, double nb)
{
	t_vector	result;

	result.x = vec.x / nb;
	result.y = vec.y / nb;
	result.z = vec.z / nb;
	return (result);
}

double		dot_vectors(t_vector vec1, t_vector vec2)
{
	return ((double)(vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z));
}
