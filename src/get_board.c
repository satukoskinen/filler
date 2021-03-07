/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:51:35 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/06 23:41:17 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int			get_board(char *dimension_line, t_board *board)
{
	size_t	i;
	size_t	j;
	size_t	offset;
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
		if (get_next_line(0, &line) != 1)
		{
			ft_strdel(&board->map);
			return (0);
		}
		offset = 0;
		while (!ft_strchr(".oOxX", line[offset]))
			offset++;
		j = 0;
		while (j < board->width)
		{
			board->map[i * board->width + j] = line[offset + j];
			j++;
		}
		free(line);
		i++;
	}
	board->map[i * j] = '\0';
	return (1);
}
