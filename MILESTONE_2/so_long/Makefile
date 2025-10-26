# Library name
NAME = so_long

# Header
HEADER = so_long.h

# Sources
SRCS = so_long.c error.c check_create/parseo.c check_create/flood_fill.c check_create/map.c \
init.c drawmap.c hooks.c moveplayer.c

# Objects directory
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

#INCLUDE = -I include/ 

# Libft linked
LIBFT_DIR = my_lib
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_REPO = https://github.com/lperalta14/My_library.git

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
RM = rm -rf

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
	@echo "$(PINK)MLX42...$(NC)"
	@mkdir -p $(MLX42_DIR)/build
	@cd $(MLX42_DIR)/build && cmake .. && make

$(LIBFT_LIB):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "$(YELLOW)📥 Download MyLib...$(NC)"; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@echo "$(PINK)$(NAME)...$(NC)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "   $(GREEN) ✅ MYLIB ✅ $(NC)"

$(NAME): $(OBJS)
	@echo "$(PINK)🔗👅 Linking 👅🔗$...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)
	@echo "$(GREEN)🫦 sucsex $(NAME!)🫦$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(PINK) $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🗑️ DELETING $(NAME) objects... 🗑️$(NC)"
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) clean; \
	fi
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(RM) -r $(MLX42_DIR)/build

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

.PHONY: all clean fclean