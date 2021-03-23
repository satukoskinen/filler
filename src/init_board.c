/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:13:19 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 11:37:02 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int			init_board(char *dimension_line, t_board *board)
{
	get_dimensions(dimension_line, &board->height, &board->width);
	if (board->height <= 0 || board->width <= 0)
		return (0);
	board->size = board->height * board->width;
	if (!(board->map = (char*)malloc(sizeof(char) * (board->size + 1))))
		return (0);
	ft_memset((void*)board->map, '.', board->size);
	board->map[board->size] = '\0';
	if (!(board->heatmap = (int*)malloc(sizeof(int) * board->size)))
		return (0);
	board->opponent_plays = 0;
	return (1);
}
