/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_is_worth_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:19:40 by jabt              #+#    #+#             */
/*   Updated: 2018/09/05 18:41:46 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet	*lm_get_last_node_by_flow(t_sommet **graph, t_sommet *node)
{
	return (NULL);	
}

/*
 * 	INPUT
 * 	node jsute avant node de fin
 */

static void		lm_count_length_path(t_sommet *node)
{
	int			ret;
	t_sommet	*tmp;

	ret = 0;
	tmp = node;
	while (node->prev)
	{
		ret++;
		node = node->prev;
	}
	tmp->distance = ret;
}

/*
 * 	INPUT
 * 	graph et resid_graph et les deux extremite de ma shortcut dans le resid_graph
 * 	et le first node de la shortcut a reverse dans le vraie graph
 */

int		lm_is_worth_path_flow(t_sommet **graph, t_sommet **resid_graph,
		t_sommet *first_node) // bon evidemment il faudra faire cette fonction
{
	t_sommet	*res_first_node;
/*	t_sommet	*shortcut;
	t_sommet	*cur;

	// procedure pour avoir le last node de mes trois var
	res_first_path = lm_get_last_node_by_flow(resid_graph, res_first_path);
	res_sec_path = lm_get_last_node_by_flow(resid_graph, res_sec_path);
	sho*/

	res_first_node = lm_get_sommet(resid_graph, first_node->name);

	printf("ici\n");

	exit(0);



	return (0);	
}

/*
 * 		INPUT
 * 		hashtable avec le node du path qui vient juste d'etre ajouter par mon bfs
 */

int				lm_is_worth_path_bfs(t_sommet **graph, int ants,
		int path)
{
	static int		ret;
	static int		worthiness;
	int				tmp;
	assert(graph[1]->prev);
	
	lm_count_length_path(graph[1]->prev);	
	if (ret == 0)
	{
		if (ants > 0)
			ret = graph[1]->prev->distance;
		return (1);
	}
	else
	{
		if (!worthiness)
		{
			worthiness = (graph[1]->prev->distance - ret) + path + 1;
			ret = graph[1]->prev->distance;
			if (worthiness <= ants)
				return (1);
		}
		else
		{
			tmp = (graph[1]->prev->distance - ret) - 1;
			if (tmp >= 0)
				worthiness = worthiness + ((tmp * path) + path + 1);
			else
				worthiness++;
			ret = graph[1]->prev->distance;
			if (worthiness <= ants)
				return (1);
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


