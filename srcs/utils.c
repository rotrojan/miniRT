/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:19:05 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/24 21:36:32 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		del(void *content)
{
	free(content);
}

t_error		return_error(t_error num_error, t_list **obj_lst)
{
	static char const	*str_error[] = {
		"", "Wrong number of arguments.", "Cannot open file.",
		"Invalid file extension.", "Invalid third argument.",
		"Cannot read file.", "Malloc failure.", "Element not well formatted.",
		"Sphere position not well formatted.",
		"Sphere color not well formatted.", "Sphere radius not well formatted.",
		"Sphere not well formatted.", "Sphere not well formatted.",
		"Resolution width not well formatted.",
		"Resolution height not well formatted.",
		"Resolution can only be set once.", "Resolution not well formatted.",
		"Ambient lighting not well formatted.",
		"Ambient lighting ratio not well formatted.",
		"Ambient lighting color not well formatted."
		};

	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd((char*)str_error[num_error], STDERR_FILENO);
	ft_lstclear(obj_lst, &del);
	return (EXIT_FAILURE);
}

void		free_array(void **array)
{
	int		i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
