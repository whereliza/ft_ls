# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/07 16:27:25 by gpop              #+#    #+#              #
#    Updated: 2018/02/15 18:23:21 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_DIR = ./srcs
INC_DIR = ./includes
LIB_DIR = ./libft
LIB_INC = $(LIB_DIR)/includes

FILES = main flag_validator error controller file_or_dir_input flag_input \
		file_obj wizard permissions file_or_dir_validator console sort \
		sort_utils file_obj_create input_destroy console_output console_utils \
		dir_processor recursion console_output_color flag_input_utils utils \
		console_output_multi_column
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_LINK = -L $(LIB_DIR) -lft

SRC = $(patsubst %,$(SRC_DIR)/%.c,$(FILES))
OBJ = $(patsubst %,%.o,$(FILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@$(CC) -I $(LIB_INC) -I $(INC_DIR) $(CFLAGS) -c $(SRC)
	@$(CC) $(OBJ) $(LIB_LINK) -o $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
