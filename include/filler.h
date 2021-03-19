/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:22:31 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/19 21:19:38 by skoskine         ###   ########.fr       */
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
	int			*heatmap;
	int			opponent_plays;
}				t_board;

typedef struct	s_piece
{
	int			width;
	int			height;
	t_2d_index	*coord;
	int			count;
}				t_piece;

int				get_player_info(char *opponent_piece);
int				init_board(char *dimension_line, t_board *board);
int				update_board(t_board *board, char opponent);
int				get_piece(t_piece *piece);
void			get_dimensions(char *str, int *height, int *width);
int				row_is_empty(char *map, int row, int width);
int				col_is_empty(char *map, int col, int width, int hght);
void			find_next_coordinates(t_board board, t_piece piece,
				char opp_char);
void			update_heatmap(t_board *board, char opponent);
t_2d_index		get_opponent_coordinates(t_board board, char opponent);
int				valid_piece_coordinates(t_2d_index coord, t_board board,
				t_piece piece, char opponent);
void			get_first_valid(t_board board, t_piece piece, char opp_char);
void			get_closest_to_opponent(t_board board, t_piece piece,
				char opp_char);
void			get_closest_to_latest(t_board board, t_piece piece,
				char opp_char, t_2d_index opp);
t_2d_index		set_coordinates(int y, int x);
void			init_debug_file(void);
void			print_debug(t_board board, t_piece piece, t_2d_index opp,
				t_2d_index next);

#endif
