/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_dist_to_latest.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:52:04 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/17 10:07:56 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

t_2d_index		get_opponent_coordinates(t_board board, char opponent)
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

double			get_distance(t_2d_index p1, t_2d_index p2)
{
	double		dist;

	dist = (p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x);
	return (ft_sqrt(dist));
}

double			dist_to_opponent(t_2d_index opponent, t_2d_index start,
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
