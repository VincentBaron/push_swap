# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 17:56:46 by vbaron            #+#    #+#              #
#    Updated: 2021/08/17 15:18:41 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


DIR_S = srcs
DIR_O = objs

SOURCES = program_main.c \
		display_stacks.c \
		create_stacks.c \
		sa_sb_ss_operations.c \
		ra_rb_rr_operations.c \
		rra_rrb_rrr_operations.c \
		pa_pb_operations.c \
		less_than_three.c \
		utils.c \
		calculate_pos.c \
		less_than_five.c \
		more_than_five.c \

		

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
HEADERS = headers
LIBFT_DIR = libft

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

CC = gcc

LIBFT = $(addprefix $(LIBFT_DIR)/,libft.a)

all: $(LIBFT) $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)	
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
		 make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJS)		
	rm -f $(OBJS)/*.o
	rm -rf $(DIR_O)	
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: re fclean all clean