/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_neighboor_bfs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 17:57:25 by jabt              #+#    #+#             */
/*   Updated: 2018/09/03 12:32:34 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


/*
 * 		INPUT
 * 		procedure pour ajouter tous les voisins bfs
 * 		Je recois un graph de flow et un node dans ce graph
 * 		je veux ajouter tous les neighboor qui ne sont pas visited
 * 		ou qui ont la valeur limit (limit ne doit pas etre
 * 		egale a 1) le node de debut doit etre visited
 */

int			lm_add_neighboor(t_sommet **graph, t_sommet *node,
		t_control_queue *control)
{
	assert(graph[0]->visited > 0);
	assert(node->visited > 0);

	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (lst->flow == 1 && cur->visited == 0)// attention au flow normalement c von mais ....
		{
			if (!lm_add_elem_queue(control, cur))
				return (-1);// faut free ici je pense
			cur->visited++;
			cur->prev = node;
		}
		lst = lst->next;
	}
	return (1);
 }
/*
int			lm_add_neighboor_relaxing(t_sommet **graph, t_sommet *node,
		t_control_queue *control)
{
	assert(graph[0]->visited > 0);
	assert(node->visited > 0);

	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (lst->flow == 1 && cur->visited == 0)// attention au flow normalement c von mais ....
		{
			if (!lm_add_elem_queue(control, cur))
				return (-1);// faut free ici je pense
			cur->visited++;
			cur->prev = node;
		}
		lst = lst->next;
	}
	return (1);
 }

*/

int			lm_add_neighboor_visited2(t_sommet **graph, t_sommet *node,
		t_control_queue *control)
{
	assert(graph[0]->visited > 0);
	assert(node->visited > 0);

	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (lst->flow == 1 && (cur->visited == 2 || cur->visited == 0) &&
				cur != graph[1])// attention au flow normalement c von mais ....
		{
			if (!lm_add_elem_queue(control, cur))
				return (-1);// faut free ici je pense
			if (cur->visited == 0)
				cur->visited++;
			cur->prev = node;
			cur->distance = node->distance + 1;
		}
		lst = lst->next;
	}
	return (1);
}
