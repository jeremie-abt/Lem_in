/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:49:18 by jabt              #+#    #+#             */
/*   Updated: 2018/09/05 14:38:28 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 		INPUT
 * 		hashtable and first node of the path to reverse
 */


void			lm_cancel_chosen_path(t_sommet **graph, t_sommet *node)
{
	t_sommet	*cur;
	t_sommet	*tmp;

	cur = node;
	while (cur)
	{
		tmp = cur;
		cur = cur->prev;
		tmp->visited = 0;
		tmp->prev = NULL;
	}
}

/*
 * 		but : valider un path -> on remonte tous le path et on 
 * 		met des visited = 2 sur tous les node en commencent 
 * 		par le previous de node
 */

void			lm_bfs_valid_path(t_sommet **graph)
{
	assert(graph[1]->prev != NULL);

	t_sommet	*cur;
	t_sommet	*node;
	t_adj_lst	*edge;
	int			length;

	length = 0;
	node = graph[1];
	cur = node->prev;
	edge = lm_get_edge(cur->lst, node->name);
	edge->flow = 0;
	if (cur == graph[0])
		return ;
	while (cur != graph[0])
	{
		length++;
		cur->visited = 2;
		edge = lm_get_edge(cur->prev->lst, cur->name);
		edge->flow = 0;
		cur = cur->prev;
 	}
	edge->flow = 0;
	cur = node->prev;
	cur->distance = length;
	node->prev = NULL;
//	return (cur);
} 

/*
 * 		OUTPOUT
 * 		tous les nodes de mon path on ete mis a visited = 2 sauf node
 * 		(correspond au node end) et node->prev remis a null, sauf si connec
 * 		entre end et start
 * 		RETURN
 * 		return the node of the path wich has been treated
 * 		if the start and end are connected, then return the start node
 */

