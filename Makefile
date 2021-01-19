# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 22:47:50 by rotrojan          #+#    #+#              #
#    Updated: 2021/01/19 13:16:06 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR			=	./srcs/
OBJS_DIR			=	./.objs/
INCLUDES_DIR		=	./includes/ ${LIBS:%=lib%/includes}
SRCS				=	main.c mlx_utils.c mlx_hooks.c						\
																			\
						parser.c parse_utils.c								\
						parse_data.c										\
						parse_resolution.c parse_ambient.c					\
						parse_camera.c parse_light.c						\
						parse_sphere.c parse_plane.c parse_cylinder.c		\
						parse_square.c parse_triangle.c						\
																			\
						ray_tracer.c utils.c intersection.c screenshot.c

OBJS				:=	${SRCS:%.c=${OBJS_DIR}%.o}

NAME				=	miniRT

DEPENDENCIES		=	${OBJS:.o=.d}

CC					=	clang
MKDIR				=	mkdir -p

LIBS				=	ft vectors
FRAMEWORKS			=	OpenGL AppKit
CFLAGS				+=	-Wall -Wextra -MMD -mavx#-Werror
CXXFLAGS			+=	${INCLUDES_DIR:%=-I%}

OS					=	$(shell uname)
ifeq (${OS}, Darwin)
MLX_DIR				=	./minilibx_opengl_20191021/
OS_FLAGS			+=	${FRAMEWORKS:%=-framework %}
endif
ifeq (${OS}, Linux)
MLX_DIR				=	./minilibx-linux/
OS_FLAGS			+=	-lm -lXext -lX11
endif
LDFLAGS				+=	-L ${MLX_DIR} -lmlx ${OS_FLAGS}
DEBUGFLAGS			=	-g3 -fsanitize=address
NODEPRECATEDFLAGS	= 	-Wno-deprecated-declarations

MLX					= ${MLX_DIR}libmlx.a

vpath %.c ${SRCS_DIR} ${SRCS_DIR}parsing ${SRCS_DIR}mlx
vpath %.a ${LIBS:%=lib%} ${MLX_DIR}

all				:
	@$(foreach LIB, ${LIBS}, echo '\x1b[33m' building lib${LIB}'\x1b[0m'; ${MAKE} -j -C lib${LIB};)
	@echo '\x1b[33m' building ${MLX}'\x1b[0m';
	CFLAGS+="${NODEPRECATEDFLAGS}" ${MAKE} -j -C ${MLX_DIR}
	@${MAKE} -j ${NAME}

${NAME}			:	${OBJS} ${LIBS:%=lib%.a} ${MLX}
	${CC} -o $@ $^ ${LDFLAGS} ${CXXFLAGS}

${OBJS_DIR}%.o	:	%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< ${CXXFLAGS} -o $@

lib%.a			:
	@${MAKE} -j -C ${@:%.a=%}

${MLX}			:
	@CFLAGS+="${NODEPRECATEDFLAGS}" ${MAKE} -j -C ${MLX_DIR}

debug			:
	@${MAKE} fclean
	@CXXFLAGS+="${DEBUGFLAGS}" ${MAKE} all

${OBJS_DIR}		:
	${MKDIR} ${OBJS_DIR}

clean			:
	@$(foreach LIB, ${LIBS}, ${MAKE} clean -C lib${LIB};)
	${MAKE} clean -C ${MLX_DIR}
	${RM} -r ${OBJS_DIR}

fclean			:
	@${MAKE} clean
	${RM} ${NAME} $(foreach LIB, ${LIBS}, lib${LIB}/lib${LIB}.a)

re				:
	@${MAKE} fclean
	@${MAKE} all

.PHONY			:		all clean fclean re
