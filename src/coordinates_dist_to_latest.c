/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_dist_to_latest.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:52:04 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 13:47:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static double	get_distance(t_2d_index p1, t_2d_index p2)
{
	double		dist;

	dist = (p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x);
	return (ft_sqrt(dist));
}

static double	dist_to_opponent(t_2d_index opponent, t_2d_index start,
t_piece piece)
{
	double		ret;
	double		dist;
	int			i;
	t_2d_index	map_coord;

	ret = get_distance(opponent, set_coordinates(start.y + piece.coord[0].y,
	start.x + piece.coord[0].x));
	i = 1;
	while (i < piece.count)
	{
		map_coord.y = start.y + piece.coord[i].y;
		map_coord.x = start.x + piece.coord[i].x;
		dist = get_distance(opponent, map_coord);
		if (dist < ret)
			ret = dist;
		i++;
	}
	return (ret);
}

t_2d_index		get_closest_to_latest(t_board *board, t_piece piece,
t_2d_index opp)
{
	t_2d_index	tmp;
	t_2d_index	next;
	int			is_next_set;
	int			i;

	next = set_coordinates(0, 0);
	is_next_set = 0;
	i = 0;
	while (board->map[i])
	{
		tmp = set_coordinates(i / board->width - piece.coord[0].y,
		i % board->width - piece.coord[0].x);
		if (valid_piece_coordinates(tmp, board, piece))
		{
			if (!is_next_set || dist_to_opponent(opp, tmp, piece) <
			dist_to_opponent(opp, next, piece))
				next = tmp;
			is_next_set = 1;
		}
		i++;
	}
	return (next);
}
