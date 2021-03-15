/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:33:48 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/15 17:00:30 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Each line is split into tokens gathered in an array. Then the proper
** sub-parser is selected by the select_sub_parser function.
*/

static t_error	parse_line(char ***token_array, char **current_line,
																t_main *main)
{
	t_type		token;
	t_error		error;

	if (!**current_line)
	{
		free(*current_line);
		current_line = NULL;
		return (NO_ERROR);
	}
	if (!(*token_array = ft_split_whitespaces(*current_line)))
		return (MALLOC_ERR);
	if ((token = get_sub_parser(*token_array[0])) == TYPE_ERROR)
		return (WRONG_ELEM_ERR);
	if ((error = select_sub_parser(token, *token_array, main))
		!= NO_ERROR)
		return (error);
	free_array((void*)*token_array);
	free(*current_line);
	return (NO_ERROR);
}

/*
** Each line is parsed individually by the parse_line function. The error check
** is made progressively during the parsing.
** Here is why the Ambient lighting was set to -1.
** The chain-linked list of cameras is made circular to make it easier to switch
** cameras.
*/

static t_error	parser(int fd, t_main *main)
{
	int			ret_gnl;
	t_error		error;
	char		*current_line;
	char		**token_array;

	current_line = NULL;
	while ((ret_gnl = get_next_line(fd, &current_line)) > 0)
	{
		if ((error = parse_line(&token_array, &current_line, main))
			!= NO_ERROR)
			return (error);
	}
	if (!main->scene.cam_lst)
		return (NB_CAM_ERR);
	if (ret_gnl == -1)
		return (READ_ERR);
	free(current_line);
	if (main->mlx.win_width == 0 && main->mlx.win_height == 0)
		return (RES_MISS_ERR);
	if (main->scene.ambient.ratio == -1.0)
		return (AMB_MISS_ERR);
	ft_lstlast(main->scene.cam_lst)->next = main->scene.cam_lst;
	return (NO_ERROR);
}

/*
** The arguments and the .rt file are verified by the check_args function. It it
** is ok, the parser function is called.
*/

t_error			open_and_parse_file(int ac, char **av, t_main *main)
{
	int			fd;
	t_error		ret;

	if ((ret = check_args(ac, av)) != NO_ERROR)
		return (ret);
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if ((ret = parser(fd, main)))
			return (ret);
		close(fd);
	}
	else
		return (OPENING_ERR);
	return (NO_ERROR);
}
