/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:22:31 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/07 10:26:59 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <string.h>

typedef struct	s_board
{
	size_t		width;
	size_t		height;
	char		*map;
}				t_board;

typedef struct	s_piece
{
	size_t		width;
	size_t		height;
	size_t		shape_width;
	size_t		shape_height;
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
void			get_dimensions(char *str, size_t *height, size_t *width);
int				row_is_empty(char *map, size_t row, size_t width);
int				col_is_empty(char *map, size_t col, size_t width, size_t hght);
void			write_next_coordinates(t_data data);

#endif
