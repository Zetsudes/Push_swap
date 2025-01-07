LIBFT_DIR = ./greg_lib

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SRC = push_swap.c \
		push_swap_utils.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
