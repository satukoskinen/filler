/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:52:30 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/13 23:02:11 by skoskine         ###   ########.fr       */
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

/*
** int			get_player_info(char *player_piece, char *opponent_piece)
** {
** 	char	*line;
** 	int		i;
**
** 	if (get_next_line(0, &line) == -1)
** 		return (0);
** 	i = 0;
** 	while (line[i] != '1' && line[i] != '2' && line[i])
** 		i++;
** 	if (line[i] == '1')
** 		*player_piece = 'o';
** 	else if (line[i] == '2')
** 		*player_piece = 'x';
** 	else
** 		*player_piece = 0;
** 	free(line);
** 	*opponent_piece = *player_piece == 'o' ? 'x' : 'o';
** 	if (*player_piece == 0)
** 		return (0);
** 	else
** 		return (1);
** }
*/
