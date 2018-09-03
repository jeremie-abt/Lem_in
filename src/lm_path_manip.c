/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:49:18 by jabt              #+#    #+#             */
/*   Updated: 2018/09/02 16:55:15 by jabt             ###   ########.fr       */
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

t_sommet		*lm_bfs_valid_path(t_sommet **graph, t_sommet *node)
{
	assert(node->prev != NULL);
	assert(node == graph[1]);

	t_sommet	*cur;
	t_adj_lst	*edge;
	int			length;

	length = 0;
	cur = node->prev;
	edge = lm_get_edge(cur->lst, node->name);
	edge->flow = 0;
	if (cur == graph[0])
		return (cur);
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
	return (cur);
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

/*
 * 		INPUT
 * 		hashtable avec le node du path qui vient juste d'etre ajouter par mon bfs
 */

int				lm_is_worth_path(t_sommet **graph, t_sommet *node, int *ants,
		int path)
{
	static t_sommet		*cur;
	
	if (node == graph[0])	
		return (1);
	if (!cur)
	{
		cur = node;
		if (*ants > 0)
			return (1);
	}
	else
	{
		(*ants) -= (node->distance - cur->distance) * (path - 1);
		if (*ants >= path)
		{
			cur = node;
			*ants -= path;
			return (1);
		}
		else
		{
			lm_cancel_chosen_path(graph, node);
			return (0);//procedure pour annuler ce chemin
		}
	}
	return (0);
}

/*
 * 		OUTPOUT
 * 		si le path est worth return 1
 * 		sinon return 0 et enlever le path choisis car il n'est pas
 * 		rentalbe
 */


