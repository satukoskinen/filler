# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 11:40:44 by skoskine          #+#    #+#              #
#    Updated: 2021/03/17 09:54:20 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = skoskine.filler

SRC_DIR = src/
OBJ_DIR = obj/
HEADER_DIR = include/

SRC = $(addprefix $(SRC_DIR), \
	main.c \
	get_player_info.c \
	get_board.c \
	get_piece.c \
	get_next_coordinates.c \
	coordinates_dist_to_latest.c \
	helpers.c \
	debug.c \
	)
OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))
HEADER = $(addprefix $(HEADER_DIR), filler.h)

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
CPPFLAGS = -I libft -I include
LDLIBS = -lft
LDFLAGS = -L libft

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
