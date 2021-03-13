/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:03:24 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/13 16:31:33 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

void		print_map(char *map, int width, int height, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			write(fd, &map[i * width + j], 1);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
}

void		print_debug(t_board board, t_piece piece, t_2d_index opponent,
t_2d_index next)
{
	int		fd;

	fd = open("debug_output.txt", O_WRONLY | O_APPEND, 0666);
	if (fd == -1)
		ft_putstr("error opening file\n");
	ft_putstr_fd("\n\n\n", fd);
	write_coordinates(board.height, board.width, fd);
	print_map(board.map, board.width, board.height, fd);
	write_coordinates(piece.height, piece.width, fd);
	print_map(piece.map, piece.width, piece.height, fd);
	ft_putstr_fd("opponent coordinates: ", fd);
	write_coordinates(opponent.y, opponent.x, fd);
	ft_putstr_fd("next piece coordinates: ", fd);
	write_coordinates(next.y, next.x, fd);
	close(fd);
}

void		init_debug_file(void)
{
	int	fd;

	fd = open("debug_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	close(fd);
}
