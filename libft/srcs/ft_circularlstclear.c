/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circularlstclear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:32:34 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 15:19:25 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_circularlstclear(t_list **lst, void (*del)(void*))
{
	t_list		*tmp;
	t_list		*next_link;
	int			lst_size;

	if (*lst && del)
	{
		tmp = *lst;
		lst_size = 1;
		(*lst) = (*lst)->next;
		while (*lst != tmp)
		{
			lst_size++;
			(*lst) = (*lst)->next;
		}
		while (lst_size--)
		{
			next_link = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = next_link;
		}
		*lst = NULL;
	}
}
