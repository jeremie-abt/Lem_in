/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_fill_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:18:33 by jabt              #+#    #+#             */
/*   Updated: 2018/09/12 11:47:23 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_fill_distance_flow(t_sommet **graph)
{
	t_adj_lst		*lst;
	t_sommet		*cur;
	int				distance;

	lst = graph[0]->lst;
	while (lst)
	{
		if (lst->flow == 0)
		{
			distance = 1;
			cur = lm_get_sommet(graph, lst->name);
			cur->distance = 1;
			while ((cur = lm_get_next_sommet_by_flow(graph, cur)))
			{
				distance++;
				if (cur == graph[1])
					break ;
				else
					cur->distance = distance;
			}
		}
		lst = lst->next;
	}
}
