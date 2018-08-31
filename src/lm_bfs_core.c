/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_bfs_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:32:23 by jabt              #+#    #+#             */
/*   Updated: 2018/08/31 10:51:50 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 		but : valider un path -> mettre un visited = 2 sur tous les nodes du path
 * 		input : graph de flow et un node qui doit etre le dernier relie
 * 		a un prev
 * 		on remonte tous le path et on met des visited = 2 sur tous les node
 * 		en commencent par le previous de node
 */




static int		lm_bfs_valid_path(t_sommet **graph, t_sommet * node)
{
	assert(node->prev != NULL);
	assert(node == graph[1]);

	t_sommet	*cur;

	cur = node->prev;
	node->prev = NULL;
	if (cur == graph[0])
		return (2);
	while (cur != graph[0])
	{
		cur->visited = 2;
		cur = cur->prev;
	}
	return (1);
}

/*
 * 		OUTPOUT
 * 		tous les nodes de mon path on ete mis a visited = 2 sauf le fin
 * 		et le fin->prev a ete remis a null
 * 		RETURN
 * 		return 1 : ok
 * 		return 2 : connexion direct between start and end donc un seul path
 */


/*			---------------------------			*/
/*			---------------------------			*/
/*			---------------------------			*/

/*
 * 		INPUT
 * 		procedure pour ajouter tous les voisins bfs
 * 		Je recois un graph de flow et un node dans ce graph
 * 		je veux ajouter tous les neighboor qui ne sont pas visited
 * 		le node de debut doit etre visited
 */

static int		lm_add_neighboor(t_sommet **graph, t_sommet *node,
		t_control_queue *control)
{
	assert(graph[0]->visited > 0);

	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (cur->visited == 0)
		{
			if (!lm_add_elem_queue(control, cur))
				return (-1);
			cur->visited++;
			cur->prev = node;
		}
		lst = lst->next;
	}
	return (1);
}


/*
 * 		INPUT
 *		Je recois un graph de flow sous forme de hashtable
 *		je ne peut toucher que au node visited->0
 *		la valeur visited des nodes debut et fin est egale a 0
 */


int		lm_find_one_path_with_bfs(t_sommet **sommet)
{
	t_control_queue		control;
	t_sommet			*cur;

	sommet[0]->visited = 1;
	ft_bzero(&control, sizeof(t_control_queue));
	if (!lm_add_elem_queue(&control, sommet[0]))
		return (-1);
	while (control.head || control.tail)
	{
		cur = lm_pop_queue(&control);
		if (cur == sommet[1])
			return (lm_bfs_valid_path(sommet, cur));
		else
			if (!lm_add_neighboor(sommet, cur, &control))
			{
				lm_free_queue(&control);
				return (-1);
			}
	}
	return (-1); // verifier ca
}

/*
 * 		OUTPOUT
 *		return -1 = print ERROR et quitter proprement
 *		return 0 = aucun path trouve
 *		return 1 = 1 path trouve
 *		return 2 -> connexion (tube) entre salle start et end trouve
 *		donc go direct envoyer toutes mes fourmis
 */
