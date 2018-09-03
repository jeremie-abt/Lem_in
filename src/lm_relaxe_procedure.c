/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_relaxe_procedure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:41:06 by jabt              #+#    #+#             */
/*   Updated: 2018/09/03 20:02:41 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 	INPUT
 * 	resid graph one node
 * 	PROCEDURE
 * 	i've to relaxe all the connected node to this node
 * 	meaning for e(u,v), i receive u as the var node
 * 	and if dist(v) > dist(u) + 1, then dist(v) = dist(u) + 1
 * 	i have to relaxe only the node which aren't visited == 2
 */

void		lm_relaxe_all_edge_node(t_sommet **resid_graph, t_sommet *node)
{
	t_adj_lst	*lst;
	t_sommet	*cur;

	if (node->visited < 2)
		node->visited = 1;
	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(resid_graph, lst->name);
		if (cur->visited <= 1)
		{
			if (cur->distance == -1 ||
					(cur->distance > node->distance + 1 && node->distance > 0))
			{
				printf("cur : %s\n", cur->name);
				if (cur == resid_graph[1])// test cette cond
				{
						printf("node : %s\n", node->name);
					if (cur->distance == 0  || (cur->distance > node->distance + 1))
					{
						cur->distance = node->distance + 1;
						cur->prev = node;
					}
				}
				else
				{
					cur->distance = node->distance + 1;
					cur->prev = node;
				}
			}
		}
		lst = lst->next;
	}
}
