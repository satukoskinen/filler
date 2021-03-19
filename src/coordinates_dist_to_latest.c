/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_dist_to_latest.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:52:04 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/19 21:45:15 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
double	get_distance(t_2d_index p1, t_2d_index p2)
{
	double		dist;

	dist = (p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x);
	return (ft_sqrt(dist));
}

double	dist_to_opponent(t_2d_index opponent, t_2d_index start,
t_piece piece)
{
	double		ret;
	double		dist;
	int			i;
	t_2d_index	map_coord;

	ret = get_distance(opponent, set_coordinates(start.y + piece.start.y,
	start.x + piece.start.x));
	i = piece.start.y * piece.width + piece.start.x + 1;
	while (piece.map[i])
	{
		if (piece.map[i] == '*')
		{
			map_coord.y = start.y + i / piece.width;
			map_coord.x = start.x + i % piece.width;
			dist = get_distance(opponent, map_coord);
			if (dist < ret)
				ret = dist;
		}
		i++;
	}
	return (ret);
}

void	get_closest_to_latest(t_board board, t_piece piece, char opp_char,
t_2d_index opp)
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
			if (!is_next_set || dist_to_opponent(opp, tmp, piece) <
			dist_to_opponent(opp, next, piece))
				next = tmp;
			is_next_set = 1;
		}
		i++;
	}
	ft_printf("%d %d\n", next.y, next.x);
}
*/
