# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 22:47:50 by rotrojan          #+#    #+#              #
#    Updated: 2020/02/23 17:35:34 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
SRCS_DIR		=	./srcs/
OBJS_DIR		=	./.objs/
INCLUDES_DIR	=	./includes/ ${LIBS:%=lib%/includes}
SRCS			=	main.c mlx_utils.c mlx_hooks.c ray_tracer.c		\
					check_args.c parser.c utils.c parse_objects1.c	\
					parse_objects2.c parse_utils.c

OBJS			:=	${SRCS:%.c=${OBJS_DIR}%.o}

NAME			=	minirt

DEPENDENCIES	=	${OBJS:.o=.d}

CC				=	clang
MKDIR			=	mkdir -p

LIBS			=	ft mlx vectors
FRAMEWORKS		=	OpenGL AppKit

CFLAGS			+=	-Wall -Wextra -Werror -MMD
LDFLAGS			+=	${FRAMEWORKS:%=-framework %}
CXXFLAGS		+=	${INCLUDES_DIR:%=-I%} -g3 -fsanitize=address

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



