/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 01:27:03 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/11 01:46:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOKS_H
# define MLX_HOOKS_H
# include "minirt.h"

/*
** mlx_hooks.c
*/

t_bool				run_mlx(t_main *main);
int					set_mlx_hooks(t_main *main);
int					close_mlx(t_mlx *mlx);

#endif
