NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./src/main.c ./src/struct_utils.c ./src/fill_stacks.c ./src/utils.c \
		./src/ft_split.c ./src/validation.c ./src/print_stack.c ./src/swap.c \
		./src/push.c ./src/sorting.c ./src/rotate.c ./src/moved_value.c ./src/find_smallest.c \
		./src/greatest_value.c ./src/move_smallest.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
