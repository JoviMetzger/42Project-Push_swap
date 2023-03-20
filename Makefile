# Files
NAME	= push_swap
LIBFT	= ./libft/libft.a
SRC	= ./src/push_swap.c ./src/swap_utils.c
OBJ	= $(addprefix $(OBJDIR)/, $(notdir$(SRC:%.c=%.o)))
OBJDIR 	= obj
SRCDIR 	= src
CC	= gcc
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
	@echo "$(GREEN) $(BOLD)Compilation Done$(RESET)"

$(LIBFT): 
		@$(MAKE) -C ./libft
		
$(OBJDIR)/%.o: $(SRCDIR)/%.c
		mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)
		@echo "$(RED)Cleaning Done$(RESET)"

fclean:
		@$(MAKE) fclean -C ./libft
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo "$(RED)fcleaning Done$(RESET)"

re:	fclean all

.PHONY: all clean fclean re


