# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 12:22:06 by lperalta          #+#    #+#              #
#    Updated: 2025/04/28 12:22:14 by lperalta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft.a

# Header
HEADER = libft.h

# Objects directory
OBJ_DIR = obj

# Sources
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_atoi.c ft_toupper.c ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_memchr.c ft_memcmp.c ft_strncmp.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_strrchr.c ft_striteri.c ft_strnstr.c ft_substr.c ft_strtrim.c ft_split.c 

# Bonus sources
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c 

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror

# Utils
AR = ar rcs
RM = rm -rf

# Rules
all: $(NAME)

# Compilating library
$(NAME) : $(OBJS)
	@echo "Creating $(NAME)...🫦"
	@ $(AR) $(NAME) $(OBJS)
	@echo "    ✅ GREAT ✅"

  ## Obj creating into objects directory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

  ## Bonus compilating
bonus: $(OBJS) $(BONUS_OBJ)
	@$(AR) $(NAME) $(BONUS_OBJ)
	@echo "🫦Bonus check🫦"

  ## cleaning
clean:
	@$(RM) $(OBJS) $(BONUS_OBJ)
clean_dir:
	@$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re
