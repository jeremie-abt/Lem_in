/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_max_flow_prob.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:03:04 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 16:55:04 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			lm_reverse_path(t_sommet **graph, t_sommet *node)
{
	t_adj_lst	*edge;
	t_adj_lst	*reverse_edge;

	edge = lm_get_edge(node->lst, graph[1]->name);
	edge->flow = 0;

	while (node->prev)
	{
		reverse_edge = lm_get_edge(node->lst, node->prev->name);
		edge = lm_get_edge(node->prev->lst, node->name);
		if (reverse_edge->flow == 0) // en gros ca c'est quand je prends une arc negative
			reverse_edge->flow = 1;
		else
			edge->flow = 0;	
		node = node->prev;
	}
}

int				lm_search_path_dfs(t_sommet **graph)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	int			ret;
	
	lm_clean_visited(graph);
	graph[0]->visited = 1;
	lst = graph[0]->lst;
	ret = 0;
	while (lst)
	{
		if (lst->flow == 1)
		{
			cur = lm_get_sommet(graph, lst->name);
			if (!cur->visited)
			{
				cur->visited = 1;
				cur->prev = graph[0];
				while ((cur = lm_get_next_node_dfs(graph, cur)))
					if (cur == graph[1])
					{
						lm_reverse_path(graph, cur->prev);
						cur->prev = NULL;
						ret = 1;
					}
			}
		}
		lst = lst->next;
	}
	return (ret);
}

int		lm_find_max_flow(t_sommet **graph)
{
	t_sommet	**resid_graph;	
	int			path;
	int			tmp;
	
	path = 0;
	tmp = 0;
	resid_graph = lm_copy_hashtable();
	while ((tmp = lm_search_path_dfs(resid_graph)))
	{
		path += tmp;
		lm_update_main_graph(sommet, resid_graph);
	}
	// faire la procedure pour free le resid graph
	return (path);
}
