SRCS =  ./mandatory/push.c ./mandatory/rotate.c ./mandatory/swaps.c ./mandatory/reverse_rotate.c  ./mandatory/stack_utils.c  ./mandatory/small_sort.c ./mandatory/utils.c  ./mandatory/push_swap.c ./mandatory/tools_stack.c ./mandatory/big_sort.c ./mandatory/range_tools.c ./mandatory/atoi.c

SRCS_BONUS = ./bonus/push_bonus.c ./bonus/rotate_bonus.c ./bonus/swaps_bonus.c ./bonus/reverse_rotate_bonus.c ./bonus/stack_utils_bonus.c ./bonus/checker_bonus.c \
	./bonus/atoi_bonus.c ./bonus/tools_bonus.c ./bonus/utils_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
