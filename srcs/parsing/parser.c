/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:33:48 by rotrojan          #+#    #+#             */
/*   Updated: 2020/03/03 05:53:38 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		count_elems(t_list **obj_lst, t_nb_elem *to_malloc)
{
	if (((t_object*)((*obj_lst)->content))->obj_type == CAMERA)
		to_malloc->nb_cameras++;
	else if (((t_object*)((*obj_lst)->content))->obj_type == LIGHT)
		to_malloc->nb_lights++;
	else if (((t_object*)((*obj_lst)->content))->obj_type != RESOLUTION
		&& ((t_object*)((*obj_lst)->content))->obj_type != AMBIENT)
		to_malloc->nb_objects++;
}

static t_error	parse_line(char ***token_array, char **current_line,
										t_list **obj_lst, t_nb_elem *to_malloc)
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
	if ((error = select_sub_parser(token, *token_array, obj_lst)) != NO_ERROR)
		return (error);
	free_array((void*)*token_array);
	free(*current_line);
	count_elems(obj_lst, to_malloc);
	return (NO_ERROR);
}

static t_error	parser(int fd, t_list **obj_lst, t_nb_elem *to_malloc)
{
	int			ret_gnl;
	t_error		error;
	char		*current_line;
	char		**token_array;

	current_line = NULL;
	ft_bzero(to_malloc, sizeof(*to_malloc));
	while ((ret_gnl = get_next_line(fd, &current_line)) > 0)
	{
		if ((error = parse_line(&token_array, &current_line, obj_lst,
			to_malloc)) != NO_ERROR)
			return (error);
	}
	if (to_malloc->nb_cameras < 1)
		return (NB_CAM_ERR);
	if (ret_gnl == -1)
		return (READ_ERR);
	free(current_line);
	return (NO_ERROR);
}

t_error			open_and_parse_file(int ac, char **av, t_scene *scene,
																	t_mlx *mlx)
{
	t_list		*obj_lst;
	int			fd;
	t_error		ret;
	t_nb_elem	to_malloc;

	obj_lst = NULL;
	if ((ret = check_args(ac, av)) != NO_ERROR)
		return (ret);
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if ((ret = parser(fd, &obj_lst, &to_malloc)))
			return (ret);
		close(fd);
	}
	else
		return (OPENING_ERR);
/*	t_list *current;
	current = obj_lst;
	while (current)
	{
		printf("type = %d\n", ((t_object*)current->content)->obj_type);
		if (((t_object*)current->content)->obj_type == SPHERE)
		{
			printf("%p\n", ((t_object*)current->content));
			printf("== Sphere ==\n");
			printf("position : x = %f, y = %f, z = %f\n",
				((t_object*)current->content)->position.x, ((t_object*)current->content)->position.y,
				((t_object*)current->content)->position.z);
			printf("radius : %f\n", ((t_object*)current->content)->obj_prop.sphere.radius);
			printf("\n");
		}
		current = current->next;
	}
*/	if ((ret = from_lst_to_struct(&obj_lst, scene, mlx, to_malloc)) != NO_ERROR)
		return (ret);
	ft_lstclear(&obj_lst, &free);
	return (NO_ERROR);
}
