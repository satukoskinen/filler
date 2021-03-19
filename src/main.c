/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:39:25 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/19 08:29:52 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	error(const char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

static void	free_resources(t_board board, t_piece piece, char *line)
{
	free(board.map);
	free(board.heatmap);
	free(piece.map);
	free(line);
}

int			main(void)
{
	char	*line;
	int		ret;
	t_board	board;
	t_piece	piece;
	char	opponent;

	board.map = NULL;
	board.heatmap = NULL;
	if (!get_player_info(&opponent))
		return (error("Bad player info\n"));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!board.map && !init_board(line, &board))
			break ;
		ft_strdel(&line);
		if (!update_board(&board, opponent) || !get_piece(&piece))
			break ;
		find_next_coordinates(board, piece, opponent);
		ft_strdel(&piece.map);
	}
	free_resources(board, piece, line);
	if (ret != 0)
		return (error("Error occurred\n"));
	return (0);
}
