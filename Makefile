CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 

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
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re