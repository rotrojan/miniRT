/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:02:06 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/24 04:50:56 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_rectangle
	(t_application *app, int x, int y, t_vector vec, int color)
{
	t_point		current;

	current.x = x;;
	current.y = y;
	while (current.y < y + vec.y)
	{
		while (current.x < x + vec.x)
		{
			put_pixel(app, current.x, current.y, color);
			current.x++;
		}
		current.x = x;
		current.y++;
	}
}

void	draw_circle
	(t_application *app, int x, int y, double radius, int color)
{
	t_point		center;
	t_point		current;

	center.x = x - radius;
	center.y = y - radius;
	current = center;
	while (current.y < y + radius)
	{
		while (current.x < x + radius)
		{
			if (length_vector(vectorize(center, current)) < radius)
				put_pixel(app, x, y, color);
			current.x++;
		}
		current.x = center.x - radius;
		current.y++;
	}
}
