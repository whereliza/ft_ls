# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clothor- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 19:30:39 by clothor-          #+#    #+#              #
#    Updated: 2018/12/04 22:02:58 by clothor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	  ft_abs.c \
	  ft_bzero.c \
	  ft_intlen.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_islower.c \
	  ft_isprint.c \
	  ft_isspace.c \
	  ft_isupper.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstappend.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstlen.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_max.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putendl.c \
	  ft_putnbr_fd.c \
	  ft_putnbr_w.c \
	  ft_putnbr.c \
	  ft_putstr_fd.c \
	  ft_putstr_w.c \
	  ft_putstr.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_swap.c \
	  ft_swap_mem.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_wordcount.c \
	  ft_wordccount.c \
	  get_next_line.c

NAME = libft.a
MODE = gcc -Wall -Wextra -Werror
OBJ_NAME = $(SRC:.c=.o)
INC_PATH = ./includes/
SRC_PATH = ./src/
OBJ_DIR = ./obj/


HEADER		= $(addprefix $(INC_PATH), $(HEADER_NAME))
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32mLibrary was created."

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_PATH)%.c $(HEADER)
	@$(MODE) -c -I $(INC_PATH) $< -o $@
	@echo "\033[22;90m$<" "\033[22;90m has been changed and recompiled."

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31mAll objects have been removed."

fclean: clean
	@rm -rf $(NAME)

re: fclean all
