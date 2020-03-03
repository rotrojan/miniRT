/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:48:35 by rotrojan          #+#    #+#             */
/*   Updated: 2020/02/28 22:24:24 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# define NO_ERROR_STR ""
# define NB_ARGS_ERR_STR "Wrong number of arguments."
# define OPENING_ERR_STR "Cannot open file."
# define FILE_EXTENSION_ERR_STR "Invalid file extension."
# define THIRD_ARG_ERR_STR "Invalid third argument."
# define READ_ERR_STR "Cannot read file."
# define MALLOC_ERR_STR "Malloc failure."
# define WRONG_ELEM_ERR_STR "Element not well formatted."
# define SP_POS_FMT_ERR_STR "Sphere position not well formatted."
# define SP_COL_FMT_ERR_STR "Sphere color not well formatted."
# define SP_LEN_FMT_ERR_STR "Sphere radius not well formatted."
# define SP_FMT_ERR_STR "Sphere not well formatted."
# define RES_X_FMT_ERR_STR "Resolution width not well formatted."
# define RES_Y_FMT_ERR_STR "Resolution height not well formatted."
# define RES_TWICE_ERR_STR "Resolution can only be set once."
# define RES_FMT_ERR_STR "Resolution not well formatted."
# define AMB_FMT_ERR_STR "Ambient lighting not well formatted."
# define AMB_RATIO_ERR_STR "Ambient lighting ratio not well formatted."
# define AMB_COL_ERR_STR "Ambient lighting color not well formatted."
# define CAM_ERR_STR "Camera not well formatted."
# define CAM_POS_ERR_STR "Camera position not well formatted."
# define CAM_ORIENT_ERR_STR "Camera orientation not well formatted."
# define CAM_FOV_ERR_STR "Camera field of view not well formatted."
# define LIGHT_ERR_STR "Light not well formatted."
# define LIGHT_POS_ERR_STR "Light position not well formatted."
# define LIGHT_INTENS_ERR_STR "Light intensity not well formatted."
# define NB_CAM_ERR_STR "There must be at least one camera."

typedef enum	e_error
{
	NO_ERROR,
	NB_ARGS_ERR,
	OPENING_ERR,
	FILE_EXTENSION_ERR,
	THIRD_ARG_ERR,
	READ_ERR,
	MALLOC_ERR,
	WRONG_ELEM_ERR,
	SP_POS_FMT_ERR,
	SP_COL_FMT_ERR,
	SP_LEN_FMT_ERR,
	SP_FMT_ERR,
	RES_X_FMT_ERR,
	RES_Y_FMT_ERR,
	RES_TWICE_ERR,
	RES_FMT_ERR,
	AMB_FMT_ERR,
	AMB_RATIO_ERR,
	AMB_COL_ERR,
	CAM_ERR,
	CAM_POS_ERR,
	CAM_ORIENT_ERR,
	CAM_FOV_ERR,
	LIGHT_ERR,
	LIGHT_POS_ERR,
	LIGHT_INTENS_ERR,
	NB_CAM_ERR
}				t_error;

#endif
