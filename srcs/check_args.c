/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 02:16:40 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/22 23:42:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		check_args(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		return (return_error("Wrong number of arguments.", NULL));
	if (ft_strcmp(".rt", av[1] + ft_strlen(av[1]) - 3))
		return (return_error("Invalid file extension.", NULL));
	if (av[2])
		if (ft_strcmp(av[2], "--save") && ft_strcmp(av[2], "-save" ))
			return (return_error("Third argument invalid.", NULL));
	return (TRUE);
}
