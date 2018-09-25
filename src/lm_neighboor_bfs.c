/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_neighboor_bfs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 17:57:25 by jabt              #+#    #+#             */
/*   Updated: 2018/09/25 15:41:19 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 		INPUT
** 		procedure pour ajouter tous les voisins bfs
** 		Je recois un graph de flow et un node dans ce graph
** 		je veux ajouter tous les neighboor qui ne sont pas visited
** 		le node de debut doit etre visited
*/

int			lm_add_neighboor(t_sommet **graph, t_sommet *node,
		t_control_queue *control)
{
	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (lst->flow == 1 && cur->visited == 0)
		{
			if (!lm_add_elem_queue(control, cur))
				return (-1);
			cur->visited = 1;
			cur->prev = node;
		}
		lst = lst->next;
	}
	return (1);
}

/*
** 	PROCEDURE
** 	the same input and role as the function just above just if cur happens
** 	to be graph[1], then don't touch to the graph[1]->prev node
*/

int			lm_add_neighboor_relaxing(t_sommet **graph, t_sommet *node,
		t_control_queue *control)
{
	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (lst->flow == 1 && cur->visited != 1 && cur->visited != 2)
		{
			if (cur->distance > node->distance + 1 || cur->distance == -1 ||
					cur->distance == 0)
			{
				cur->distance = node->distance + 1;
				cur->prev = node;
				if (!lm_add_elem_queue(control, cur))
					return (-1);
			}
		}
		lst = lst->next;
	}
	return (1);
}

int			lm_add_neighboor_visited2(t_sommet **graph, t_sommet *node,
		t_control_queue *control)
{
	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (lst->flow == 1 && (cur->visited == 2 || cur->visited == 0) &&
				cur != graph[1])
		{
			if (!lm_add_elem_queue(control, cur))
				return (-1);
			if (cur->visited == 0)
				cur->visited++;
			cur->prev = node;
			cur->distance = node->distance + 1;
		}
		lst = lst->next;
	}
	return (1);
}
