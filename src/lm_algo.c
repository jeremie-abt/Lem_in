/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:39:02 by jabt              #+#    #+#             */
/*   Updated: 2018/09/12 16:43:48 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			lm_iter_reverse_shortcut(t_sommet **graph,
		t_sommet **resid_graph, t_shortcut *scut)
{
	scut->save_last_node = lm_get_sommet(graph, scut->save_last_node->name);
	scut->cur_graph = lm_get_sommet(graph, scut->save_last_node->name);
	scut->cur_graph = scut->cur_graph->prev;
	scut->cur_resid_graph = lm_get_sommet(resid_graph, scut->cur_graph->name);
	scut->cur_resid_graph->distance = scut->cur_graph->distance;
}

/*
** 	PROCEDURE
** 	update the distance from one point in the resid_graph
** 	by relaxing the edges like djikstra algorithm
*/

static int			lm_relaxe_from_one_point(t_sommet **graph,
		t_sommet **resid_graph, t_shortcut *scut)
{
	while (scut->cur_resid_graph != resid_graph[0])
	{
		if (lm_relaxing_bfs(resid_graph, scut->cur_resid_graph) == -1)
			return (-1);
		scut->cur_resid_graph = scut->cur_resid_graph->prev;
		scut->cur_graph = lm_get_sommet(graph, scut->cur_resid_graph->name);
		scut->cur_resid_graph->distance = scut->cur_graph->distance;
	}
	return (1);
}

/*
** 		INPUT
** 		graph de resid qui contient le graph original copie a l'identique
** 		avec son flow, si ya pas de flow ca ne doit pas rentrer la
*/

static int			lm_optimize_and_reverse_shortcut(t_sommet **graph,
		t_sommet **resid_graph, int ants)
{
	t_shortcut	scut;
	int			ret;

	ret = 0;
	while ((scut.save_last_node = lm_get_node_to_reverse_bfs(resid_graph)))
	{
		lm_iter_reverse_shortcut(graph, resid_graph, &scut);
		if (lm_relaxe_from_one_point(graph, resid_graph, &scut) == -1)
			return (0);
		if (resid_graph[1]->prev && lm_is_worth_path_flow(graph, resid_graph,
					scut.save_last_node, ants))
		{
			lm_reverse_valid_path(resid_graph, graph, scut.save_last_node);
			ret++;
		}
		else
			lm_reverse_wrong_path(resid_graph, scut.save_last_node);
		lm_clean_resid_graph(resid_graph);
	}
	return (ret);
}

/*
** 		OUTPOUT
**		un flow modifie ou pas s'il etait deja le plus opti
*/

/*
** 		INPUT
** 		une hashtable de taille HASH_SIZE
** 		un nombre de fourmis qui doit etre sup a 0 normalement
** 		qui represente un graph flow
** 		le node debut est hashtable[0] et celui de fin est hashtable[1]
** 		le but est de renvoyer le maximum de shortest path distinct
** 		via un bfs donc sans faire attention aux shortcut
*/

static int			lm_find_shortest_distinct_path(t_sommet **graph,
		int ants)
{
	int		path;

	path = 0;
	while (lm_find_one_path_with_bfs(graph) > 0)
	{
		if (graph[1]->prev == graph[0])
			return (1);
		if (lm_is_worth_path_bfs(graph, ants, path))
		{
			lm_bfs_valid_path(graph);
			path++;
		}
		else
			break ;
		lm_clean_visited(graph);
	}
	lm_clean_visited(graph);
	return (path);
}

/*
** 		RETURN
** 		nombre de path
** 		chaque node etant dans un path a part debut et end
** 		doivent avoir leurs node prev a leur precedent et visited = 2
*/

int					lm_find_best_flow(t_sommet **graph, int ants)
{
	int			path;
	t_sommet	**resid_graph;

	path = lm_find_shortest_distinct_path(graph, ants);
	if (path == 1 && graph[1]->prev == graph[0])
		return (1);
	if (path <= 0)
		return (path);
	graph[1]->distance = 0;
	if (!(resid_graph = lm_copy_hashtable(graph)))
	{
		lm_free_resid_graph(resid_graph);
		free(resid_graph);
		return (path);
	}
	lm_fill_distance_flow(graph);
	path += lm_optimize_and_reverse_shortcut(graph, resid_graph, ants);
	
	
	
	
	lm_free_resid_graph(resid_graph);
	free(resid_graph);
	ft_bzero(resid_graph, sizeof(t_sommet *) * HASH_SIZE);
	return (path);
}
