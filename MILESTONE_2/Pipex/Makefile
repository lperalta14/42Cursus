# Library name
NAME = pipex

# Header
HEADER = pipex.h

# Sources
SRCS = main.c src/errors.c src/paths.c src/pipex.c

# Objects directory
OBJ_DIR = obj

#INCLUDE = -I include/ 

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Libft linked
LIBFT_DIR = my_lib
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_REPO = https://github.com/lperalta14/My_library.git

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(LIBFT_INC)

# Utils
AR = @ar rcs
RM = rm -rf

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PINK=\033[0;35m
NC=\033[0m  # (reset)

# Rules
all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	@echo "$(PINK)🔗Link🔗$...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "   $(GREEN) OK $(NAME!)$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(PINK) $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "$(YELLOW)📥 Download MyLib...$(NC)"; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@echo "$(PINK)$(NAME)...$(NC)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "   $(GREEN) ✅ MYLIB ✅ $(NC)"

clean:
	@echo "$(RED)🗑️ DELETING $(NAME) objects... 🗑️$(NC)"
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) clean; \
	fi
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@echo "$(RED) 🗑️ DELETING all... 🗑️$(NC)"
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) fclean; \
		$(RM) $(LIBFT_DIR); \
	fi
	@$(RM) $(NAME) $(BONUS)
	@echo "$(BLUE)🧽🫧🧼🫧 ALL CLEAN 🫧🧼🫧🧽$(NC)"

re: fclean all

update_lib:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		echo "$(YELLOW)🔄 UPDATE MyLib...$(NC)"; \
		cd $(LIBFT_DIR) && git pull; \
		$(MAKE) -C $(LIBFT_DIR) re; \
		echo "$(GREEN)✅ UPDATE READY$(NC)"; \
	else \
		echo "$(RED)❌ Library not found $(NC)"; \
	fi

.PHONY: all clean fclean re bonus

