/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_verif_sommet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:33:04 by jabt              #+#    #+#             */
/*   Updated: 2018/06/18 15:34:11 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
int		lm_nb_child(t_sommet **sommet, t_sommet *parent, t_sommet *node)
{
	t_adj_lst		*adj_lst;
	t_sommet		*tmp;
	int				distance;
	int				ret;

	distance = node->distance + 1;
	adj_lst = sommet->lst;
	ret = 0;
	while (adj_lst)
	{
		tmp = lm_get_sommet(sommet, adj_lst->name);
		if (tmp->distance == distance && tmp != parent)
			ret++;
		adj_lst = adj_lst->next;
	}
	return (ret);
}*/
