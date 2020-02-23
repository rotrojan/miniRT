/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:19:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/23 18:03:05 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		del(void *content)
{
	free(content);
}

t_bool		return_error(char *error_message, t_list **parsed_object_list)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	if (parsed_object_list && *parsed_object_list)
		ft_lstclear(parsed_object_list, &del);
	return (FALSE);
}

void		free_array(void **array)
{
	int		i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
