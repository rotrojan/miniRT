/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:21:59 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/19 14:38:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_matrix(t_vector vec, t_matrix mtrx)
{
	t_vector	ret;

	ret.x = vec.x * mtrx[0][0] + vec.y * mtrx[1][0]
		+ vec.z * mtrx[2][0] + mtrx[3][0];
	ret.y = vec.x * mtrx[0][1] + vec.y * mtrx[1][1]
		+ vec.z * mtrx[2][1] + mtrx[3][1];
	ret.z = vec.x * mtrx[0][2] + vec.y * mtrx[1][2]
		+ vec.z * mtrx[2][2] + mtrx[3][2];
	return (ret);
}
