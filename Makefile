# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 09:48:42 by zamohame          #+#    #+#              #
#    Updated: 2025/01/24 17:38:06 by zamohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ../greg_lib
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft

SRC = push_swap.c \
      push_swap_utils.c \
	  push_swap_utils_bis.c \
	  push_swap_sort.c \
      push.c \
      swap.c \
      rotate.c \
      reverse_rotate.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
