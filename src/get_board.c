/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:51:35 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/18 16:41:15 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

void		fill_heatmap(t_board *board, char opponent, int i, int value)
{
	if (ft_toupper(board->map[i]) == opponent)
	{
		board->heatmap[i] = 1;
		value = 1;
	}
	else
		board->heatmap[i] = value;
	if ((i + 1) % board->width != 0 &&
	(board->heatmap[i + 1] == 0 || board->heatmap[i + 1] > value + 1))
		fill_heatmap(board, opponent, i + 1, value + 1);
	if (i % board->width != 0 &&
	(board->heatmap[i - 1] == 0 || board->heatmap[i - 1] > value + 1))
		fill_heatmap(board, opponent, i - 1, value + 1);
	if (i - board->width >= 0 &&
	(board->heatmap[i - board->width] == 0 ||
	board->heatmap[i - board->width] > value + 1))
		fill_heatmap(board, opponent, i - board->width, value + 1);
	if (i + board->width < board->width * board->height &&
	(board->heatmap[i + board->width] == 0 ||
	board->heatmap[i + board->width] > value + 1))
		fill_heatmap(board, opponent, i + board->width, value + 1);
}

void		update_heatmap(t_board *board, char opponent)
{
	int		i;

	ft_memset((void*)board->heatmap, 0,
	board->height * board->width * sizeof(int));
	i = 0;
	while (ft_toupper(board->map[i]) != opponent)
		i++;
	fill_heatmap(board, opponent, i, 1);
}

static int	update_board_row(char *map, int row, int width, char opponent)
{
	char	*line;
	int		offset;
	int		j;

	if (get_next_line(0, &line) != 1)
		return (0);
	offset = 0;
	while (!ft_strchr(".oOxX", line[offset]) && line[offset])
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
	if (!board->height || !board->width)
		return (1);
	if (!(board->map = (char*)malloc(sizeof(char) *
	(board->height * board->width + 1))))
		return (0);
	ft_memset((void*)board->map, '.', board->height * board->width);
	board->map[board->height * board->width] = '\0';
	if (!(board->heatmap = (int*)malloc(sizeof(int) *
	(board->height * board->width))))
		return (0);
	return (1);
}
