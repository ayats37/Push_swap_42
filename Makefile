SRCS =  ./mandatory/push.c ./mandatory/rotate.c ./mandatory/swaps.c ./mandatory/reverse_rotate.c  ./mandatory/stack_utils.c  ./mandatory/utils.c ./mandatory/small_sort.c ./mandatory/push_swap.c ./mandatory/tools_stack.c ./mandatory/big_sort.c
SRCS_BONUS = 

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re 
