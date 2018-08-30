/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get_sommet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:07:39 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 18:05:02 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_get_start_end(t_sommet **sommet, char *needle)
{
	if (ft_strequ(sommet[0]->name, needle))
		return (sommet[0]);
	else if (ft_strequ(sommet[1]->name, needle))
		return (sommet[1]);
	else
		return (NULL);
}

t_sommet			*lm_get_sommet(t_sommet **sommet, char *needle)
{
	int			key;
	t_sommet	*iter;

	key = lm_hash(needle);
	iter = sommet[key];
	if (!iter || ft_strequ(needle, sommet[0]->name) || ft_strequ(needle, sommet[1]->name))
		return (lm_get_start_end(sommet, needle));
	while (!ft_strequ(iter->name, needle))
		iter = iter->next;
///	printf("addr renvoye : %p pour : %s\n",iter, needle);
	return (iter);
}
