/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get_sommet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:07:39 by jabt              #+#    #+#             */
/*   Updated: 2018/06/19 14:16:15 by jabt             ###   ########.fr       */
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
	return (iter);
}

int					lm_get_distance(t_sommet **sommet, char *needle)
{
	int			distance;
	t_sommet	*ret;

	ret = lm_get_sommet(sommet, needle);
	return (ret->distance);
}
