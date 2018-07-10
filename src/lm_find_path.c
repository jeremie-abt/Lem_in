/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:46:59 by jabt              #+#    #+#             */
/*   Updated: 2018/07/10 13:21:27 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_find_neighbor(t_sommet **sommet, t_adj_lst *adj_lst, int distance)
{
	int		key;
	int		nb;

	nb = 0;
	while (adj_lst)
	{
		key = lm_hash(adj_lst->name);
		if (sommet[key]->distance == distance)
			nb++;
		adj_lst = adj_lst->next;
	}
	return (nb);
}
/*
 * 			faut refaire ca !!
 *
 *
void		lm_find_path(t_sommet **sommet, t_sommet *node)
{
	t_sommet	*child;

	node->visited = 1;
	child = lm_loneliest_node(node, sommet);
	if (child == sommet[0])
	{
		if (node != sommet[1])
			node->queue = child;
		return ;
	}
	else
		lm_find_path(sommet, child);
	if (node != sommet[1])
		node->queue = child;
}

int		lm_find_path_core(t_sommet **sommet)
{
	t_sommet	*current;

	lm_clear_all_queue(sommet);	
//
//		dans cette fonction jaimerais bien choper et iterer sur tous les 
//		node voisins de larrive (mes potentiels chemins et trouver leurs chemins)
//

	while ((current = lm_loneliest_node(sommet[1], sommet)) && current)
	{
		//("voici le current : %s\n", current->name);
		lm_find_path(sommet, current);
		print_path(sommet, current);
	}

	exit(5);
	return (1);
}*/
