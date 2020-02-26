/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:52 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/25 22:10:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	get_vector(double x, double y, double z)
{
	t_vector vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
