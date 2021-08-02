# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 17:56:46 by vbaron            #+#    #+#              #
#    Updated: 2021/08/02 16:36:25 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


DIR_S = srcs
DIR_O = objs

SOURCES = program_main.c \
		display_stacks.c \
		create_stacks.c \
		# sa_sb_ss_operations.c \
		# do_operation.c \
		# ra_rb_rr_operations.c \
		# rra_rrb_rrr_operations.c \

		

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
HEADERS = headers
LIBFT_DIR = libft
PRINTF_DIR = printf

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

LIBFT = $(addprefix $(LIBFT_DIR)/,libft.a)
PRINTF = $(addprefix $(PRINTF_DIR)/,printf.a)

all: $(LIBFT) $(PRINTF) $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)	
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
		 make -C $(LIBFT_DIR)

$(PRINTF):
		make -C $(PRINTF_DIR)

clean:
		rm -f $(OBJS)		
	rm -f $(OBJS)/*.o
	rm -rf $(DIR_O)	
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: re fclean all clean