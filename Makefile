# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 09:48:42 by zamohame          #+#    #+#              #
#    Updated: 2025/02/10 10:44:23 by zamohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ../greg_lib
PRINTF_DIR = ../print_greg

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC = push_swap.c \
      push_swap_utils.c \
	  push_swap_utils_bis.c \
	  push_swap_utils_gamma.c \
	  push_swap_sort.c \
      push.c \
      swap.c \
      rotate.c \
      reverse_rotate.c

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
