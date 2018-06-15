/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_start_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:58:09 by galemair          #+#    #+#             */
/*   Updated: 2018/06/15 16:15:36 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_queue_neighbor(t_sommet *head, t_sommet **queue, t_sommet **sommet)
{
	t_sommet	*tmp;
	t_adj_list	*adj_lst;

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

int			lm_start_algo(t_sommet **sommet, int ants)
{
	t_sommet *queue;

	queue = NULL;
	sommet[1]->distance = -1;
	add_in_queue(&queue, sommet[0]);
	queue->distance = 0;
	get_distance(sommet, &queue);
	printf("ok je sors :\n\n");
	print_all_hashtable_wdistance(sommet);

	exit(4);
	return (0);
}
