# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 02:53:19 by rotrojan          #+#    #+#              #
#    Updated: 2021/03/18 10:08:43 by rotrojan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### SOURCES ####################################

SRCS_DIR		=	./srcs/
SRCS 			=	ft_memset.c									\
					ft_bzero.c									\
					ft_memcpy.c									\
					ft_memccpy.c								\
					ft_memmove.c								\
					ft_memchr.c									\
					ft_memcmp.c									\
					ft_strlen.c									\
					ft_strnlen.c								\
					ft_isalpha.c								\
					ft_isdigit.c								\
					ft_isalnum.c								\
					ft_isascii.c								\
					ft_isprint.c								\
					ft_toupper.c								\
					ft_tolower.c								\
					ft_strchr.c									\
					ft_strrchr.c								\
					ft_strncmp.c								\
					ft_strlcpy.c								\
					ft_strlcat.c								\
					ft_strnstr.c								\
					ft_atoi.c									\
					ft_atoll.c									\
					ft_atod.c									\
					ft_strdup.c									\
					ft_calloc.c									\
					ft_strnlen.c								\
					ft_strndup.c								\
					ft_strcmp.c									\
					ft_strstr.c									\
					ft_isspace.c								\
					ft_substr.c									\
					ft_strjoin.c								\
					ft_strtrim.c								\
					ft_split.c									\
					ft_split_whitespaces.c						\
					ft_swap.c									\
					ft_itoa.c									\
					ft_strmapi.c								\
					ft_putchar_fd.c								\
					ft_putstr_fd.c								\
					ft_putendl_fd.c								\
					ft_putnbr_fd.c								\
					ft_lstnew.c									\
					ft_lstadd_front.c							\
					ft_lstsize.c								\
					ft_lstlast.c								\
					ft_lstadd_back.c							\
					ft_lstdelone.c								\
					ft_lstclear.c								\
					ft_circularlstclear.c						\
					ft_lstiter.c								\
					ft_lstmap.c									\
					get_next_line.c
OBJS			=	${SRCS:%.c=${OBJS_DIR}%.o}
DEPENDENCIES	=	${OBJS:.o=.d}

################################ MISCELLANEOUS #################################

INCLUDES_DIR	=	./includes/
OBJS_DIR		=	./.objs/

CFLAGS			+=	-Wall -Wextra -Werror -MMD
CXXFLAGS		+=	${INCLUDES_DIR:%=-I%}

NAME			=	libft.a

##################################### BIN ######################################

CC				=	clang
AR				=	ar rcs
MKDIR			=	mkdir -p

#################################### RULES #####################################

vpath %.c ${SRCS_DIR}

all		:	${NAME}

${NAME}	:	${OBJS}
	${AR} $@ $^

-include ${DEPENDENCIES}
${OBJS_DIR}%.o : %.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< ${CXXFLAGS} -o $@

${OBJS_DIR}:
	${MKDIR} ${OBJS_DIR}

clean	:
	${RM} -r ${OBJS_DIR}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean re

.PHONY	:			re			\
					all			\
					clean		\
					fclean
