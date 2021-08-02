# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/28 17:52:53 by vbaron            #+#    #+#              #
#    Updated: 2021/08/02 10:39:04 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		srcs/ft_printf.c \
			srcs/conversion_functions_1.c \
			srcs/conversion_functions_2.c \
			srcs/general_functions_1.c \
			srcs/general_functions_2.c \
			srcs/general_functions_3.c \

OBJS = 		${SRC:.c=.o}

INCLUDES = 	includes

NAME = 		printf.a

CC = 		gcc

FLAGS =  	-Wall -Werror -Wextra

all:		${NAME}

-c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

${NAME}: 	${OBJS}
			# make -C Libft
			# cp Libft/libft.a ./$(NAME)
			ar -rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}
			# make clean -C Libft

fclean: 	clean
			rm -f ${NAME}
			# make fclean -C Libft

re: 		fclean all

.PHONY: clean all fclean re