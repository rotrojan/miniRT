/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:17:21 by rotrojan          #+#    #+#             */
/*   Updated: 2021/01/27 17:28:02 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include <math.h>

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef double		t_matrix[4][4];

t_vector			add_vectors(t_vector vec1, t_vector vec2);
t_vector			sub_vectors(t_vector vec1, t_vector vec2);
t_vector			cross_vectors(t_vector vec1, t_vector vec2);
double				dot_vectors(t_vector vec1, t_vector vec2);
double				norm_square_vector(t_vector vec);
double				norm_vector(t_vector vec);
t_vector			normalized_vector(t_vector vec);
t_vector			get_vector(double x, double y, double z);
t_vector			vec_matrix(t_vector vec, t_matrix mtrx);

#endif
