/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:49:53 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/19 08:36:47 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

static int	get_shape_start(t_piece *piece, t_2d_index *coord)
{
	coord->y = 0;
	while (coord->y < piece->height &&
	row_is_empty(piece->map, coord->y, piece->width))
		coord->y++;
	if (coord->y == piece->height)
		return (0);
	coord->x = 0;
	while (piece->map[coord->y * piece->width + coord->x] != '*')
		coord->x++;
	return (1);
}

static int	add_piece_row(char *map, int row, int width)
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
		map[row * width + j] = line[j];
		j++;
	}
	free(line);
	return (1);
}

int			get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	piece->map = NULL;
	if (get_next_line(0, &line) != 1)
		return (0);
	get_dimensions(line, &piece->height, &piece->width);
	free(line);
	if (!piece->height || !piece->width || !(piece->map =
	(char*)malloc(sizeof(char) * (piece->height * piece->width + 1))))
		return (0);
	i = 0;
	while (i < piece->height)
	{
		if (!add_piece_row(piece->map, i, piece->width))
			return (0);
		i++;
	}
	piece->map[piece->height * piece->width] = '\0';
	if (!(get_shape_start(piece, &piece->start)))
		return (0);
	return (1);
}
