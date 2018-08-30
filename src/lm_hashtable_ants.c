/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:48:47 by jabt              #+#    #+#             */
/*   Updated: 2018/08/29 16:36:11 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lm_send_first_ant_in_path(t_sommet **graph, t_sommet **tab, 
		int *tab_of_ant, int size)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	int			i;

	i = 0;
	lst = graph[0]->lst;
	while (i < size)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (i == 0)
			cur->ant = 1;
		else
			cur->ant = tab_of_ant[i - 1] + 1;
		printf("L%d-%s ", cur->ant, cur->name);
		lst = lst->next;
		i++;

		tab[i - 1] = lm_get_next_sommet_by_flow(graph, cur);
		if (tab[i - 1] == graph[1])
			tab[i - 1] = cur;
		//tab[i - 1] = cur;
	}
	lm_remove_one_ant(tab_of_ant, size);
	printf("\n");
}
