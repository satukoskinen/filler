/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:14:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 13:44:22 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

static int	fill_remaining(t_board *board, int value)
{
	int	empty;
	int	i;

	empty = 0;
	i = 0;
	while (i < board->size)
	{
		if (board->heatmap[i] == 0)
			empty++;
		else if (board->heatmap[i] == value)
		{
			if ((i + 1) % board->width != 0 && board->heatmap[i + 1] == 0)
				board->heatmap[i + 1] = value + 1;
			if (i % board->width != 0 && board->heatmap[i - 1] == 0)
				board->heatmap[i - 1] = value + 1;
			if (i - board->width >= 0 && board->heatmap[i - board->width] == 0)
				board->heatmap[i - board->width] = value + 1;
			if (i + board->width < board->size &&
			board->heatmap[i + board->width] == 0)
				board->heatmap[i + board->width] = value + 1;
		}
		i++;
	}
	return (empty);
}

static void	fill_from_opponent(t_board *board, int i)
{
	int	value;
	int	j;

	value = 1;
	board->heatmap[i] = value;
	j = 1;
	while ((i - j + 1) % board->width != 0 &&
	(board->heatmap[i - j] == 0 || board->heatmap[i - j] > value))
		board->heatmap[i - j++] = ++value;
	value = 1;
	j = 1;
	while ((i + j) % board->width != 0 &&
	(board->heatmap[i + j] == 0 || board->heatmap[i + j] > value))
		board->heatmap[i + j++] = ++value;
	value = 1;
	j = 1;
	while (i - j * board->width >= 0 && (board->heatmap[i - j * board->width]
	== 0 || board->heatmap[i - j * board->width] > value))
		board->heatmap[i - j++ * board->width] = ++value;
	value = 1;
	j = 1;
	while (i + j * board->width < board->size &&
	(board->heatmap[i + j * board->width] == 0 ||
	board->heatmap[i + j * board->width] > value))
		board->heatmap[i + j++ * board->width] = ++value;
}

void		update_heatmap(t_board *board)
{
	int		i;
	int		value;

	ft_memset((void*)board->heatmap, 0,
	board->size * sizeof(int));
	i = 0;
	while (board->map[i])
	{
		if (ft_toupper(board->map[i]) == board->opponent)
			fill_from_opponent(board, i);
		i++;
	}
	value = 2;
	while (1)
	{
		if (!fill_remaining(board, value))
			break ;
		value++;
	}
}
