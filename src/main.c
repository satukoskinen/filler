/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:39:25 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 13:42:37 by skoskine         ###   ########.fr       */
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
	free(piece.coord);
	free(line);
}

static void	set_resources_to_null(t_board *board, t_piece *piece, char **line)
{
	board->map = NULL;
	board->heatmap = NULL;
	piece->coord = NULL;
	*line = NULL;
}

int			main(void)
{
	char	*line;
	int		ret;
	t_board	board;
	t_piece	piece;

	set_resources_to_null(&board, &piece, &line);
	if (DEBUG)
		init_debug_file();
	if (!get_player_info(&board.opponent, &board.player))
		return (error("Bad player info\n"));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!board.map && !init_board(line, &board))
			break ;
		ft_strdel(&line);
		if (!update_board(&board) || !get_piece(&piece))
			break ;
		find_next_coordinates(&board, piece);
		ft_memdel((void**)&piece.coord);
	}
	free_resources(board, piece, line);
	if (ret != 0)
		return (error("Error occurred\n"));
	return (0);
}
