/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:38:38 by jabt              #+#    #+#             */
/*   Updated: 2018/08/22 17:14:04 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
void			lm_init_neighboor_edge(t_sommet **sommet, t_sommet *node)
{
	t_sommet		*cur;
	t_adj_lst		*lst;
	t_adj_lst		*edge;

	lst = node->lst;
	while (lst)
	{
		cur = lm_get_sommet(sommet, lst->name);
		if (!cur->visited)
		{
			if (node == sommet[1])
			{
				lst->flow = 0;
			}
			else if (cur->distance < node->distance)// gerer une condition pour la fin
			{
				printf("first\n");
				printf("node : %s.%d cur : %s.%d\n\n", node->name, node->distance, cur->name, cur->distance);
				lst->flow = 0;
				edge = lm_get_edge(cur->lst, node->name);
				edge->flow = 1;
			}
			else
			{
u				printf("second\n");
				printf("node : %s.%d cur : %s.%d\n\n\n\n", node->name, node->distance, cur->name, cur->distance);
				lst->flow = 1;
				edge = lm_get_edge(cur->lst, node->name);
				edge->flow = 0;
			}
		}
		lst = lst->next;	
	}
	node->visited = 1;
}*/

t_adj_lst		*lm_get_edge(t_adj_lst *lst, char *str)
{
	while (lst)
	{
		if (ft_strequ(lst->name, str))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
