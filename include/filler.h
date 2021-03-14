/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:22:31 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/13 23:17:17 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <string.h>

# define DEBUG 0

typedef struct	s_2d_index
{
	int			y;
	int			x;
}				t_2d_index;

typedef struct	s_board
{
	int			width;
	int			height;
	char		*map;
}				t_board;

typedef struct	s_piece
{
	int			width;
	int			height;
	t_2d_index	start;
	char		*map;
}				t_piece;

int				get_player_info(char *opponent_piece);
int				init_board(char *dimension_line, t_board *board);
int				update_board(t_board *board, char opponent);
int				get_piece(t_piece *piece);
void			get_dimensions(char *str, int *height, int *width);
int				row_is_empty(char *map, int row, int width);
int				col_is_empty(char *map, int col, int width, int hght);
void			get_next_coordinates(t_board board, t_piece piece, char oppnt);
t_2d_index		set_coordinates(int y, int x);
void			write_coordinates(int y, int x, int fd);
void			init_debug_file(void);
void			print_debug(t_board board, t_piece piece, t_2d_index opponent,
t_2d_index next);

#endif
