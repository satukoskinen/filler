# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 11:40:44 by skoskine          #+#    #+#              #
#    Updated: 2021/03/23 11:36:43 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = skoskine.filler

SRC_DIR = src/
OBJ_DIR = obj/
HEADER_DIR = include/

SRC = $(addprefix $(SRC_DIR), \
	main.c \
	get_player_info.c \
	init_board.c \
	update_board.c \
	get_piece.c \
	find_next_coordinates.c \
	update_heatmap.c \
	helpers.c \
	debug.c \
	)

OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))
HEADER = $(addprefix $(HEADER_DIR), filler.h)

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
CPPFLAGS = -I libft -I include
LDLIBS = -lft
LDFLAGS = -L libft #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $< $(CPPFLAGS)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ): $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
