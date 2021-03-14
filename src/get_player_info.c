/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:52:30 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/13 23:16:50 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			get_player_info(char *opponent)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) == -1)
		return (0);
	i = 0;
	while (line[i] != '1' && line[i] != '2' && line[i])
		i++;
	if (line[i] == '1')
		*opponent = 'X';
	else if (line[i] == '2')
		*opponent = 'O';
	else
		*opponent = 0;
	free(line);
	if (*opponent == 0)
		return (0);
	else
		return (1);
}
