/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:39:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/19 08:38:46 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int			valid_piece_coordinates(t_2d_index coord, t_board board,
t_piece piece, char opponent)
{
	int			i;
	int			overlap;
	char		cell;
	t_2d_index	map_coord;

	overlap = 0;
	i = piece.start.y * piece.width + piece.start.x;
	while (piece.map[i])
	{
		if (piece.map[i] == '*')
		{
			map_coord.y = coord.y + i / piece.width;
			map_coord.x = coord.x + i % piece.width;
			if (map_coord.y < 0 || map_coord.y >= board.height ||
			map_coord.x < 0 || map_coord.x >= board.width)
				return (0);
			cell = board.map[map_coord.y * board.width + map_coord.x];
			if (cell != '.' && ft_toupper(cell) != opponent)
				overlap++;
			if (overlap == 2 || ft_toupper(cell) == opponent)
				return (0);
		}
		i++;
	}
	return (overlap);
}

static int	heatmap_sum(t_board board, t_2d_index start, t_piece piece)
{
	int			i;
	int			sum;
	t_2d_index	map_coord;

	i = piece.start.y * piece.width + piece.start.x;
	sum = 0;
	while (piece.map[i])
	{
		if (piece.map[i] == '*')
		{
			map_coord.y = start.y + i / piece.width;
			map_coord.x = start.x + i % piece.width;
			sum += board.heatmap[map_coord.y * board.width + map_coord.x];
		}
		i++;
	}
	return (sum);
}

static void	get_closest_to_opponent(t_board board, t_piece piece, char opp_char)
{
	t_2d_index	tmp;
	t_2d_index	next;
	int			is_next_set;
	int			i;

	next = set_coordinates(0, 0);
	is_next_set = 0;
	i = 0;
	while (board.map[i])
	{
		tmp = set_coordinates(i / board.width - piece.start.y,
		i % board.width - piece.start.x);
		if (valid_piece_coordinates(tmp, board, piece, opp_char))
		{
			if (!is_next_set || heatmap_sum(board, tmp, piece) <
			heatmap_sum(board, next, piece))
				next = tmp;
			is_next_set = 1;
		}
		i++;
	}
	ft_printf("%d %d\n", next.y, next.x);
}

static void	get_first_valid(t_board board, t_piece piece, char opp_char)
{
	t_2d_index	next;
	t_2d_index	tmp;
	int			i;

	next = set_coordinates(0, 0);
	i = 0;
	while (board.map[i])
	{
		tmp = set_coordinates(i / board.width - piece.start.y,
		i % board.width - piece.start.x);
		if (valid_piece_coordinates(tmp, board, piece, opp_char))
		{
			next = tmp;
			break ;
		}
		i++;
	}
	ft_printf("%d %d\n", next.y, next.x);
}

void		find_next_coordinates(t_board board, t_piece piece, char opp_char)
{
	if (board.opponent_plays)
	{
		update_heatmap(&board, opp_char);
		get_closest_to_opponent(board, piece, opp_char);
	}
	else
		get_first_valid(board, piece, opp_char);
}
