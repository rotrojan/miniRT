/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:13:01 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 17:23:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCT_H
# define MLX_STRUCT_H
# include "minirt.h"

/*
** This structure contains all informations needed by the MLX. Even if a screen-
** shot is called (hence the mlx is not initialized) the *data pointer contains
** the array of pixels of the resulting image.
*/

typedef struct		s_mlx
{
	unsigned int		win_width;
	unsigned int		win_height;
	int					screen_width;
	int					screen_height;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*data;
	int					size_line;
	int					bits_per_pixel;
	int					endian;
}					t_mlx;

#endif
