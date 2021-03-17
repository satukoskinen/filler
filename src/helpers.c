/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:46:12 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/17 10:58:53 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <unistd.h>

void		get_dimensions(char *str, int *height, int *width)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i])
		i++;
	*height = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]) && str[i])
		i++;
	*width = ft_atoi(&str[i]);
}

t_2d_index	get_opponent_coordinates(t_board board, char opponent)
{
	int			i;
	int			j;
	t_2d_index	coordinates;

	coordinates.y = 0;
	coordinates.x = 0;
	i = 0;
	while (i < board.height)
	{
		j = 0;
		while (j < board.width)
		{
			if (ft_toupper(board.map[i * board.width + j]) == opponent)
			{
				coordinates.y = i;
				coordinates.x = j;
			}
			if (board.map[i * board.width + j] == ft_tolower(opponent))
				return (coordinates);
			j++;
		}
		i++;
	}
	return (coordinates);
}

int			row_is_empty(char *map, int row, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		if (map[row * width + i] == '*')
			return (0);
		i++;
	}
	return (1);
}

int			col_is_empty(char *map, int col, int width, int height)
{
	int		i;

	i = 0;
	while (i < height)
	{
		if (map[i * width + col] == '*')
			return (0);
		i++;
	}
	return (1);
}

t_2d_index	set_coordinates(int y, int x)
{
	t_2d_index	coordinates;

	coordinates.y = y;
	coordinates.x = x;
	return (coordinates);
}
