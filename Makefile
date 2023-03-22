# Files
NAME	= push_swap
LIBFT	= ./libft/libft.a
SRC		= ./src/push_swap.c ./src/action_push.c ./src/action_reverse.c ./src/action_rotate.c ./src/action_swap.c ./src/swap_utils.c ./src/t_list.c 
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

# Colors
BOLD = \033[1m
BLACK = \033[30;1m
RED = \033[31;1m
GREEN = \033[32;1m
YELLOW = \033[33;1m
BLUE = \033[34;1m
MAGENTA = \033[35;1m
CYAN = \033[36;1m
WHITE = \033[37;1m
RESET = \033[0m

# Targets
all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(MAGENTA) $(BOLD)✨Compilation Done✨$(RESET)"

$(LIBFT): 
		@$(MAKE) -C ./libft

# Clean
clean:
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)
		@echo "$(GREEN)✅ Done ✅$(RESET)"

fclean:
		@$(MAKE) fclean -C ./libft
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo "$(GREEN)✅ Done ✅$(RESET)"

re:		fclean all 

.PHONY: all clean fclean re



