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
LIBFT_DIR = my_lib
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(LIBFT_INC)
CFLAGS_BONUS = $(CFLAGS) -I. -IBONUS

# Utils
AR = @ar rcs
RM = @rm -rf

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
	@echo "$(PINK)🔗👅 Linking 👅🔗$...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "$(GREEN)🫦 sucsex $(NAME!)🫦$(NC)"

bonus: $(LIBFT_LIB) $(BONUS)

$(BONUS): $(BONUS_OBJS)
	@echo "$(BLUE)🔗 Linking checker 🔗$(NC)"
	@$(CC) $(CFLAGS_BONUS) $(BONUS_OBJS) $(LIBFT_LIB) -o $(BONUS)
	@echo "$(GREEN)Checker ready ✅$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(PINK)🫦 Cumpiling $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: BONUS/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)🫦 Compiling bonus $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(LIBFT_LIB):
	@echo "$(PINK)Cumpilating $(NAME)...🫦$(NC)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "    $(GREEN)🫦   Sucsex 🫦$(NC)"

clean:
	@echo "$(BLUE)🧽🫧 Cleaning push_swap objects... 🫧🧽$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@echo "$(BLUE) 🧽🫧🧼🫧 Full clean push_swap and libft... 🫧🧼🫧🧽$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
