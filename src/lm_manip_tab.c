/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:01 by jabt              #+#    #+#             */
/*   Updated: 2018/09/11 10:18:44 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 	INPUT
** 	graph[1]->lst is sorted in order of shortest path
** 	meaning graph[0]->lst = shortest path, graph[1]->lst->next
** 	equal the second shortest path etc ...
*/

void			lm_fill_ants_per_path_tab(t_sommet **graph, int path, int ants,
		int *tab_of_ants)
{
	t_sommet	*cur;
	t_sommet	*sec_cur;
	t_adj_lst	*lst;
	int			i;
	int			j;

	lst = graph[1]->lst->next;
	cur = lm_get_sommet(graph, lst->name);
	sec_cur = lm_get_sommet(graph, lst->name);
	j = 0;
	while (ants >= 1)
	{
		i = -1;
		while (++i <= j && ants-- >= 1)
		{
			tab_of_ants[i]++;
			if (j < path - 1 &&
					(sec_cur->distance - tab_of_ants[0]) < cur->distance)
				if (++j < path - 1)
				{
					lst = lst->next;
					sec_cur = lm_get_sommet(graph, lst->name);
				}
		}
	}
}

void			lm_init_save_cur_ant_tab(t_sommet **tab,
		t_sommet **graph, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = graph[0];
		i++;
	}
}

void			lm_remove_one_ant(int *tab_of_ant, int size)
{
	int		i;

	i = 0;
	while (i < size && tab_of_ant[i] > 0)
	{
		tab_of_ant[i]--;
		i++;
	}
}

int				lm_verif_ant_cur_tab(t_sommet **cur_tab, int size)
{
	int		size_iter;
	int		test;

	test = 0;
	size_iter = size - 1;
	while (size_iter >= 0)
	{
		if (!cur_tab[size_iter])
			test++;
		size_iter--;
	}
	if (size == test)
		return (0);
	return (1);
}
