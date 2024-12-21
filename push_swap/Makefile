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
				next2.c
				
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
