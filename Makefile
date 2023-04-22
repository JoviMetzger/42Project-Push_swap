# Executable
NAME		= push_swap
BONUS		= checker

# Libraries
LIBFT		= ./libft/libft.a

# Compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g

# Sources files
SRC	= ./src/action_push.c \
				./src/action_reverse.c \
				./src/action_rotate.c \
				./src/action_swap.c \
				./src/apply_move.c \
				./src/calculate_cost.c \
				./src/checks.c \
				./src/do_rotations.c \
				./src/fill_stack.c \
				./src/find_position.c \
				./src/indexing.c \
				./src/push_swap.c \
				./src/sort_3.c \
				./src/sorting_a.c \
				./src/sorting_b.c \
				./src/t_list.c \
				./src/utils.c

BONUS_SRC	= ./bonus/action_push.c \
				./bonus/action_reverse.c \
				./bonus/action_rotate.c \
				./bonus/action_swap.c \
				./bonus/check_arg.c \
				./bonus/checker.c \
				./bonus/fill_stack.c \
				./bonus/t_list.c \
				./bonus/utils.c

# Objects files
OBJ			= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))
BONUS_OBJ	= $(addprefix $(OBJDIR)/, $(notdir $(BONUS_SRC:.c=.o)))

# Object Directory
OBJDIR 		= obj

# Colors
BOLD		= \033[1m
ITALIC		= \033[3m
UNDER 		= \033[4m
GREEN		= \033[32;1m
INDIGO		= \033[38;2;75;0;130m
CORAL		= \033[38;2;255;127;80m
RESET		= \033[0m

# Targets
all:	$(NAME)

bonus:	$(BONUS)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		@echo "$(INDIGO) $(UNDER) $(BOLD) $(ITALIC) ✨Compilation Done✨   $(RESET)"

$(BONUS): $(LIBFT) $(BONUS_OBJ)
		@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)
		@echo "$(CORAL) $(UNDER) $(BOLD) $(ITALIC) ✨BONUS Compilation Done✨   $(RESET)"

$(LIBFT): 
		@$(MAKE) -C ./libft

$(OBJDIR)/%.o: ./src/%.c
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

$(OBJDIR)/%.o: ./bonus/%.c
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c -o $@ $^

# Clean
clean:
		@$(MAKE) clean -C ./libft
		@rm -rf $(OBJDIR)
		@echo "$(GREEN) $(ITALIC) ✅ Done ✅$(RESET)"

fclean: clean
		@$(MAKE) fclean -C ./libft
		@rm -f $(NAME)
		@rm -f $(BONUS)
		@echo "$(GREEN) $(ITALIC) ✅ Done ✅$(RESET)"

re:		fclean all

.PHONY: all clean fclean re bouns
