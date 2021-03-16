# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 22:47:50 by rotrojan          #+#    #+#              #
#    Updated: 2021/03/16 14:43:21 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR			=	./srcs/
OBJS_DIR			=	./.objs/
INCLUDES_DIR		=	./includes/ ${LIBS:%=./lib%/includes/} ${MLX_DIR}
SRCS				=	main.c mlx_utils.c mlx_hooks.c						\
						parser.c parse_utils.c								\
						parse_colors.c parse_length.c parse_ratio.c			\
						parse_vector.c parse_orientation.c				 	\
						parse_resolution.c parse_ambient.c					\
						parse_camera.c parse_light.c						\
						parse_sphere.c parse_plane.c parse_cylinder.c		\
						parse_square.c parse_triangle.c						\
						ray_tracer.c shader.c normal.c solve_quadratic.c	\
						sphere_intersection.c plane_intersection.c			\
						cylinder_intersection.c square_intersection.c		\
						triangle_intersection.c								\
						utils.c screenshot.c colors_utils.c					\
						square_intersection.c cylinder_intersection.c
OBJS				:=	${SRCS:%.c=${OBJS_DIR}%.o}

NAME				=	miniRT

DEPENDENCIES		=	${OBJS:.o=.d}

CC					=	clang
MKDIR				=	mkdir -p
LIBS				=	ft vectors
CFLAGS				+=	-Wall -Wextra -Werror -MMD -g3
CXXFLAGS			+=	${INCLUDES_DIR:%=-I%}

MLX_DIR				=	./minilibx-linux/
OS_FLAGS			+=	-lm -lXext -lX11
LDFLAGS				+=	-L ${MLX_DIR} -lmlx ${OS_FLAGS}

MLX					=	${MLX_DIR}libmlx.a

vpath %.c ${SRCS_DIR} ${SRCS_DIR}mlx										\
${SRCS_DIR}raytracing	${SRCS_DIR}raytracing/intersections					\
${SRCS_DIR}parsing ${SRCS_DIR}parsing/data_parsers							\
${SRCS_DIR}parsing/object_parsers
vpath %.a ${LIBS:%=lib%} ${MLX_DIR}
vpath %.h ${INCLUDES_DIR}

all					:
	@$(foreach LIB, ${LIBS}, echo -e '\x1b[33m'building lib${LIB}'\x1b[0m' && ${MAKE} -j -C lib${LIB} &)
	@echo -e '\x1b[33m'building ${MLX}'\x1b[0m'
	${MAKE} -C ${MLX_DIR}
	@${MAKE} -j ${NAME}

${NAME}				:	${OBJS} ${LIBS:%=lib%.a} ${MLX}
	@echo -e '\x1b[33m'building ${NAME}'\x1b[0m'
	${CC} -o $@ $^ ${LDFLAGS} ${CXXFLAGS}
	@echo -e'\x1b[33m' && cat header

-include ${DEPENDENCIES}
${OBJS_DIR}%.o		:	%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< ${CXXFLAGS} -o $@

lib%.a				:
	@${MAKE} -j -C  ${@:%.a=%}

libmlx.a			:
	@CFLAGS+="${NODEPRECATEDFLAGS}" CC="clang" ${MAKE} -j -C ${MLX_DIR}

${OBJS_DIR}			:
	@echo -e '\x1b[33m'building objects and dependencies${LIB}'\x1b[0m'
	${MKDIR} ${OBJS_DIR}

clean				:
	@$(foreach LIB, ${LIBS}, ${MAKE} clean -C lib${LIB};)
	${MAKE} clean -C ${MLX_DIR}
	${RM} -r ${OBJS_DIR}

fclean				:	clean
	${RM} ${NAME} $(foreach LIB, ${LIBS}, lib${LIB}/lib${LIB}.a)

re					:	fclean all

.PHONY				:	all clean fclean re
