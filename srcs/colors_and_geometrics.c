/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_and_geometrics.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:11:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/20 22:46:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		apply_background(t_application *app, int color)
{
	int		nb_pixels;
	int		index_pixel;

	nb_pixels = WIN_X * WIN_Y;
	index_pixel = 0;
	while (index_pixel < nb_pixels)
		app->data[index_pixel++] = color;
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
