# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 22:47:50 by rotrojan          #+#    #+#              #
#    Updated: 2020/01/24 04:37:02 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		=	./srcs/
OBJS_DIR		=	./.objs/
INCLUDES_DIR	=	./includes/ ./libmlx/
SRCS			=	main.c colors_and_geometrics.c mlx_utils.c	drawings.c \
					mlx_hooks.c vectors1.c vectors2.c ray_tracer.c

OBJS			:=	${SRCS:%.c=${OBJS_DIR}%.o}

NAME			=	minirt

DEPENDENCIES	=	${OBJS:.o=.d}

CC				=	clang
MKDIR			=	mkdir -p

LIBS			=	mlx ft
FRAMEWORKS		=	OpenGL AppKit

CFLAGS			+=	-Wall -Wextra -Werror -MMD
LDFLAGS			+=	${FRAMEWORKS:%=-framework %}
CXXFLAGS		+=	${INCLUDES_DIR:%=-I%}

vpath %.c ${SRCS_DIR}
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



