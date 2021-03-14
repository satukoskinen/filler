/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_coordinates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:39:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/14 13:17:55 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static int			valid_piece_coordinates(t_2d_index coord, t_board board,
t_piece piece, char opponent)
{
	int			i;
	int			overlap;
	char		cell;

	i = 0;
	overlap = 0;
	while (piece.map[i])
	{
		if (piece.map[i] == '*')
		{
			if (coord.y + i / piece.width >= board.height ||
			coord.x + i % piece.width >= board.width ||
			coord.y + i / piece.width < 0 ||
			coord.x + i % piece.width < 0)
				return (0);
			cell = board.map[(coord.y + i / piece.width) * board.width +
			coord.x + i % piece.width];
			if (cell != '.' && ft_toupper(cell) != opponent)
				overlap++;
			if (overlap == 2 || ft_toupper(cell) == opponent)
				return (0);
		}
		i++;
	}
	return (overlap);
}

/*
**static int	valid_piece_coordinates(t_2d_index coord, t_board board,
**t_piece piece, char opponent)
**{
**	t_2d_index	i;
**	int			overlap;
**	char		cell;
**
**	overlap = 0;
**	i.y = 0;
**	while (i.y < piece.height)
**	{
**		i.x = 0;
**		while (i.x < piece.width)
**		{
**			if (piece.map[i.y * piece.width + i.x] == '*')
**			{
**				if (coord.y + i.y >= board.height || coord.x + i.x >=
**				board.width || coord.y + i.y < 0 || coord.x + i.x < 0)
**					return (0);
**				cell = board.map[(coord.y + i.y) * board.width + coord.x + i.x];
**				if (ft_tolower(cell) != '.' && ft_tolower(cell) != opponent)
**					overlap++;
**				if (overlap == 2 || ft_tolower(cell) == opponent)
**					return (0);
**			}
**			i.x++;
**		}
**		i.y++;
**	}
**	return (overlap);
**}
*/

static t_2d_index	get_opponent_coordinates(t_board board, char opponent)
{
	int			i;
	int			j;
	t_2d_index	coordinates;

	coordinates.y = 0;
	coordinates.x = 0;
	i = 0;
	while (i < board.height)
	{
		j = 0;
		while (j < board.width)
		{
			if (ft_toupper(board.map[i * board.width + j]) == opponent)
			{
				coordinates.y = i;
				coordinates.x = j;
			}
			if (board.map[i * board.width + j] == ft_tolower(opponent))
				return (coordinates);
			j++;
		}
		i++;
	}
	return (coordinates);
}

double				get_distance(t_2d_index p1, t_2d_index p2)
{
	double	dist;

	dist = (p1.y - p2.y) * (p1.y - p2.y) +	 (p1.x - p2.x) * (p1.x - p2.x);
	return (ft_sqrt(dist));
}

double				dist_to_opponent(t_2d_index opponent, t_2d_index start,
t_piece piece)
{
	double		ret;
	double		dist;
	int			i;
	t_2d_index	map_coordinates;

	ret = get_distance(opponent, set_coordinates(start.y + piece.start.y,
	start.x + piece.start.x));
	i = piece.start.y * piece.width + piece.start.x + 1;
	while (piece.map[i])
	{
		if (piece.map[i] == '*')
		{
			map_coordinates.y = start.y + i / piece.width;
			map_coordinates.x = start.x + i % piece.width;
			dist = get_distance(opponent, map_coordinates);
			if (dist < ret)
				ret = dist;
		}
		i++;
	}
	return (ret);
}

void				get_next_coordinates(t_board board, t_piece piece,
char opponent)
{
	t_2d_index	tmp;
	t_2d_index	next;
	t_2d_index	opponent_piece;
	int			is_next_set;
	int			i;

	opponent_piece = get_opponent_coordinates(board, opponent);
	next = set_coordinates(0, 0);
	is_next_set = 0;
	i = 0;
	while (board.map[i])
	{
		tmp = set_coordinates(i / board.width - piece.start.y,
		i % board.width - piece.start.x);
		if (valid_piece_coordinates(tmp, board, piece, opponent))
		{
			if (!is_next_set || dist_to_opponent(opponent_piece, tmp, piece) <=
			dist_to_opponent(opponent_piece, next, piece))
				next = tmp;
			is_next_set = 1;
		}
		i++;
	}
	write_coordinates(next.y, next.x, 1);
}

/*
** void		get_next_coordinates(t_board board, t_piece piece, char opponent)
** {
** 	t_2d_index	i;
** 	t_2d_index	next;
** 	t_2d_index	opponent_piece;
** 	int			is_next_set;
**
** 	opponent_piece = get_opponent_coordinates(board, opponent);
** 	next = set_coordinates(0, 0);
** 	is_next_set = 0;
** 	i.y = 0;
** 	while (i.y < board.height)
** 	{
** 		i.x = 0;
** 		while (i.x < board.width)
** 		{
** 			if (valid_piece_coordinates(set_coordinates(i.y - piece.start.y,
** 			i.x - piece.start.x), board, piece, opponent))
** 			{
** 				if (!is_next_set)
** 					next = set_coordinates(i.y, i.x);
** 				is_next_set = 1;
** 				if (distance_to_opponent(opponent_piece, i, piece) <=
** 				distance_to_opponent(opponent_piece, next, piece))
** 					next = i;
** 			}
** 			i.x++;
** 		}
** 		i.y++;
** 	}
** 	write_coordinates(next.y - piece.start.y, next.x - piece.start.x);
** }
*/

/*
** void		get_next_coordinates(t_data data)
** {
** 	t_2d_index	piece;
** 	t_2d_index	piece_start;
**
** 	piece_start = get_piece_start(data.piece);
** 	piece.y = 0;
** 	while (piece.y < data.board.height)
** 	{
** 		piece.x = 0;
** 		while (piece.x < data.board.width)
** 		{
** 			if (valid_piece_coordinates(piece.y - piece_start.y,
** 			piece.x - piece_start.x, data))
** 			{
** 				write_coordinates(piece.y - piece_start.y,
** 				piece.x - piece_start.x);
** 				return ;
** 			}
** 			piece.x++;
** 		}
** 		piece.y++;
** 	}
** 	write_coordinates(0, 0);
** }
*/
