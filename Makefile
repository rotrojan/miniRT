# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 22:47:50 by rotrojan          #+#    #+#              #
#    Updated: 2021/03/18 10:47:21 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE				=	make
SRCS_DIR			=	./srcs/
OBJS_DIR			=	./.objs/
INCLUDES_DIR		=	./includes/ ${LIBS:%=./lib%/includes/} ${MLX_DIR}
SRCS				=	main.c mlx_utils.c mlx_hooks.c						\
						parser.c parse_utils.c check_number.c				\
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
CFLAGS				+=	-Wall -Wextra -Werror -MMD
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
	$(foreach LIB, ${LIBS}, ${MAKE} -C lib${LIB} &)
	@${MAKE} -C ${MLX_DIR} 2> /dev/null
	@${MAKE} ${NAME}

${NAME}				:	${OBJS} ${LIBS:%=lib%.a} ${MLX}
	@${CC} -o $@ $^ ${LDFLAGS} ${CXXFLAGS}
	@cat README

-include ${DEPENDENCIES}
${OBJS_DIR}%.o		:	%.c | ${OBJS_DIR}
	@${CC} ${CFLAGS} -c $< ${CXXFLAGS} -o $@

lib%.a				:
	@${MAKE} -C  ${@:%.a=%}

${MLX}				:
	@${MAKE} -C ${MLX_DIR} > /dev/null

${OBJS_DIR}			:
	@echo building objects and dependencies${LIB}
	@${MKDIR} ${OBJS_DIR}

clean				:
	@$(foreach LIB, ${LIBS}, ${MAKE} clean -C lib${LIB};)
	@echo cleaning sources
	@${MAKE} clean -C ${MLX_DIR} 2> /dev/null
	@${RM} -r ${OBJS_DIR}

fclean				:	clean
	@echo cleaning executable
	${RM} ${NAME} $(foreach LIB, ${LIBS}, lib${LIB}/lib${LIB}.a)

re					:	fclean all

.PHONY				:	all clean fclean re
.SILENT				:	all clean fclean re ${NAME}
