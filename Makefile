LIBFT_PATH = ./Lib
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = Validation/ft_is_int.c Validation/ft_parse.c Stack/ft_stack.c\
	Stack/ft_plate.c Stack/ft_push.c Stack/ft_swap.c Stack/try_ss.c\
	Stack/ft_rotate.c Stack/try_rr.c Stack/ft_reverse_rotate.c Stack/try_rrr.c\
	SortingAlgorithm/optimized_push.c SortingAlgorithm/sort_five.c\
	SortingAlgorithm/longest_sequence.c SortingAlgorithm/ft_sort.c\
	push_swap.c
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LDFLAGS = -L$(LIBFT_PATH) -lft

$(shell mkdir -p $(OBJ_DIR))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

debug: CFLAGS += -fsanitize=address -g
debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re