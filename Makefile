LIBFT_PATH = ./includes/lib
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = push_swap.c src/ft_free.c src/ft_sanitize.c src/ft_split_whitespaces.c\
	src/ft_stack.c src/ft_valid_args.c src/ft_push.c src/ft_swap.c\
	src/ft_rotate.c src/ft_reverse_rotate.c src/ft_sort.c src/ft_value.c\
	src/ft_push_pivot.c src/combined_moves.c src/ft_sort_hundred.c\
	src/ft_cost.c src/ft_r_n.c src/ft_rr_n.c src/efficient_move.c\
	src/ft_min_max.c
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LDFLAGS = -L$(LIBFT_PATH) -lft
BONUS_NAME = checker
BONUS_SRCS = checker.c src/ft_free.c src/ft_sanitize.c\
	src/ft_split_whitespaces.c src/ft_stack.c src/ft_valid_args.c src/ft_push.c\
	src/ft_swap.c src/ft_rotate.c src/ft_reverse_rotate.c bonus/ft_is_sorted.c\
	bonus/ft_read_instructions.c bonus/ft_exec_instruction.c\
	bonus/get_next_line.c
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(OBJ_DIR)/src)
$(shell mkdir -p $(OBJ_DIR)/bonus)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -O3 -o $(NAME) $(OBJS) $(LDFLAGS)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -O3 -o $(BONUS_NAME) $(BONUS_OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

debug: CFLAGS += -fsanitize=address -g3
debug: fclean $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

lldb: CFLAGS += -g3
lldb: fclean $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

lldb_bonus: CFLAGS += -g3
lldb_bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus