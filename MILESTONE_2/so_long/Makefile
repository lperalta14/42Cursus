# Library name
NAME = so_long

# Header
HEADER = so_long.h

# Sources
SRCS = so_long.c error.c check_create/parseo.c check_create/flood_fill.c check_create/map.c \
ventana.c

# Objects directory
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

#INCLUDE = -I include/ 

# Libft linked
LIBFT_DIR = my_lib
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

# MLX42 linked
MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = -I$(MLX42_DIR)/include

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(LIBFT_INC) $(MLX42_INC)
MLX42_FLAGS = -ldl -lglfw -pthread -lm

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
all: $(LIBFT_LIB) $(MLX42_LIB) $(NAME)

$(MLX42_LIB):
	@echo "$(PINK)MLX42...🫦$(NC)"
	@mkdir -p $(MLX42_DIR)/build
	@cd $(MLX42_DIR)/build && cmake .. && make

$(LIBFT_LIB):
	@echo "$(PINK)$(NAME)...🫦$(NC)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "    $(GREEN)🫦   Sucsex 🫦$(NC)"

$(NAME): $(OBJS)
	@echo "$(PINK)🔗👅 Linking 👅🔗$...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)
	@echo "$(GREEN)🫦 sucsex $(NAME!)🫦$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(PINK)🫦 Cumpiling $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)🧽🫧 Cleaning objects... 🫧🧽$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)
	@$(RM) -r $(MLX42_DIR)/build

fclean: clean
	@echo "$(BLUE) 🧽🫧🧼🫧 Full clean... 🫧🧼🫧🧽$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean