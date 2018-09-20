/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_update_main_graph.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:23:41 by jabt              #+#    #+#             */
/*   Updated: 2018/09/19 16:12:08 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_update_lst(t_adj_lst *lst, t_adj_lst *resid_lst)
{
	t_adj_lst	*edge;

	while (resid_lst)
	{
		edge = lm_get_edge(lst, resid_lst->name);
		edge->flow = resid_lst->flow;
		resid_lst = resid_lst->next;
	}
}

static void		lm_update_node(t_sommet **graph, t_sommet *node,
		t_sommet *resid_node)
{
	t_sommet	*tmp;

	while (node)
	{
		if (resid_node->prev)
		{
			tmp = lm_get_sommet(graph, resid_node->prev->name);
			node->prev = tmp;
		}
		else
			node->prev = NULL;
		node->distance = resid_node->distance;
		node->visited = resid_node->visited;
		lm_update_lst(node->lst, resid_node->lst);
		node = node->next;
		resid_node = resid_node->next;
	}
}

void			lm_update_main_graph(t_sommet **graph, t_sommet **resid_graph)
{
	int			i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (graph[i])
			lm_update_node(graph, graph[i], resid_graph[i]);
		i++;
	}
}
