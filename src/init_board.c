/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:13:19 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/19 07:53:47 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>

int			init_board(char *dimension_line, t_board *board)
{
	int		board_size;

	get_dimensions(dimension_line, &board->height, &board->width);
	board_size = board->height * board->width;
	if (board_size == 0)
		return (1);
	if (!(board->map = (char*)malloc(sizeof(char) * (board_size + 1))))
		return (0);
	ft_memset((void*)board->map, '.', board_size);
	board->map[board_size] = '\0';
	if (!(board->heatmap = (int*)malloc(sizeof(int) * board_size)))
		return (0);
	board->opponent_plays = 0;
	return (1);
}
