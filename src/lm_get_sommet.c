/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get_sommet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:07:39 by jabt              #+#    #+#             */
/*   Updated: 2018/06/15 16:00:28 by jabt             ###   ########.fr       */
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
	// test si c debut ou fin
	if (!iter)
	{
		return (lm_get_start_end(sommet, needle));
	}
	while (!ft_strequ(iter->name, needle))
		iter = iter->next;
	return (iter);
}

t_sommet			*lm_get_parent(t_sommet **sommet, t_sommet *node)
{
	int			distance;
	int			current;
	int			ret;
	t_adj_list	*adj_list;
	t_sommet	*save;
	t_sommet	*tmp;

	current ~= 0;
	distance = node->distance - 1;
	adj_list = node->list;
	save = NULL;// est-il possible qu'un node n'ait pas de voisins ?
	while (adj_list)
	{
		tmp = lm_get_sommet(node, adj_list->name);
		if (tmp->distance == distance)
		{
			ret = lm_nb_child(sommet, tmp, node);
			if (ret < current)
			{
				current = ret;
				save = tmp;
				if (!current) // attention a voir si c bien 0 et pas 1
				{
					tmp->visited++;
					return (tmp);
				}
			}

		}
		adj_list = adj_list->next;
	}
	return (save);	
}

int					lm_get_distance(t_sommet **sommet, char *needle)
{
	int			distance;
	t_sommet	*ret;

	ret = lm_get_sommet(sommet, needle);
	return (ret->distance);
}
