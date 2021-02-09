/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:21:59 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/09 15:15:17 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	vec_matrix(t_vector vec, t_matrix mtrx)
{
	return (get_vector(
			vec.x * mtrx[0] + vec.y * mtrx[3] + vec.z * mtrx[6],
			vec.x * mtrx[1] + vec.y * mtrx[4] + vec.z * mtrx[7],
			vec.x * mtrx[2] + vec.y * mtrx[5] + vec.z * mtrx[8]));
}
