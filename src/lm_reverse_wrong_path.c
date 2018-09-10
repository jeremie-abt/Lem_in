/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reverse_wrong_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:20:54 by jabt              #+#    #+#             */
/*   Updated: 2018/09/10 16:15:26 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			lm_reverse_first_part(t_sommet **resid_graph,
		t_sommet *node)
{
	t_sommet	*tmp;

	node = node->prev;
	while (node != resid_graph[0])
	{
		node->visited = 0;
		tmp = node->prev;
		node->prev = NULL;
		node = tmp;
	}
}

/*
**	INPUT
**	resid_graph sous forme de hashtableh
**	et le premier node visited == 2 que mon bfs a trouve juste avant
**	dans le vraie graph
*/

void				lm_reverse_wrong_path(t_sommet **resid_graph,
		t_sommet **graph, t_sommet *node)
{
	t_sommet	*resid_node;
	t_adj_lst	*edge;

	resid_graph[1]->prev = NULL;
	resid_graph[1]->visited = 0;
	resid_graph[1]->distance = 0;
	resid_node = lm_get_sommet(resid_graph, node->name);
	edge = lm_get_edge(resid_node->prev->lst, resid_node->name);
	edge->flow = 0;
}
