LIBFT_PATH = ./Lib
LIBFT = $(LIBFT_PATH)/libft.a
VLDN = Validation
STACK = Stack
ALGO = SortingAlgorithm
OBJ_DIRS = $(VLDN) $(STACK) $(ALGO)
SRCS = $(VLDN)/ft_is_int.c $(VLDN)/ft_parse.c $(STACK)/ft_stack.c\
	$(STACK)/ft_push.c $(STACK)/ft_swap.c $(STACK)/ft_rotate.c\
	$(STACK)/ft_reverse_rotate.c $(STACK)/ft_find.c $(ALGO)/combined_logic.c\
	$(ALGO)/sort_under_seven.c $(ALGO)/ft_cost.c $(ALGO)/ft_cost2.c\
	$(ALGO)/efficient_move.c $(ALGO)/lis_sort.c $(ALGO)/ft_sort.c push_swap.c
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LDFLAGS = -L$(LIBFT_PATH) -lft

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(OBJ_DIR)/$(VLDN))
$(shell mkdir -p $(OBJ_DIR)/$(STACK))
$(shell mkdir -p $(OBJ_DIR)/$(ALGO))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -O3 -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

debug: CFLAGS += -fsanitize=address -g3
debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

lldb: CFLAGS += -g3
lldb: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re