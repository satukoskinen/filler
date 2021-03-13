/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:51:35 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/13 23:02:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

static int	update_board_row(char *map, int row, int width, char opponent)
{
	char	*line;
	int		offset;
	int		j;

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
		if (line[offset + j] == opponent && map[row * width + j] == '.')
			map[row * width + j] = ft_tolower(opponent);
		else
			map[row * width + j] = line[offset + j];
		j++;
	}
	free(line);
	return (1);
}

int			update_board(t_board *board, char opponent)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) != 1)
	{
		ft_strdel(&board->map);
		return (0);
	}
	free(line);
	i = 0;
	while (i < board->height)
	{
		if (!update_board_row(board->map, i, board->width, opponent))
		{
			ft_strdel(&board->map);
			return (0);
		}
		i++;
	}
	return (1);
}

int			init_board(char *dimension_line, t_board *board)
{
	get_dimensions(dimension_line, &board->height, &board->width);
	if (!(board->map = (char*)malloc(sizeof(char) *
	(board->height * board->width + 1))))
		return (0);
	ft_memset((void*)board->map, '.', board->height * board->width);
	board->map[board->height * board->width] = '\0';
	return (1);
}

/*
** static int	add_board_row(char *map, int row, int width)
** {
** 	char	*line;
** 	int		offset;
** 	int		j;
**
** 	if (get_next_line(0, &line) != 1)
** 		return (0);
** 	offset = 0;
** 	while (!ft_strchr(".oOxX", line[offset]))
** 		offset++;
** 	j = 0;
** 	while (j < width)
** 	{
** 		if (!line[offset + j])
** 			return (0);
** 		map[row * width + j] = line[offset + j];
** 		j++;
** 	}
** 	free(line);
** 	return (1);
** }
**
** int			get_board(char *dimension_line, t_board *board)
** {
** 	char	*line;
** 	int		i;
**
** 	get_dimensions(dimension_line, &board->height, &board->width);
** 	if (!(board->map = (char*)malloc(sizeof(char) *
** 	(board->height * board->width + 1))))
** 		return (0);
** 	if (get_next_line(0, &line) != 1)
** 	{
** 		ft_strdel(&board->map);
** 		return (0);
** 	}
** 	free(line);
** 	i = 0;
** 	while (i < board->height)
** 	{
** 		if (!add_board_row(board->map, i, board->width))
** 		{
** 			ft_strdel(&board->map);
** 			return (0);
** 		}
** 		i++;
** 	}
** 	board->map[board->height * board->width] = '\0';
** 	return (1);
** }
*/
