/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reverse_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:33:59 by jabt              #+#    #+#             */
/*   Updated: 2018/09/03 17:28:22 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 *		the reverse procedure are normally just made on the residual graph
 */

/*
 * 	INPUT
 * 	resid_graph, first_node wich is the first node of the shortcut but in
 * 	the real graph and end node which is the last node of the shortcut
 */

static void		lm_reverse_shortcut_valid(t_sommet **resid_graph,
		t_sommet *first_node, t_sommet *end_node)
{
	//ici normalement je dois avoir first 6 et second 3 dans le resid graph
	t_sommet	*test;
	t_sommet	*second_node;
	t_adj_lst	*edge;

	second_node = lm_get_sommet(resid_graph, first_node->prev->name);
//	printf("first node avant : %s addr : %p\n", first_node->name, first_node);
	first_node = lm_get_sommet(resid_graph, first_node->name);
	while (first_node != end_node)
	{
		edge = lm_get_edge(second_node->lst, first_node->name);
		edge->flow = 1;
		if (second_node != end_node)
		{
			second_node->visited = 0;
			second_node->distance = -1;
		}
		first_node = second_node;
		second_node = second_node->prev;
	}
}

/*
 * 	INPUT
 *	resid_graph, the last node to reverse until a certain limit
 */

static t_sommet		*lm_reverse_one_part(t_sommet **resid_graph,
		t_sommet *first_node, t_sommet *second_node)
{
	t_sommet	*tmp;
	t_adj_lst	*edge;

	//edge = second_node->lst;
//	tmp = resid_graph[1];
	while (second_node->visited == 1)
	{
		second_node->visited = 2;
		edge = lm_get_edge(second_node->lst, first_node->name);
		edge->flow = 0;
		first_node = second_node;
		second_node = second_node->prev;
	}
	edge = lm_get_edge(second_node->lst, first_node->name);
	edge->flow = 0;
	return (second_node);	
}

/*
 * 	OUTPOUT
 * 	the part after a shortcut has to be reversed
 * 	the prev var of the end node has to be NULLed
 * 	RETURN
 * 	the last node of the shortcut
 */

/*
 *	INPUT
 *	resid_graph sous forme de hashtable, le node de fin doit avoir
 *	sa var prev init sur le path qui va etre traite par la fonction
 *	le vraie graph
 *	et le premier node visited == 2 que mon bfs a trouve juste avant
 *	dans le vraie graph
 */

void			lm_reverse_valid_path(t_sommet **resid_graph,
		t_sommet **graph, t_sommet *node)
{
	assert(resid_graph[1]->prev);
	assert(!graph[1]->prev);

	t_sommet	*cur;

	resid_graph[0]->visited = 0;
	cur = lm_reverse_one_part(resid_graph, resid_graph[1], resid_graph[1]->prev);	
	resid_graph[1]->prev = NULL;
	resid_graph[1]->visited = 0;


	lm_reverse_shortcut_valid(resid_graph, node, cur);
	cur = lm_get_sommet(resid_graph, node->name);
	lm_reverse_one_part(resid_graph, cur, cur->prev);
	print_flow(resid_graph);
	printf("\n\n");
	print_hashtable_distance_and_prev(resid_graph);
	exit(4);

}

/*
 * 	OUTPOUT
 * 	the path which has beem  validated
 * 	in all case i must have my hashtable clean meaning all node that aren't
 * 	visited == 2 have their visited =0 and prev = NULL
 */
