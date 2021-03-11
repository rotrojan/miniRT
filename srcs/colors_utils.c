/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:19:05 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/10 23:56:38 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		get_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color		shade_color(double coef, t_color color)
{
	return (get_color(coef * color.r, coef * color.g, coef * color.b));
}

t_color		add_colors(t_color color1, t_color color2)
{
	return (get_color(fmin(1, fmax(0, color1.r + color2.r)),
			fmin(1, fmax(0, color1.g + color2.g)),
			fmin(1, fmax(0, color1.b + color2.b))));
}

t_color		mix_colors(t_color color1, t_color color2)
{
	return (get_color(fmin(1, fmax(0, color1.r * color2.r)),
			fmin(1, fmax(0, color1.g * color2.g)),
			fmin(1, fmax(0, color1.b * color2.b))));
}
