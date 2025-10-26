# Library name
NAME = push_swap
BONUS = checker

# Header
HEADER = push_swap.h
BONUS_HEADER = push_swap_bonus.h

# Sources
SRCS = main.c checkers.c errors.c get_arguments.c push_swap.c calculate_costs.c \
moves/movesrot.c moves/push.c moves/rotate.c moves/reverserotate.c moves/swap.c \
moves/targets.c moves/utils_movements.c

BONUS_SRCS = BONUS/arg_check_bonus.c BONUS/checkers_bonus.c BONUS/errors_bonus.c \
BONUS/get_arguments_bonus.c BONUS/push_bonus.c BONUS/moves_bonus.c \
BONUS/utils_bonus.c

# Objects directory
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus

#INCLUDE = -I include/ 

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:BONUS/%.c=$(BONUS_OBJ_DIR)/%.o)

# Libft linked
LIBFT_DIR = mylib
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_REPO = https://github.com/lperalta14/My_library.git
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(LIBFT_INC)
CFLAGS_BONUS = $(CFLAGS) -I. -IBONUS

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
	@echo "$(PINK)🔗 Linking 🔗$...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)  ✅ ✅ ✅ $(NAME!)✅ ✅ ✅$(NC)"

bonus: $(LIBFT_LIB) $(BONUS)

$(BONUS): $(BONUS_OBJS)
	@echo "$(BLUE)🔗 Linking checker 🔗$(NC)"
	@$(CC) $(CFLAGS_BONUS) $(BONUS_OBJS) $(LIBFT_LIB) -o $(BONUS)
	@echo "$(GREEN)Checker ready ✅$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(PINK) Compiling $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: BONUS/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW) Compiling bonus $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(LIBFT_LIB):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "$(YELLOW)📥 Download MyLib...$(NC)"; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@echo "$(PINK)Compiling $(LIBFT_DIR)...⌛⌛⌛$(NC)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "    $(GREEN)✅ ✅ ✅ MYLIB ✅ ✅ ✅$(NC)"

clean:
	@echo "$(BLUE)🗑️ DELETING push_swap objects... 🗑️$(NC)"
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) clean; \
	fi
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@echo "$(RED) 🗑️ DELETING push_swap and MyLib... 🗑️$(NC)"
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
