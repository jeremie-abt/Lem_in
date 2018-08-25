/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_fourmi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 13:35:16 by jabt              #+#    #+#             */
/*   Updated: 2018/08/25 18:46:34 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
static void		lm_print_one_turn(t_sommet **graph)
{
	
}

static void		lm_shift_ant(t_sommet **graph)
{
	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = graph[0]->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph);
		if (cur->ant > 0)
			cur->ant = 0;
		lst = lst->next;
	}
}
*/

/*
 *
 *		ATTENTION CALCUL TRES HASARDEUX EN DESSOUS ET SURTOUT FAUX
 *		IL EST CLAIREMENT FAUXX !!!
 *
 */

static void			lm_fill_ants_per_path_tab(t_sommet **graph, int *tab, int path)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	int			i;

	lst = graph[1]->lst;
	i = 0;
	while (i < path && lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		tab[i] = cur->ant;
		cur->ant = 0;
		i++;
		lst = lst->next;
	}
}



static int		lm_disperse_ants(t_sommet **graph, int path)
{
	t_adj_lst		*lst;
	t_sommet		*cur;
	int				*ants_per_path;

	if (!(ants_per_path = malloc(sizeof(int) * path)))
		return (0);
	lm_fill_ants_per_path_tab(graph, ants_per_path, path);
	lst = graph[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
	}
	return (1);
}

void			lm_print_ants(t_sommet **graph, int ants)
{
	int			i;
	int			nb_ants_in_path;
	int			path;
	t_sommet	*cur;
	t_sommet	*second_cur;
	t_adj_lst	*lst;

	i = 1;
	lm_sort_lst_byorder(graph);
	// faut que je sorte le debut par ordre aussi
	lst = graph[1]->lst;
	while (lst->next && ants > 0)
	{
		cur = lm_get_sommet(graph, lst->name);
		second_cur = lm_get_sommet(graph, lst->next->name);
		cur->ant = (cur->distance + ants) - (second_cur->distance + 1);
		second_cur->ant = ants - cur->ant;
		nb_ants_in_path += cur->ant;
		ants -= cur->ant;	
		lst = lst->next;
	}
	path = 2;
	// bon gerer ca aussi hein plutot que de le remplir a la main	
	
	if (!lm_sort_begin_byorder(graph))
	{
		//verif si ya pas des trucs a free ...
		return ;
	}
	print_adj_lst(graph[0], graph[0]->lst);
	exit(5);
	lm_disperse_ants(graph, path);
	
	///print_ant_path(graph);
}
