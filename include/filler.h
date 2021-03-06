/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:22:31 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 13:46:56 by skoskine         ###   ########.fr       */
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
	int			size;
	char		*map;
	int			*heatmap;
	int			opponent_plays;
	char		opponent;
	char		player;
}				t_board;

typedef struct	s_piece
{
	int			width;
	int			height;
	t_2d_index	*coord;
	int			count;
}				t_piece;

int				get_player_info(char *opponent, char *player);
int				init_board(char *dimension_line, t_board *board);
int				update_board(t_board *board);
int				get_piece(t_piece *piece);
void			get_dimensions(char *str, int *height, int *width);
void			find_next_coordinates(t_board *board, t_piece piece);
void			update_heatmap(t_board *board);
int				valid_piece_coordinates(t_2d_index coord, t_board *board,
				t_piece piece);
t_2d_index		get_first_valid(t_board *board, t_piece piece);
t_2d_index		get_closest_to_opponent(t_board *board, t_piece piece);
t_2d_index		get_closest_to_latest(t_board board, t_piece piece,
				t_2d_index opp);
t_2d_index		get_opponent_coordinates(t_board board, char opponent);
t_2d_index		set_coordinates(int y, int x);
int				row_is_empty(char *map, int row, int width);
int				col_is_empty(char *map, int col, int width, int height);
void			init_debug_file(void);
void			print_debug(t_board board, t_piece piece, t_2d_index next);

#endif
