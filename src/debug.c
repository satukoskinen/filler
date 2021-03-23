/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:03:24 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 12:00:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static void	print_heatmap(int *map, int width, int height, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_dprintf(fd, "%4d", map[i * width + j]);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
}

static void	print_map(char *map, int width, int height, int fd)
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

static void	print_piece_coordinates(t_2d_index *coord, int count, int fd)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_dprintf(fd, "%d %d\n", coord[i].y, coord[i].x);
		i++;
	}
}

void		print_debug(t_board board, t_piece piece, t_2d_index next)
{
	int		fd;

	fd = open("debug_output.txt", O_WRONLY | O_APPEND, 0666);
	if (fd == -1)
		ft_putstr("error opening file\n");
	ft_dprintf(fd, "board:\n%d %d\n", board.height, board.width);
	print_map(board.map, board.width, board.height, fd);
	ft_dprintf(fd, "heatmap:\n");
	print_heatmap(board.heatmap, board.width, board.height, fd);
	ft_dprintf(fd, "piece:\n%d %d\n", piece.height, piece.width);
	ft_dprintf(fd, "piece coordinates:\n");
	print_piece_coordinates(piece.coord, piece.count, fd);
	ft_putstr_fd("next piece coordinates: ", fd);
	ft_dprintf(fd, "%d %d\n", next.y, next.x);
	ft_dprintf(fd, "\n\n");
	close(fd);
}

void		init_debug_file(void)
{
	int	fd;

	fd = open("debug_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	close(fd);
}
