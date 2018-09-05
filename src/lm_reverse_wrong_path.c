/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_reverse_wrong_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:20:54 by jabt              #+#    #+#             */
/*   Updated: 2018/09/05 13:46:55 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			lm_reverse_first_part(t_sommet **resid_graph, t_sommet *node)
{
	t_sommet	*tmp;

	node = node->prev;
	while (node != resid_graph[0])
	{
		node->visited = 0;
		tmp = node->prev;
		node->prev = NULL;
		node = tmp;
	}
}

//void			lm_block_shortcut(t_sommet **resid_graph, t_som)

/*
 *	INPUT
 *	resid_graph sous forme de hashtableh
 *	et le premier node visited == 2 que mon bfs a trouve juste avant
 *	dans le vraie graph
 */

// attention enfaite ya deux cas :
// 		premier cas c'est une shortcut et elle n'est pas interessante
// 		deuxieme cas c'est pas une shortcut juste ya pas de path donc il faut blocker
// 		le path
void			lm_reverse_wrong_path(t_sommet **resid_graph, t_sommet **graph,
		t_sommet *node)
{
	t_sommet	*resid_node;

	resid_node = lm_get_sommet(resid_graph, node->name);

	printf("voici le node : %s\n", node->name);
	exit(4);
}
