# Library name
NAME = libft.a

# Header
HEADER = libft.h

# Objects directory
OBJ_DIR = obj

# Sources
PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/nbrs.c ft_printf/writers.c
GNL_SRCS = GNL/get_next_line_utils.c GNL/get_next_line.c
UTILS_SRCS = ft_utils/ft_atoibase.c ft_utils/ft_atolints.c ft_utils/ft_putnbr.c ft_utils/ft_strcmp.c


SRCS = ft_lib/ft_isalpha.c ft_lib/ft_isdigit.c ft_lib/ft_isalnum.c ft_lib/ft_isascii.c ft_lib/ft_isprint.c \
ft_lib/ft_strlen.c ft_lib/ft_memset.c ft_lib/ft_bzero.c ft_lib/ft_memcpy.c ft_lib/ft_memmove.c ft_lib/ft_atoi.c \
ft_lib/ft_toupper.c ft_lib/ft_tolower.c ft_lib/ft_strlcpy.c ft_lib/ft_strlcat.c ft_lib/ft_strchr.c \
ft_lib/ft_memchr.c ft_lib/ft_memcmp.c ft_lib/ft_strncmp.c ft_lib/ft_calloc.c ft_lib/ft_strdup.c ft_lib/ft_strjoin.c \
ft_lib/ft_putendl_fd.c ft_lib/ft_putstr_fd.c ft_lib/ft_putchar_fd.c ft_lib/ft_putnbr_fd.c ft_lib/ft_itoa.c \
ft_lib/ft_strmapi.c ft_lib/ft_strrchr.c ft_lib/ft_striteri.c ft_lib/ft_strnstr.c ft_lib/ft_substr.c ft_lib/ft_strtrim.c \
ft_lib/ft_split.c $(PRINTF_SRCS) $(GNL_SRCS) $(UTILS_SRCS) $(BONUS_SRC)

BONUS_SRC = ft_list/ft_lstnew.c ft_list/ft_lstadd_back.c ft_list/ft_lstadd_front.c ft_list/ft_lstclear.c \
ft_list/ft_lstdelone.c ft_list/ft_lstlast.c ft_list/ft_lstmap.c ft_list/ft_lstsize.c ft_list/ft_lstiter.c\
ft_utils/ft_replacechar.c

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Utils
AR = ar rcs
RM = @rm -rf

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PINK = \033[0;35m
NC=\033[0m  # (reset)

# Rules
all: $(NAME)

# Compilating library
$(NAME) : $(OBJ_DIR) $(OBJS)
	@echo "$(PINK)Cumpilating $(NAME)...🫦$(NC)"
	@$(AR) $(NAME) $(OBJS)
	@echo "    $(GREEN)🫦   Sucsex 🫦$(NC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(PINK) OBJ DIR created...🫦$(NC)"

  ## Obj creating into objects directory
$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

  ## cleaning
clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)    ...🧹🧹🧹🧹...$(NC)"
fclean: clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re
