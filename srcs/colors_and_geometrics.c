/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_and_geometrics.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:11:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/01/27 06:34:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		apply_background(t_application *app, int color)
{
	int		nb_pixels;
	int		index_pixel;

	nb_pixels = app->win_width * app->win_height;
	index_pixel = 0;
	while (index_pixel < nb_pixels)
		app->data[index_pixel++] = color;
}
