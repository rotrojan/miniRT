/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 02:16:40 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/26 04:13:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error		check_args(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		return (NB_ARGS_ERR);
	if (ft_strcmp(".rt", av[1] + ft_strlen(av[1]) - 3))
		return (FILE_EXTENSION_ERR);
	if (av[2])
		if (ft_strcmp(av[2], "--save") && ft_strcmp(av[2], "-save"))
			return (THIRD_ARG_ERR);
	return (NO_ERROR);
}
