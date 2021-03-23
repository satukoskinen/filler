/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:49:53 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 19:51:20 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

static int	add_piece_row(t_2d_index *coord, int *count, int row, int width)
{
	char	*line;
	int		j;

	if (get_next_line(0, &line) != 1)
		return (0);
	j = 0;
	while (j < width)
	{
		if (!line[j])
			return (0);
		if (line[j] == '*')
		{
			coord[*count] = set_coordinates(row, j);
			*count += 1;
		}
		j++;
	}
	free(line);
	return (1);
}

int			get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	piece->coord = NULL;
	piece->count = 0;
	if (get_next_line(0, &line) != 1)
		return (0);
	get_dimensions(line, &piece->height, &piece->width);
	free(line);
	if (piece->height <= 0 || piece->width <= 0)
		return (0);
	if (!(piece->coord = (t_2d_index*)malloc(sizeof(t_2d_index) *
	(piece->height * piece->width))))
		return (0);
	i = 0;
	while (i < piece->height)
	{
		if (!add_piece_row(piece->coord, &piece->count, i, piece->width))
			return (0);
		i++;
	}
	return (1);
}
