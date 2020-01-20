# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 22:47:50 by rotrojan          #+#    #+#              #
#    Updated: 2020/01/20 22:44:04 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		=	./srcs/
OBJS_DIR		=	./.objs/
INCLUDES_DIR	=	./includes/ ./libmlx/
SRCS			=	main.c colors_and_geometrics.c drawings.c mlx_utils.c	\
					mlx_hooks.c

OBJS			:=	${SRCS:%.c=${OBJS_DIR}%.o}

NAME			=	minirt

DEPENDENCIES	=	${OBJS:.o=.d}

CC				=	clang
MKDIR			=	mkdir -p

LIBS			=	mlx
FRAMEWORKS		=	OpenGL AppKit

CFLAGS			+=	-Wall -Wextra -Werror -MMD
LDFLAGS			+=	${FRAMEWORKS:%=-framework %}
CXXFLAGS		+=	${INCLUDES_DIR:%=-I%}

vpath %.c ./srcs/
vpath %.a ${LIBS:%=lib%}

all				:
	@$(foreach LIB, ${LIBS}, @echo building lib${LIB}; ${MAKE} -j -C lib${LIB};)
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



