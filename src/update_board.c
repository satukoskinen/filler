/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:13:55 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 13:43:20 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

static int	get_map_start(char *line)
{
	int		i;

	i = 0;
	while (!ft_strchr(".OX", line[i]) && line[i])
		i++;
	return (i);
}

static int	update_board_row(t_board *board, char *line, int row, char opp)
{
	int		offset;
	int		j;

	offset = get_map_start(line);
	j = 0;
	while (j < board->width)
	{
		if (!line[offset + j])
			return (0);
		if (line[offset + j] == opp &&
		board->map[row * board->width + j] == '.')
		{
			board->map[row * board->width + j] = ft_tolower(opp);
			board->opponent_plays = 1;
		}
		else
			board->map[row * board->width + j] = line[offset + j];
		j++;
	}
	return (1);
}

int			update_board(t_board *board)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) != 1)
		return (0);
	ft_strdel(&line);
	board->opponent_plays = 0;
	i = 0;
	while (i < board->height)
	{
		if (!(get_next_line(0, &line)))
			break ;
		if (!update_board_row(board, line, i, board->opponent))
			break ;
		free(line);
		i++;
	}
	if (i != board->height)
	{
		free(line);
		return (0);
	}
	return (1);
}
