/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:56:06 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 17:57:02 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//	return -1 faut arreter traitement et print error
//	return 0 juste passer a la stance tube
//	return 1, la string de room_name est bonne

static int		lm_is_good_room(t_sommet **graph, char *room_name)
{
	int		i;
	int		ret;

	i = 0;
	if (*room_name == 'L' || (room_name[0] == '#' && room_name[1] != '#'))
		return (-1);
	if (*room_name == '#')
	{
		ret = lm_handle_command(sommet, room_name);
		return (ret); // attention ca va peut etre pose pb
	}
	while (room_name[i] && room_name[i] != ' ' && room_name[i] != '\n')
	{
		if (room_name[i] == '-')
			return (0);
		i++;
	}
	if (!room_name[i] || room_name[i] == '\n')
		return (-1);
	return (1);
}


// return -1 problem de segfault ou quoi en gros faut stop le traitement
// tout free et mettre erreur
// 0 -> mauvais format donc on test de voir si cest un tube
// 1 -> on continue a stock des room

int		lm_parse_and_stock_room(t_sommet **sommet)
{
	char	*ptr;
	char	*ligne;
	int		ret;
	int		gnl_ret;

	gnl_ret = 0;
	while ((gnl_ret = get_next_line(0, &ligne)))
	{
		if ((ret = lm_is_good_room(sommet, ligne)) == -1 || ret == 0)
		{
			if (ligne && ret == -1)
			{
				free(ligne);
				ligne = NULL;
			}
			assert(ret == -1 && ligne != NULL);
			assert(ret == 0 && ligne == NULL);
			return (ret);
		}
		printf("%s\n", ligne);
		free(ligne);
	}
	if (gnl_ret == 0)
		return (-1);
}
