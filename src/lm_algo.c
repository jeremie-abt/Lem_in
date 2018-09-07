/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:39:02 by jabt              #+#    #+#             */
/*   Updated: 2018/09/07 14:12:44 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 	INPUT
 * 	graph de resid qui contient le graph original copie a l'identique
 * 	avec son flow, si ya pas de flow ca ne doit pas rentrer la
 */

static 	int			lm_optimize_and_reverse_shortcut(t_sommet **graph, 
		t_sommet **resid_graph, int ants)
{
	t_sommet	*save_last_node;	
	t_sommet	*cur_graph;
	t_sommet	*cur_resid_graph;
	int			ret;

	ret = 0;
	while  ((save_last_node = lm_get_node_to_reverse_bfs(resid_graph))) // debugger un peu cette fonction aussi
	{
		save_last_node = lm_get_sommet(graph, save_last_node->name);
		cur_graph = lm_get_sommet(graph, save_last_node->name);
		cur_graph = cur_graph->prev;
		cur_resid_graph = lm_get_sommet(resid_graph, cur_graph->name);
		cur_resid_graph->distance = cur_graph->distance;
		while (cur_resid_graph != resid_graph[0])
		{
			lm_relaxing_bfs(resid_graph, cur_resid_graph);
			cur_resid_graph = cur_resid_graph->prev;
			cur_graph = lm_get_sommet(graph, cur_resid_graph->name);
			cur_resid_graph->distance = cur_graph->distance;
		}
		if (resid_graph[1]->prev && lm_is_worth_path_flow(graph, resid_graph,
					save_last_node, ants))
		{
			lm_reverse_valid_path(resid_graph, graph, save_last_node);
			ret++;
		}
		else
			lm_reverse_wrong_path(resid_graph, graph, save_last_node);
		lm_clean_resid_graph(resid_graph);
	}
	return (ret);
}

/*
 * 	OUTPOUT
 *	un flow modifie ou pas s'il etait deja le plus opti
 */


/*
 * 		INPUT
 * 		une hashtable de taille HASH_SIZE
 * 		un nombre de fourmis qui doit etre sup a 0 normalement
 * 		qui represente un graph flow
 * 		le node debut est hashtable[0] et celui de fin est hashtable[1]
 * 		le but est de renvoyer le maximum de shortest path distinct
 * 		via un bfs donc sans faire attention aux shortcut
 */

static int			lm_find_shortest_distinct_path(t_sommet **graph,
		int ants)
{
	int		ret;
	int		path;

	path = 0;
	//ret = lm_find_one_path_with_bfs(graph, ants, path);
	//if (graph[1]->prev == graph[0])
	//	return (1);
	while (lm_find_one_path_with_bfs(graph, ants, path)/*ret && path < ants*/)
	{

		// verif si le path qui vient detre trouve est rentable
		if (lm_is_worth_path_bfs(graph, ants, path))
		{
			lm_bfs_valid_path(graph);
			path++;// procedure pour verif lefficacite dun path
		}
		else
		{
			//procedure pour reverse un path
			break ;
		}
		lm_clean_visited(graph);
		//ret = lm_find_one_path_with_bfs(graph, ants, path);
	}
	lm_clean_visited(graph);
	return (path);
}

/*
 * 		RETURN
 * 		nombre de path
 * 		chaque node etant dans un path a part debut et end
 * 		doivent avoir leurs node prev a leur precedent et visited = 2
 */

int					lm_find_best_flow(t_sommet **graph, int ants)
{
	int			path;
	//	int			save_ants;
	t_sommet	**resid_graph;

	///	save_ants = *ants;
	path = lm_find_shortest_distinct_path(graph, ants);

	graph[1]->distance = 0;

	resid_graph = lm_copy_hashtable(graph);// go enlever cette globale de merde

	lm_fill_distance_flow(graph);// ca devrait pas me remplir la fin
	// c'est vraiment naze
	path += lm_optimize_and_reverse_shortcut(graph, resid_graph, ants);
	lm_free_resid_graph(resid_graph);
	free(resid_graph);
	ft_bzero(resid_graph, sizeof(t_sommet *) * HASH_SIZE);

	return (path);
}

