/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_update_main_graph.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:23:41 by jabt              #+#    #+#             */
/*   Updated: 2018/09/07 14:00:02 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 		sec_lst = resid_graph
 */

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

static void		lm_update_parent_main_graph(t_sommet **graph, t_sommet *node,
		t_sommet *resid_node)
{
	t_sommet	*tmp;

	tmp = lm_get_sommet(graph, resid_node->prev->name);
	node->prev = tmp;
}

void			lm_update_main_graph(t_sommet **graph, t_sommet **resid_graph)
{
	int			i;
	t_sommet	*cur;
	t_sommet	*resid_cur;
	t_sommet	*tmp;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (graph[i])
		{
			cur = graph[i];
			resid_cur = resid_graph[i];
			while (cur)
			{
				if (resid_cur->prev)
				{
					tmp = lm_get_sommet(graph, resid_cur->prev->name);
					cur->prev = tmp;
				}
				else
					cur->prev = NULL;
				cur->distance = resid_cur->distance;
				cur->visited = resid_cur->visited;
				lm_update_lst(cur->lst, resid_cur->lst);
				cur = cur->next;
				resid_cur = resid_cur->next;
			}
		}
		i++;
	}
}

