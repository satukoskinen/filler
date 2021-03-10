/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:51:35 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/10 08:09:28 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

static int	add_board_row(char *map, size_t row, size_t width)
{
	char	*line;
	size_t	offset;
	size_t	j;

	if (get_next_line(0, &line) != 1)
		return (0);
	offset = 0;
	while (!ft_strchr(".oOxX", line[offset]))
		offset++;
	j = 0;
	while (j < width)
	{
		if (!line[offset + j])
			return (0);
		map[row * width + j] = line[offset + j];
		j++;
	}
	free(line);
	return (1);
}

int			get_board(char *dimension_line, t_board *board)
{
	size_t	i;
	char	*line;

	get_dimensions(dimension_line, &board->height, &board->width);
	if (!(board->map = (char*)malloc(sizeof(char) *
	(board->height * board->width + 1))))
		return (0);
	if (get_next_line(0, &line) != 1)
	{
		ft_strdel(&board->map);
		return (0);
	}
	free(line);
	i = 0;
	while (i < board->height)
	{
		if (!add_board_row(board->map, i, board->width))
		{
			ft_strdel(&board->map);
			return (0);
		}
		i++;
	}
	board->map[board->height * board->width] = '\0';
	return (1);
}
