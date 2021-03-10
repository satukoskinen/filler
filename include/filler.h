/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:22:31 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/07 16:30:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <string.h>

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
	int			shape_width;
	int			shape_height;
	char		*map;
}				t_piece;

typedef struct	s_data
{
	char		player_piece;
	char		opponent_piece;
	t_board		board;
	t_piece		piece;
}				t_data;

int				get_player_info(char *player_piece, char *opponent_piece);
int				get_board(char *dimension_line, t_board *board);
int				get_piece(t_piece *piece);
void			get_dimensions(char *str, int *height, int *width);
int				row_is_empty(char *map, int row, int width);
int				col_is_empty(char *map, int col, int width, int hght);
void			get_next_coordinates(t_data data);

#endif
