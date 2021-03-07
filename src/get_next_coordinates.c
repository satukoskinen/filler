/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_coordinates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 22:39:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/07 10:04:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static int	valid_piece_coordinates(size_t y, size_t x, t_data data)
{
	size_t	i;
	size_t	j;
	int		overlap;
	char	cell;

	overlap = 0;
	i = 0;
	while (i < data.piece.height)
	{
		j = 0;
		while (j < data.piece.width)
		{
			if (data.piece.map[i * data.piece.width + j] == '*')
			{
				if (y + i >= data.board.height || x + j >= data.board.width)
					return (0);
				cell = data.board.map[(y + i) * data.board.width + x + j];
				overlap += (ft_tolower(cell) == data.player_piece);
				if (overlap == 2 || ft_tolower(cell) == data.opponent_piece)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (overlap);
}

void		write_next_coordinates(t_data data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < data.board.height)
	{
		x = 0;
		while (x < data.board.width)
		{
			if (valid_piece_coordinates(y, x, data))
			{
				ft_putnbr(y);
				ft_putstr(" ");
				ft_putnbr(x);
				ft_putstr("\n");
				return ;
			}
			x++;
		}
		y++;
	}
	ft_putstr("0 0\n");
}
