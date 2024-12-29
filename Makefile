# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/27 09:22:19 by brogalsk          #+#    #+#              #
#    Updated: 2024/12/27 09:22:22 by brogalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc

CFLAGS	=	-g -Wall -Wextra -Werror

INCLUDE	=	-I.

SRCS	=	push_swap.c \
				instruction.c \
				funtion.c \
				list_operation.c \
				next.c \
				help_function2.c \
				help_funtion.c \
				next2.c \
				utils.c
				
OBJS	=	${SRCS:.c=.o}

LIBPATH	=	libft/

all:		${NAME}

${NAME}:	${OBJS} 
			make -C ${LIBPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIBPATH}libft.a -o ${NAME}

# ${LIBPATH}libft.a:
# 			make -C ${LIBPATH}

clean:
			make clean -C ${LIBPATH}
			rm -f ${OBJS}
fclean:		clean
			make fclean -C ${LIBPATH}
			rm -f ${NAME}

re:				fclean all

.PHONY:		all clean fclean re ${LIBPATH}libft.a
