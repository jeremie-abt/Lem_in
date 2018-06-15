/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_verif_sommet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:33:04 by jabt              #+#    #+#             */
/*   Updated: 2018/06/15 14:42:22 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_nb_child(t_sommet **sommet, t_sommet *parent, t_sommet *node)
{
	t_adj_list		*adj_list;
	t_sommet		*tmp;
	int				distance;
	int				ret;

	distance = node->distance + 1;
	adj_list = sommet->lst;
	ret = 0;
	while (adj_list)
	{
		tmp = lm_get_sommet(sommet, adj_list->name);
		if (tmp->distance == distance && tmp != parent)
			ret++;
		adj_list = adj_list->next;
	}
	return (ret);
}
