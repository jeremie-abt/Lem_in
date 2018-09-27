/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_bfs_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:32:23 by jabt              #+#    #+#             */
/*   Updated: 2018/09/27 17:26:14 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 		INPUT
**		Je recois un graph de flow sous forme de hashtable
**		je ne peut toucher que au node visited == 0
**		la valeur visited des nodes debut et fin est egale a 0
*/

void			lm_init_graph(t_sommet **graph)
{
	graph[0]->visited = 1;
	graph[1]->visited = 0;
}

int				lm_find_one_path_with_bfs(t_sommet **graph)
{
	t_control_queue		control;
	t_sommet			*cur;

	lm_init_graph(graph);
	ft_bzero(&control, sizeof(t_control_queue));
	if (!lm_add_elem_queue(&control, graph[0]))
		return (-1);
	while (control.head || control.tail)
	{
		cur = lm_pop_queue(&control);
		if (cur == graph[1])
		{
			lm_free_queue(&control);
			return (1);
		}
		else
		{
			if (!lm_add_neighboor(graph, cur, &control))
			{
				lm_free_queue(&control);
				return (-1);
			}
		}
	}
	return (0);
}

/*
** 		OUTPUT
**		return = 1 if one worth path is found
**		return 0 if 0 path are found or if the found path aren't worth
**		return -1 to indicate a problem to the calling procedure,
**		meaning quitting correctly the program
*/

/*
** 	INPUT
** 	graph like above i can touch only 0s visited node
*/

t_sommet		*lm_get_node_to_reverse_bfs(t_sommet **resid_graph)
{
	t_control_queue		control;
	t_sommet			*cur;
	int					distance;

	distance = 1;
	lm_init_graph(resid_graph);
	ft_bzero(&control, sizeof(t_control_queue));
	if (!lm_add_elem_queue(&control, resid_graph[0]))
	{
		lm_free_queue(&control);
		return (NULL);
	}
	while (control.head || control.tail)
	{
		cur = lm_pop_queue(&control);
		if (cur != resid_graph[1] && cur->visited == 2)
		{
			lm_free_queue(&control);
			return (cur);
		}
		else if (!lm_add_neighboor_visited2(resid_graph, cur, &control))
			return (NULL);
	}
	return (NULL);
}

/*
** 	OUTPUT
** 	return the first node reach by a bfs which has its visited value to
** 	2 and isn't the end node
** 	NULL if there is no such node, meaning no path in the resid_graph
*/

/*
** 	INPUT
** 	the resid_graph and one node within it
** 	PROCEDURE
** 	i want to run a BFS unti the end node is reached
** 	with all the nodes that aren't visited == 2
** 	and relaxe the distance, meaning for e(u,v) if dist(v) > dist(u) + 1
** 	then dist(v) = dist(u) + 1
*/

int				lm_relaxing_bfs(t_sommet **resid_graph, t_sommet *node)
{
	t_control_queue		control;
	t_sommet			*cur;
	int					state;

	state = 0;
	lm_init_graph(resid_graph);
	ft_bzero(&control, sizeof(t_control_queue));
	if (!lm_add_elem_queue(&control, node))
		return (-1);
	while (control.head || control.tail)
	{
		cur = lm_pop_queue(&control);
		if (!state && cur == resid_graph[1])
			state = 1;
		else if (!state)
		{
			if (!lm_add_neighboor_relaxing(resid_graph, cur, &control))
			{
				lm_free_queue(&control);
				return (-1);
			}
		}
	}
	return (0);
}
