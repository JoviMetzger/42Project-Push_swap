# NOTES
# $(wildcard): is a function that searches for files that match a certain pattern, and returns a list of those files.
# $(patsubst): is a function that takes a list of words, and replaces a specific pattern in each word with another pattern.
# - The syntax is $(patsubst pattern,replacement,text)
#		- "pattern" is a pattern that we want to match. ($(SRCDIR)/%.c) = all .c
#		- "replacement" is the pattern that we want to replace the matched pattern with. ($(OBJDIR)/%.o) = all .o
#		- "text" is the list of words that we want to apply the pattern substitution to. ($(SRC)) = all those files

# Executable
NAME	= push_swap

# Libraries
LIBFT	= ./libft/libft.a

# Compiler and flags
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

# Sources and objects
SRC		= $(wildcard $(SRCDIR)/*.c) 
OBJ		= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# Directories
OBJDIR 	= ./obj
SRCDIR 	= ./src

# Colors
BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# Targets
all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		@echo "$(MAGENTA) $(BOLD)✨Compilation Done✨$(RESET)"

$(LIBFT): 
		@$(MAKE) -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@mkdir -p $(OBJDIR)
		$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
		@$(MAKE) clean -C ./libft
		@rm -rf $(OBJDIR)
		@echo "$(GREEN)✅ Done ✅$(RESET)"

fclean:
		@$(MAKE) fclean -C ./libft
		@rm -rf $(OBJDIR)
		@rm -f $(NAME)
		@echo "$(GREEN)✅ Done ✅$(RESET)"

re:		fclean all

.PHONY: all clean fclean re
