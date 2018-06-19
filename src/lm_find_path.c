/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:46:59 by jabt              #+#    #+#             */
/*   Updated: 2018/06/19 14:38:20 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * bon gaf a ca c'est vraiment un truc rafistole
 */

static void		remplir_mon_truc(t_sommet **sommet)
{
	int		i = 0;
	int		j = 1;

	while (i < HASH_SIZE)
	{
		if (sommet[i])
		{
			if (i == 0)
				sommet[i]->distance = 0;
			else if (i == 1)
				sommet[i]->distance = 2;
			else if (i == 50)
				sommet[i]->distance = 1;
			else if (i == 51)
				sommet[i]->distance = 1;
		}
		i++;
	}	
}

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
	exit(5);
}

int		lm_find_path_core(t_sommet **sommet)
{
	t_sommet	*current;

	remplir_mon_truc(sommet);
	lm_clear_all_queue(sommet);	

//
//
//		dans cette fonction jaimerais bien choper et iterer sur tous les 
//		node voisins de larrive (mes potentiels chemins et trouver leurs chemins)
//

	while ((current = lm_loneliest_node(sommet[1], sommet)) && current)
	{
		lm_find_path(sommet, current);
		printf("node : %s et son chemin %s\n", current->name, current->queue->name);
	}

	exit(5);
	return (1);
}
