/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:21:59 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/28 16:56:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	vec_matrix(t_vector vec, t_matrix mtrx)
{
	return (get_vector(
			vec.x * mtrx[0 * 4 + 0] + vec.y * mtrx[1 * 4 + 0]
			+ vec.z * mtrx[2 * 4 + 0] + mtrx[3 * 4 + 0],
			vec.x * mtrx[0 * 4 + 1] + vec.y * mtrx[1 * 4 + 1]
			+ vec.z * mtrx[2 * 4 + 1] + mtrx[3 * 4 + 1],
			vec.x * mtrx[0 * 4 + 2] + vec.y * mtrx[1 * 4 + 2]
			+ vec.z * mtrx[2 * 4 + 2] + mtrx[3 * 4 + 2]));
}
