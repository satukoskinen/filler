/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:14:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/18 20:16:01 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

static void	fill_heatmap(t_board *board, char opponent, int i, int value)
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
