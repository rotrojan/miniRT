# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 02:53:19 by rotrojan          #+#    #+#              #
#    Updated: 2021/01/21 13:41:18 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### SOURCES ####################################

SRCS_DIR		=	./srcs/
SRCS 			=	normalized_vector.c norm_square_vector.c get_vector.c	\
					norm_vector.c dot_vectors.c cross_vectors.c vec_matrix.c
OBJS			=	${SRCS:%.c=${OBJS_DIR}%.o}
DEPENDENCIES	=	${OBJS:.o=.d}

################################ MISCELLANEOUS #################################

INCLUDES_DIR	=	./includes/
OBJS_DIR		=	./.objs/

CFLAGS			+=	-Wall -Wextra -Werror -MMD -mavx
CXXFLAGS		+=	${INCLUDES_DIR:%=-I%}

NAME			=	libvectors.a

##################################### BIN ######################################

CC				=	clang
AR				=	ar rcs
MKDIR			=	mkdir -p

#################################### RULES #####################################

vpath %.c ${SRCS_DIR}

all		:
	${MAKE} -j ${NAME}

${NAME}	:	${OBJS}
	${AR} $@ $^

-include ${DEPENDENCIES}
${OBJS_DIR}%.o : %.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< ${CXXFLAGS} -o $@

${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}

clean	:
	${RM} -r ${OBJS_DIR}

fclean	:
	${MAKE} clean
	${RM} ${NAME}

re		:
	${MAKE} fclean
	${MAKE} all

.PHONY	:			re			\
					all			\
					clean		\
					fclean
