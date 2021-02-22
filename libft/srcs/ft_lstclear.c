/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:32:34 by rotrojan          #+#    #+#             */
/*   Updated: 2021/02/17 16:33:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*tmp;
	t_list		*next_link;
	t_list		*head_lst;

	if (*lst && del)
	{
		tmp = *lst;
		head_lst = *lst;
		while (tmp && tmp != head_lst)
		{
			next_link = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = next_link;
		}
		*lst = NULL;
	}
}
