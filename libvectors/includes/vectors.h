/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:17:21 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/17 16:30:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include <math.h>

typedef double		t_vector __attribute__((ext_vector_type(3)));

double				dot_vectors(t_vector vec1, t_vector vec2);
double				norm_square_vector(t_vector vec);
double				norm_vector(t_vector vec);
t_vector			normalized_vector(t_vector vec);
t_vector			get_vector(double x, double y, double z);

#endif
