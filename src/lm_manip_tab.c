/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:01 by jabt              #+#    #+#             */
/*   Updated: 2018/08/29 16:10:14 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_fill_ants_per_path_tab(t_sommet **graph, int path, int ants,
		int *tab_of_ants)
{
	t_sommet	*cur;
	t_sommet	*sec_cur;
	t_adj_lst	*lst;
	int			i;
	int			j;

	lst = graph[1]->lst;
	cur = lm_get_sommet(graph, lst->name);
	lst = lst->next;
	if (path > 1)
		sec_cur = lm_get_sommet(graph, lst->name);
	j = 0;
	while (ants >= 1)
	{
		i = 0;
		while (i <= j && ants >= 1)
		{
			tab_of_ants[i]++;
			ants--;
			if ((sec_cur->distance - tab_of_ants[0]) < cur->distance && j < path - 1)
			{
				j++;
				if (j < path - 1)
				{
					lst = lst->next;
					sec_cur = lm_get_sommet(graph, lst->name);
				}
			}
			i++;
		}
	}
}

void			lm_init_save_cur_ant_tab(t_sommet **tab, t_sommet **graph, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = graph[0];//lm_get_sommet(graph, lst->name);
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
	int		i;

	i = 0;
	while (i < size)
	{
		if (!cur_tab[i])
			return (0);
		i++;
	}
	return (1);
}
