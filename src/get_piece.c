/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:49:53 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/07 01:44:49 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void		get_shape_dimensions(t_piece *piece)
{
	size_t	i;
	size_t	height;
	size_t	width;

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

int			get_piece(t_piece *piece)
{
	size_t	i;
	size_t	j;
	char	*line;

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
		if (get_next_line(0, &line) != 1)
		{
			ft_strdel(&piece->map);
			return (0);
		}
		j = 0;
		while (j < piece->width)
		{
			piece->map[i * piece->width + j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
	piece->map[i * j] = '\0';
	get_shape_dimensions(piece);
	return (1);
}
