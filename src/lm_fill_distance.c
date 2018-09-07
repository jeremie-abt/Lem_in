/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_fill_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:18:33 by jabt              #+#    #+#             */
/*   Updated: 2018/09/07 16:19:29 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_fill_distance_flow(t_sommet **graph)
{
	t_adj_lst		*lst;
	t_adj_lst		*tmp_lst;
	t_sommet		*cur;
	int				distance;

	lst = graph[0]->lst;
	while (lst)
	{
		if (lst->flow == 0)
		{
			distance = 1; 
			cur = lm_get_sommet(graph, lst->name);
			cur->distance = distance;
			while (cur != graph[1])
			{
				distance++;
				tmp_lst = cur->lst;
				while (tmp_lst->flow != 0)
					tmp_lst = tmp_lst->next;
				cur = lm_get_sommet(graph, tmp_lst->name);
				cur->distance = distance;
			}
			lst->flow = distance;//c'est bon ?
		}
		lst = lst->next;
	}
}

