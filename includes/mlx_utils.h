/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:13:01 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/11 01:47:22 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "minirt.h"

typedef struct		s_mlx
{
	int		win_width;
	int		win_height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}					t_mlx;

/*
** mlx_utils.c
*/

void				init_mlx(t_mlx *mlx);
void				apply_background(t_mlx *mlx, int color);
void				put_pixel(t_mlx *mlx, int x, int y, t_color color);

#endif
