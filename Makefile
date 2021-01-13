# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 22:47:50 by rotrojan          #+#    #+#              #
#    Updated: 2021/01/12 15:09:36 by bigo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
SRCS_DIR		=	./srcs/
OBJS_DIR		=	./.objs/
INCLUDES_DIR	=	./includes/ ${LIBS:%=lib%/includes} /usr/include/X11/mlx/
SRCS			=	main.c mlx_utils.c mlx_hooks.c						\
																		\
					parser.c parse_utils.c								\
					parse_data.c										\
					parse_resolution.c parse_ambient.c					\
					parse_camera.c parse_light.c						\
					parse_sphere.c parse_plane.c parse_cylinder.c		\
					parse_square.c parse_triangle.c						\
																		\
					ray_tracer.c utils.c intersection.c screenshot.c

OBJS			:=	${SRCS:%.c=${OBJS_DIR}%.o}

NAME			=	minirt

DEPENDENCIES	=	${OBJS:.o=.d}

CC				=	clang
MKDIR			=	mkdir -p

LIBS			=	ft vectors
#FRAMEWORKS		=	OpenGL AppKit

CFLAGS			+=	-Wall -Wextra -MMD -mavx# -Werror
#LDFLAGS			+=	${FRAMEWORKS:%=-framework %} -L /usr/local/lib -lmlx
LDFLAGS			+=	/usr/lib/X11/libmlx.a -lm -lXext -lX11
CXXFLAGS		+=	${INCLUDES_DIR:%=-I%} #-g3 -fsanitize=address

vpath %.c ${SRCS_DIR} ${SRCS_DIR}parsing ${SRCS_DIR}mlx
vpath %.a ${LIBS:%=lib%}

all				:
	@$(foreach LIB, ${LIBS}, echo '\x1b[33m' building lib${LIB}'\x1b[0m'; ${MAKE} -j -C lib${LIB};)
	@${MAKE} -j ${NAME}

${NAME}			:	${OBJS} ${LIBS:%=lib%.a}
	${CC} -o $@ $^ ${LDFLAGS} ${CXXFLAGS}

-include ${DEPENDENCIES}
${OBJS_DIR}%.o	:	%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< ${CXXFLAGS} -o $@

lib%.a			:
	@${MAKE} -j -C ${@:%.a=%}

${OBJS_DIR}		:
	${MKDIR} ${OBJS_DIR}

clean			:
	@$(foreach LIB, ${LIBS}, ${MAKE} clean -C lib${LIB};)
	${RM} -r ${OBJS_DIR}

fclean			:
	@${MAKE} clean
	${RM} ${NAME} $(foreach LIB, ${LIBS}, lib${LIB}/lib${LIB}.a)

re				:
	@${MAKE} fclean
	@${MAKE} all

.PHONY			:		all clean fclean re
