/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_fill_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:18:33 by jabt              #+#    #+#             */
/*   Updated: 2018/08/31 09:19:04 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_add_neighboor_bydist(t_sommet **sommet, t_sommet *node,
		t_control_queue *control_queue)
{
	t_adj_lst	*adj_lst;
	t_sommet	*cur; // for edge (u,v), this correspond to v and node == u
	int			distance;

	distance = node->distance;
	adj_lst = node->lst;
	while (adj_lst)
	{
		cur = lm_get_sommet(sommet, adj_lst->name);
		if  (cur->distance > distance + 1)
		{
			cur->distance = distance + 1;
			cur->prev = node;
		}
		else if (cur->distance == -1 || (sommet[1]->distance <= 0 && cur == sommet[1]))
		{
			cur->distance = distance + 1;
			cur->prev = node;
			if (cur != sommet[1] && lm_add_elem_queue(control_queue, cur) == -1)
				return (-1); // attention a bien free dans la fonction appelante ou ici
		}
		adj_lst = adj_lst->next;
	}
	return (1);
}
/*
int			lm_add_neighboor_bfs(t_sommet **sommet, t_sommet *node,
		t_control_queue *control_queue)
{
	t_adj_lst	*adj_lst;
	t_sommet	*cur; // for edge (u,v), this correspond to v and node == u

	adj_lst = node->lst;
	while (adj_lst)
	{
		cur = lm_get_sommet(sommet, adj_lst->name);
		if  (!cur->visited)
			lm_add_elem_queue(control_queue, cur);
		adj_lst = adj_lst->next;
	}
	return (1);
}
*/

void			lm_fill_distance_flow(t_sommet **graph)
{
	t_adj_lst		*lst;
	t_adj_lst		*tmp_lst;
	t_sommet		*cur;
	int				distance;

	lst = graph[0]->lst;
	while (lst)
	{
		if (lst->flow == 0)
		{
			distance = 1; 
			cur = lm_get_sommet(graph, lst->name);
			cur->distance = distance;
			while (cur != graph[1])
			{
				distance++;
				tmp_lst = cur->lst;
				while (tmp_lst->flow != 0)
					tmp_lst = tmp_lst->next;
				cur = lm_get_sommet(graph, tmp_lst->name);
				cur->distance = distance;
			}
			lst->flow = distance;//c'est bon ?
		}
		lst = lst->next;
	}
}

int			lm_fill_distance(t_sommet **sommet, int ants)
{
	t_control_queue		control;
	t_sommet			*ret;

	ft_bzero(&control, sizeof(t_control_queue));
	// fonction pour parcourir tous les voisins et les add a la liste

	if (lm_add_neighboor_bydist(sommet, sommet[0], &control) == -1) // init
	{
		// attention a bien free m queue si elle existe encore
		return (-1);
	}
	while (control.tail || control.head)
	{
		ret = lm_pop_queue(&control);
		lm_add_neighboor_bydist(sommet, ret, &control);
	}
	ft_bzero(&control, sizeof(t_control_queue));
	return (0);
}
