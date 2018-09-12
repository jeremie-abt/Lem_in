/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_fourmi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 13:35:16 by jabt              #+#    #+#             */
/*   Updated: 2018/09/12 16:53:00 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			lm_print_last_part(t_sommet **graph, t_sommet *cur,
		int *tab_of_ant, t_sommet **cur_tab)
{
	t_sommet	*next;
	t_sommet	*prev;

	prev = cur->prev;
	next = lm_get_next_sommet_by_flow(graph, cur);
	if (prev != graph[0])
	{
		if (cur->ant)
		{
			ft_printf("{GREEN}L%d-%s{EOC} ", cur->ant, graph[1]->name);
			cur->ant = prev->ant;
			if (!cur->ant)
				*cur_tab = NULL;
		}
		else if (next != graph[1])
			*cur_tab = next;
	}
	else
	{
		ft_printf("{GREEN}L%d-%s{EOC} ", cur->ant, graph[1]->name);
		if (!*tab_of_ant)
			*cur_tab = NULL;
	}
}

/*
** 	INPUT
** 	pointeur directly on the good index to the tab_of_ant tab
*/

static void			lm_print_first_part(t_sommet *cur, int *tab_of_ant)
{
	if (*tab_of_ant)
	{
		cur->ant++;
		ft_printf("L%d-%s ", cur->ant, cur->name);
		(*tab_of_ant)--;
	}
	else
		cur->ant = 0;
}

/*
** 		format of printing : Lnb_fourmi-room
*/

static void			lm_print_and_shift_path(t_sommet **graph,
		t_sommet **cur_tab, int *tab_of_ant, int combientieme)
{
	t_sommet	*next;
	t_sommet	*cur;
	t_sommet	*prev;

	cur = cur_tab[combientieme - 1];
	next = lm_get_next_sommet_by_flow(graph, cur);
	prev = cur->prev;
	lm_print_last_part(graph, cur,
			&tab_of_ant[combientieme - 1], &cur_tab[combientieme - 1]);
	while (prev != graph[0])
	{
		if (prev->ant)
			ft_printf("L%d-%s ", prev->ant, cur->name);
		cur->ant = prev->ant;
		cur = prev;
		prev = prev->prev;
	}
	lm_print_first_part(cur, &tab_of_ant[combientieme - 1]);
}

static int			lm_print_ants(t_sommet **graph, int *tab_of_ants, int size)
{
	t_sommet			**tab;
	t_adj_lst			*lst;
	int					i;

	lst = graph[0]->lst;
	if (!(tab = malloc(sizeof(t_sommet *) * size)))
		return (-1);
	lm_init_save_cur_ant_tab(tab, graph, size);
	lm_send_first_ant_in_path(graph, tab, tab_of_ants, size);
	while (lm_verif_ant_cur_tab(tab, size))
	{
		i = 0;
		while (i < size)
		{
			if (tab[i])
				lm_print_and_shift_path(graph, tab, tab_of_ants, i + 1);
			i++;
		}
		ft_printf("\n");
	}
	free(tab);
	return (1);
}

/*
** 	INPUT
** 	hashtable which represent a graph under those constraints :
** 	the node juste before end of the path i'll use need to have
** 	their distance node all node within a path shall have their
** 	prev node init and all the forward edge of a path need to
** 	have their flow to 0
*/

int					lm_core_print_ants(t_sommet **graph, int ants, int path)
{
	int			*nb_ants_in_path;

	lm_sort_lst_byorder(graph);
	if (lm_sort_begin_byorder(graph) == -1)
		return (-1);
	if (!(nb_ants_in_path = ft_memalloc(sizeof(int) * path)))
		return (-1);
	lm_fill_ants_per_path_tab(graph, path, ants, nb_ants_in_path);
	if (lm_print_ants(graph, nb_ants_in_path, path) == -1)
	{
		free(nb_ants_in_path);
		return (-1);
	}
	free(nb_ants_in_path);
	return (1);
}
