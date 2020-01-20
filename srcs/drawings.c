/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:02:06 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/19 17:18:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_rectangle
	(t_application *app, t_point top_left_corner, t_vector vec, int color)
{
	t_point		current;

	current = top_left_corner;
	while (current.y < top_left_corner.y + vec.y)
	{
		while (current.x < top_left_corner.x + vec.x)
		{
			put_pixel(app, current, color);
			current.x++;
		}
		current.x = top_left_corner.x;
		current.y++;
	}
}

void	draw_circle
	(t_application *app, t_point center, t_vector radius, int color)
{
	t_point		current;
	float		length_radius;

	length_radius = length_vector(radius);
	current.x = center.x - length_radius;
	current.y = center.y - length_radius;
	while (current.y < center.y + length_radius)
	{
		while (current.x < center.x + length_radius)
		{
			if (length_vector(vectorize(center, current)) < length_radius)
				put_pixel(app, current, color);
			current.x++;
		}
		current.x = center.x - length_radius;
		current.y++;
	}
}
