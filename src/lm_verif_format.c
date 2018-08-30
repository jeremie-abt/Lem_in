/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_verif_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:42:46 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 17:54:52 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
int		lm_is_good_name_room(t_sommet **sommet, char *room)
{
	int		i;
	int		ret;

	i = 0;
	if (*room == 'L' || (room[0] == '#' && room[1] != '#'))
		return (-1);
	if (*room == '#')
	{
		ret = lm_handle_command(sommet, room);
		return (ret); // attention ca va peut etre pose pb
	}
	while (room[i] && room[i] != ' ' && room[i] != '\n')
	{
		if (room[i] == '-')
			return (0);
		i++;
	}
	if (!room[i] || room[i] == '\n')
		return (-1);
	return (1);
}
*/

// une fonctino qui manage la premiere partie d'une room
//
// et une fonction pour la deuxieme partie
