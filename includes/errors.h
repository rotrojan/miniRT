/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:48:35 by rotrojan          #+#    #+#             */
/*   Updated: 2021/03/17 01:25:41 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file list all possible errors and the corresponding displayed messages.
*/

#ifndef ERRORS_H
# define ERRORS_H
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
# define PL_POS_FMT_ERR_STR "Plane position not well formatted."
# define PL_COL_FMT_ERR_STR "Plane color not well formatted."
# define PL_ORIENT_FMT_ERR_STR "Plane orientation not well formatted."
# define PL_FMT_ERR_STR "Plane not well formatted."
# define SQ_POS_FMT_ERR_STR "Square position not well formatted."
# define SQ_COL_FMT_ERR_STR "Square color not well formatted."
# define SQ_ORIENT_FMT_ERR_STR "Square orientation not well formatted."
# define SQ_LEN_FMT_ERR_STR "Square size not well formatted."
# define SQ_FMT_ERR_STR "Square not well formatted."
# define CY_POS_FMT_ERR_STR "Cylinder position not well formatted."
# define CY_COL_FMT_ERR_STR "Cylinder color not well formatted."
# define CY_ORIENT_FMT_ERR_STR "Cylinder orientation not well formatted."
# define CY_DIAM_FMT_ERR_STR "Cylinder diameter not well formatted."
# define CY_HGHT_FMT_ERR_STR "Cylinder height not well formatted."
# define CY_FMT_ERR_STR "Cylinder not well formatted."
# define TR_COL_FMT_ERR_STR "Triangle color not well formatted."
# define TR_VER_FMT_ERR_STR "Triangle vertice not well formatted."
# define TR_FMT_ERR_STR "Triangle not well formatted."
# define RES_X_FMT_ERR_STR "Resolution width not well formatted."
# define RES_Y_FMT_ERR_STR "Resolution height not well formatted."
# define RES_MISS_ERR_STR "Resolution missing."
# define RES_TWICE_ERR_STR "Resolution can only be set once."
# define RES_FMT_ERR_STR "Resolution not well formatted."
# define AMB_MISS_ERR_STR "Ambient lighting missing."
# define AMB_TWICE_ERR_STR "Ambient lighting can only be set once."
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
# define LIGHT_COL_ERR_STR "Light color not well formatted."
# define NB_CAM_ERR_STR "There must be at least one camera."
# define BMP_ERR_STR "Bitmap file creation failure."
# define MLX_HOOKS_ERR_STR "Hooks initialization failure."

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
	PL_POS_FMT_ERR,
	PL_COL_FMT_ERR,
	PL_ORIENT_FMT_ERR,
	PL_FMT_ERR,
	SQ_POS_FMT_ERR,
	SQ_COL_FMT_ERR,
	SQ_ORIENT_FMT_ERR,
	SQ_LEN_FMT_ERR,
	SQ_FMT_ERR,
	CY_POS_FMT_ERR,
	CY_COL_FMT_ERR,
	CY_ORIENT_FMT_ERR,
	CY_DIAM_FMT_ERR,
	CY_HGHT_FMT_ERR,
	CY_FMT_ERR,
	TR_COL_FMT_ERR,
	TR_VER_FMT_ERR,
	TR_FMT_ERR,
	RES_X_FMT_ERR,
	RES_Y_FMT_ERR,
	RES_MISS_ERR,
	RES_TWICE_ERR,
	RES_FMT_ERR,
	AMB_MISS_ERR,
	AMB_TWICE_ERR,
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
	LIGHT_COL_ERR,
	NB_CAM_ERR,
	BMP_ERR,
	MLX_HOOKS_ERR
}				t_error;

#endif
