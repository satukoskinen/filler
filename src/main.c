/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:39:25 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/07 01:41:00 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	print_board(t_board board)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < board.height)
	{
		j = 0;
		while (j < board.width)
		{
			write(1, &board.map[i * board.width + j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		error(const char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int		main(void)
{
	char	*line;
	int		ret;
	t_data	data;

	if (!get_player_info(&data.player_piece, &data.opponent_piece))
		return (error("Bad player info\n"));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!get_board(line, &data.board))
			return (1);
		if (!get_piece(&data.piece))
			return (1);
		write_next_coordinates(data);
		free(line);
		free(data.board.map);
		free(data.piece.map);
	}
	if (ret == -1)
		return (1);
	return (0);
}
