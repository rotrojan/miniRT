/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_and_geometrics.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:11:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/19 03:47:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		create_color
	(unsigned char red, unsigned char green, unsigned char blue)
{
	t_color		color;

	color.r = red;
	color.g = green;
	color.b = blue;
	return (color);
}

float		length_vector(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

t_vector	vectorize(t_point a, t_point b)
{
	t_vector	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	return (vec);
}
