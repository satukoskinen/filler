/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_coordinates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:39:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/10 08:21:47 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static int	valid_piece_coordinates(int y, int x, t_data data)
{
	t_2d_index	i;
	int			overlap;
	char		cell;

	overlap = 0;
	i.y = 0;
	while (i.y < data.piece.height)
	{
		i.x = 0;
		while (i.x < data.piece.width)
		{
			if (data.piece.map[i.y * data.piece.width + i.x] == '*')
			{
				if (y + i.y >= data.board.height || x + i.x >= data.board.width ||
				y + i.y < 0 || x + i.x < 0)
					return (0);
				cell = data.board.map[(y + i.y) * data.board.width + x + i.x];
				if (ft_tolower(cell) == data.player_piece)
					overlap++;
				if (overlap == 2 || ft_tolower(cell) == data.opponent_piece)
					return (0);
			}
			i.x++;
		}
		i.y++;
	}
	return (overlap);
}

static void	write_coordinates(size_t y, size_t x)
{
	ft_putnbr(y);
	ft_putstr(" ");
	ft_putnbr(x);
	ft_putstr("\n");
} 

void		get_next_coordinates(t_data data)
{
	t_2d_index	piece;
	t_2d_index	piece_start;
	t_2d_index	next_piece;
//	t_2d_index	opponent_piece;

	next_piece.y = 0;
	next_piece.x = 0;
	piece_start.y = 0;
	while (row_is_empty(data.piece.map, piece_start.y, data.piece.width))
		piece_start.y++;
	piece_start.x = 0;
	while (data.piece.map[piece_start.y * data.piece.width + piece_start.x] != '*')
		piece_start.x++;
	piece.y = 0;
	while (piece.y < data.board.height)
	{
		piece.x = 0;
		while (piece.x < data.board.width)
		{
			if (valid_piece_coordinates(piece.y - piece_start.y, piece.x - piece_start.x, data))
			{
				write_coordinates(piece.y - piece_start.y, piece.x - piece_start.x);
				return ;
			}
			piece.x++;
		}
		piece.y++;
	}
	write_coordinates(next_piece.y, next_piece.x);
}
