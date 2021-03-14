/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:39:25 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/14 13:19:50 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		error(const char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int		main(void)
{
	char	*line;
	int		ret;
	t_board	board;
	t_piece	piece;
	char	opponent;

	board.map = NULL;
	if (!get_player_info(&opponent))
		return (error("Bad player info\n"));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!board.map && !init_board(line, &board))
			return (error("Error in initializing map\n"));
		if (!update_board(&board, opponent) || !get_piece(&piece))
			return (error("Error in updating board and piece\n"));
		get_next_coordinates(board, piece, opponent);
		free(line);
		free(piece.map);
	}
	free(board.map);
	if (ret == -1)
		return (error("Error in reading input\n"));
	return (0);
}
