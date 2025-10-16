# NAME
NAME = philo

HEADER = philo.h

# PATH SRCS & UTILS
SRCS = main.c utils/utilslib.c src/clean_up.c src/inits.c src/routine.c

# OBJECTS
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# COMPILER & FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

AR = @ar rcs
RM = @rm -rf

# COLORS
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PINK=\033[0;35m
NC=\033[0m

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(PINK) CREATE $(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "    $(GREEN)  ok $(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(PINK) $< ⌛⌛⌛$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)🧽🫧 Cleaning $(NAME) objects... 🫧🧽$(NC)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(BLUE) 🧽🫧🧼🫧 Full clean $(NAME)... 🫧🧼🫧🧽$(NC)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
