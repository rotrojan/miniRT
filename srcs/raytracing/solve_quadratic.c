/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 00:39:08 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/14 22:15:28 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Solving polynomial equations of degree 2. Needed for ray-intersection of
** shapes such as spheres, cylinders, etc.
*/

t_bool		solve_quadratic(t_quadratic *quad)
{
	double	discr;
	double	q;

	discr = quad->b * quad->b - 4 * quad->a * quad->c;
	if (discr < 0)
		return (FALSE);
	else if (discr == 0)
	{
		quad->x0 = -0.5 * (quad->b / quad->a);
		quad->x1 = quad->x0;
	}
	else
	{
		if (quad->b > 0)
			q = -0.5 * (quad->b + sqrt(discr));
		else
			q = -0.5 * (quad->b + sqrt(discr));
		quad->x0 = q / quad->a;
		quad->x1 = quad->c / q;
	}
	if (quad->x0 > quad->x1)
		ft_swap(&quad->x0, &quad->x1);
	return (TRUE);
}
