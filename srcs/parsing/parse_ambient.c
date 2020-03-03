/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:07:01 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/01 06:11:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_error		check_ambient(char **token_array, t_list **obj_lst)
{
	t_list		*current_link;

	if (!token_array[1] || !token_array[2] || token_array[3])
		return (AMB_FMT_ERR);
	current_link = *obj_lst;
	while (current_link)
	{
		if (((t_object*)(current_link->content))->obj_type == AMBIENT)
			return (RES_TWICE_ERR);
		current_link = current_link->next;
	}
	return (NO_ERROR);
}

t_error				parse_ambient(char **token_array, t_list **obj_lst)
{
	t_object	*ambient;
	t_error		ret;

	ambient = NULL;
	if ((ret = check_ambient(token_array, obj_lst)) != NO_ERROR)
		return (ret);
	if (!(ambient = (t_object*)malloc(sizeof(t_object))))
		return (MALLOC_ERR);
	ambient->obj_type = AMBIENT;
	if (!(parse_ratio(token_array[1], &ambient->obj_prop.ambient.ratio)))
	{
		free(ambient);
		return (AMB_RATIO_ERR);
	}
	if (!(parse_color(token_array[2], &ambient->obj_prop.ambient.color)))
	{
		free(ambient);
		return (AMB_COL_ERR);
	}
	ft_lstadd_front(obj_lst, ft_lstnew(ambient));
	return (NO_ERROR);
}
