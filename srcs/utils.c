/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:19:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/16 23:06:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool				return_error(char *error_message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	return (FALSE);
}
