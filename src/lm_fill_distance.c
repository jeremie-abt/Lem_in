/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_fill_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:58:09 by galemair          #+#    #+#             */
/*   Updated: 2018/07/10 16:53:36 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
void			lm_queue_neighbor(t_sommet *head, t_sommet **queue, t_sommet **sommet)
{
	t_sommet	*tmp;
	t_adj_lst	*adj_lst;

	adj_lst = head->lst;
	while (adj_lst)
	{
		tmp = lm_get_sommet(sommet, adj_lst->name);
		if (tmp->distance == -1)
		{
			add_in_queue(queue, tmp);
			tmp->distance = head->distance + 1;
		}
		adj_lst = adj_lst->next;
	}
}

int			get_distance(t_sommet **sommet, t_sommet **queue)
{
	while (*queue) // TROUVER UNE CONDITION D'ARRET POUR OPTI
		lm_queue_neighbor(exit_queue(queue), queue, sommet);
	return (0);
}
*/

int		lm_add_neighboor_queue(t_sommet **sommet, t_sommet *node,
		t_control_queue *control_queue)
{
	t_adj_lst	*adj_lst;
	t_sommet	*cur;
	int			distance;

	distance = node->distance;
	adj_lst = node->lst;
	while (adj_lst)
	{
		cur = lm_get_sommet(sommet, adj_lst->name);

		if (cur->distance > distance + 1)
			cur->distance = distance + 1;
		else if (cur->distance == -1)
		{
			cur->distance = distance + 1;
			if (lm_add_elem_queue(control_queue, cur) == -1)
				return (-1); // attention a bien free dans la fonction appelante ou ici
		}
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

	if (lm_add_neighboor_queue(sommet, sommet[0], &control) == -1)
	{
		// attention a bien free m queue si elle existe encore
		return (-1);
	}
	while (control.tail || control.head)
	{
		ret = lm_pop_queue(&control);
		lm_add_neighboor_queue(sommet, ret, &control);
	}
	ft_bzero(&control, sizeof(t_control_queue));

	return (0);
}
