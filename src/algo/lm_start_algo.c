/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_start_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:58:09 by galemair          #+#    #+#             */
/*   Updated: 2018/06/07 15:39:47 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_queue_neigbor(t_sommet *head, t_sommet **queue, t_sommet **sommet)
{
	t_sommet	*tmp;

	while (head->lst)
	{
		if (tmp->distance == 0 && ft_strcmp(tmp->name, graphe[1]->name) != 0)
		{
			add_in_queue(queue, tmp);
			tmp->distance = head->distance + 1;
		}
		head->lst = (head->lst)->next;
	}
}

int			get_distance(t_sommet **sommet, t_sommet **queue)
{
	/*
	 * Traitement des elements de la queue
	 */
	while (*queue) // TROUVER UNE CONDITION D'ARRET POUR OPTI
		lm_queue_neighbor(exit_queue(queue), queue);
	return (0);
}

int			lm_start_algo(t_sommet **sommet, int ants)
{
	t_sommet *queue;

	queue = NULL;
	add_in_queue(&queue, sommet[0])	
	queue->distance = 0;
	/*
	 * Find shortest path
	 * Eventualy the second shortest path
	 * if nombre de tours est plus opti avec deux chemins et queue != NULL chercher une troisieme chemin
	 * boucler sur ca
	*/
	get_distance(sommet, &queue);
}
