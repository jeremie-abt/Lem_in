/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_is_worth_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:19:40 by jabt              #+#    #+#             */
/*   Updated: 2018/09/04 14:30:02 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 	PROCEDURE
 * 	see if reversing one edge is worth or not
 */

int		lm_is_worth_path_flow(void) // bon evidemment il faudra faire cette fonction
{
	return (1);	
}

/*
 * 		INPUT
 * 		hashtable avec le node du path qui vient juste d'etre ajouter par mon bfs
 */

int				lm_is_worth_path_bfs(t_sommet **graph, t_sommet *node, int *ants,
		int path)
{
	static t_sommet		*cur;
	
	if (node == graph[0])	
		return (1);
	if (!cur)
	{
		cur = node;
		if (*ants > 0)
			return (1);
	}
	else
	{
		(*ants) -= (node->distance - cur->distance) * (path - 1);
		if (*ants >= path)
		{
			cur = node;
			*ants -= path;
			return (1);
		}
		else
		{
			lm_cancel_chosen_path(graph, node);
			return (0);//procedure pour annuler ce chemin
		}
	}
	return (0);
}

/*
 * 		OUTPOUT
 * 		si le path est worth return 1
 * 		sinon return 0 et enlever le path choisis car il n'est pas
 * 		rentalbe
 */


