/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_start_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:58:09 by galemair          #+#    #+#             */
/*   Updated: 2018/06/05 18:48:17 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lm_queue_neigbor(t_sommet *head, t_sommet **queue, t_sommet **sommet)
{
	int			final_distance;
	t_sommet	*tmp;

	final_distance = 0;
	while (head->lst)
	{
		tmp = lm_get_adress((head->lst)->neighbor, sommet);
		if (ft_strcmp(tmp->name, graphe[1]->name) == 0) 
			final_distance = head->distance + 1;
		else if (tmp->distance == 0)
		{
			add_in_queue(queue, tmp);
			tmp->distance = head->distance + 1;
		}
		head->lst = (head->lst)->next;
	}
	return (final_distance);
}

int			find_shortest_path(t_sommet **sommet, t_sommet **queue)
{
	int		shortest_distance;
	/*
	 * Traitement des elements de la queue
	 */
	while ((shortest_distance = lm_queue_neighbor(exit_queue(queue), queue)) == 0)
		;
	return (shortest_distance);
}
int			lm_start_algo(t_sommet **sommet, int ants_number)
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
	find_shortest_path(sommet, &queue);
	
}
