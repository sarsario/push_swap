LIBC_DIR = Libc
PRINTF_DIR = Printf
STRING_MANIP = String\ Manipulation
OBJ_DIR = obj
BONUS_DIR = Bonus

SRCS = $(wildcard \
	$(addsuffix /*.c,$(LIBC_DIR)) \
	$(addsuffix /*.c,$(PRINTF_DIR)) \
	$(addsuffix /*.c,$(STRING_MANIP)) \
)
SRCS_BONUS = $(wildcard $(addsuffix /*.c,$(BONUS_DIR)))
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))
NAME = libft.a

AR = ar rcs
RM = rm -f

CC = cc
CFLAGS = -Wall -Wextra -Werror

vpath %.c $(LIBC_DIR) $(STRING_MANIP) $(PRINTF_DIR) $(BONUS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus