/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:52 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/03 17:27:14 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	get_vector(float x, float y, float z)
{
	t_vector vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

