/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_algo_dfs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
//<<<<<<< HEAD:src/lm_algo_dfs.c
/*   Created: 2018/08/23 14:24:47 by jabt              #+#    #+#             */
/*   Updated: 2018/08/23 17:00:48 by jabt             ###   ########.fr       */
//=======
/*   Created: 2018/06/05 11:05:59 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 14:27:34 by galemair         ###   ########.fr       */
//>>>>>>> gdev1.1:src/lm_free_hashtable.c
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
t_sommet		*lm_get_next_node_dfs(t_sommet **sommet, t_sommet *node)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	t_sommet	*tmp;

	while (node)
	{
		lst = node->lst;
		while (lst)
		{
			if (lst->flow == 1)
			{
				cur = lm_get_sommet(sommet, lst->name);
				if (!cur->visited)
				{
					cur->visited = 1;
					cur->prev = node;
					return (cur);
				}
			}
			lst = lst->next;
		}
		tmp = node;
		node = node->prev;
		tmp->prev = NULL;
	}
	return (NULL);
}
*/
