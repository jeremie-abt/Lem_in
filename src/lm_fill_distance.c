/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_fill_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:58:09 by galemair          #+#    #+#             */
/*   Updated: 2018/08/23 14:25:42 by jabt             ###   ########.fr       */
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

// gaff ici mais jsuis casi sur qu'il y a pas
//		besoins add le voisins a la queue car cette condition ne peut pas tenir si le node
//		v n'a pas deja ete visite au prealable (a verif mais ya moyen)
		adj_lst = adj_lst->next;
	}
	return (1);
}

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
