/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:49:53 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/10 08:07:00 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

static void	get_shape_dimensions(t_piece *piece)
{
	int		i;
	int		height;
	int		width;

	height = 0;
	width = 0;
	i = 0;
	while (i < piece->height)
	{
		if (!row_is_empty(piece->map, i, piece->width))
			height++;
		i++;
	}
	i = 0;
	while (i < piece->width)
	{
		if (!col_is_empty(piece->map, i, piece->width, piece->height))
			width++;
		i++;
	}
	piece->shape_height = height;
	piece->shape_width = width;
}

static int	add_piece_row(char *map, int 	row, int 	width)
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
	if (!(piece->map = (char*)malloc(sizeof(char) *
	(piece->height * piece->width + 1))))
		return (0);
	i = 0;
	while (i < piece->height)
	{
		if (!add_piece_row(piece->map, i, piece->width))
		{
			ft_strdel(&piece->map);
			return (0);
		}
		i++;
	}
	piece->map[piece->height * piece->width] = '\0';
	get_shape_dimensions(piece);
	return (1);
}
