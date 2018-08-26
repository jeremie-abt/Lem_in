/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:01 by jabt              #+#    #+#             */
/*   Updated: 2018/08/26 17:43:38 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*lm_fill_ants_per_path_tab(t_sommet **graph, int path)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	int			i;
	int			*new_tab;

	if (!(new_tab = malloc(sizeof(int) * path)))
		return (0);
	lst = graph[1]->lst;
	i = 0;
	while (i < path && lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		new_tab[i] = cur->ant;
		cur->ant = 0;
		i++;
		lst = lst->next;
	}
	return (new_tab);
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
