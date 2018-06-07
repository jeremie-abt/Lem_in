/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:29:35 by jabt              #+#    #+#             */
/*   Updated: 2018/06/06 10:33:12 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 *		pour l'instant sommet[0] == start	sommet[1] == end
 */

int			lm_add_start(t_sommet **sommet, char *str)
{
	char	*start_room;

	if (sommet[0])
		return (-1);// pour l'instant ca ce n'est pas gere
	start_room = lm_get_room_name(str);
	if (start_room)
	{
		if (!(sommet[0] = malloc(sizeof(t_sommet))))
			return (-1);
	}
	else
		return (-1);
	ft_bzero(sommet[0], sizeof(t_sommet));
	sommet[0]->name = start_room;
	return (1);
}

int			lm_add_end(t_sommet **sommet, char *str)
{
	char	*end_room;

	if (sommet[1])
		return (-1);//pour l'instant non gere aussi
	end_room = lm_get_room_name(str);
	if (end_room)
	{
		if (!(sommet[1] = malloc(sizeof(t_sommet))))
			return (-1);
	}
	else
		return (-1);
	ft_bzero(sommet[1], sizeof(t_sommet));
	sommet[1]->name = end_room;
	return (1);
}
