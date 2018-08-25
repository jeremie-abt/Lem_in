/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_update_flow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:20:34 by jabt              #+#    #+#             */
/*   Updated: 2018/08/25 12:52:45 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 *		**sommet is a graph (hashtable) with a maximum flow
 *		meaning the maximum of different distinct path possible
 *		with edge weighted to 0 from S towards T where there is a flow
 *		and 1 where there isn't flow, it's the residual graph
 *		here i want suppr the interne shortcut
 *
 */



/*
 *			go reflechir a une solution faisable pour ce truc
 *
 */

/*
void		lm_suppr_internal_shortcut(t_sommet **graph)
{
	t_sommet	*cur;
	t_adj_lst	*lst;
	t_adj_lst	*edge;

	lst = graph[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		while (cur->prev)
		{
			cur = lm_get_sommet(graph, lst);
			while ()
		}
		lst = lst->next;
	}
}*/
