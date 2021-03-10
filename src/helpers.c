/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:46:12 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/07 16:32:27 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
