/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print_fourmi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 13:35:16 by jabt              #+#    #+#             */
/*   Updated: 2018/08/26 19:09:47 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*

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

*/

/*
 *
 *		ATTENTION CALCUL TRES HASARDEUX EN DESSOUS ET SURTOUT FAUX
 *		IL EST CLAIREMENT FAUXX !!!
 *
 */

/*
 * 		format of printing : Lnb_fourmi-room
 */

static void			lm_print_and_shift_path(t_sommet **graph, t_sommet **cur_tab,
		int *tab_of_ant, int combientieme)
{
	t_sommet	*next;
	t_sommet	*cur;

	cur = cur_tab[combientieme - 1];
	next = lm_get_next_sommet_by_flow(graph, cur);
	
	if (next != graph[1])
		cur_tab[combientieme - 1] = next;

// bon faire proprement cette fonction de merde




	// fin de chemin on doit transpose le ant au next et le cur_tab doit
	// devenir next sauf si il est egale au node de fin


	// puis milieux



	// puis debut de chemin
	
}

static int			lm_display_one_turn(t_sommet **graph, int *tab_of_ants, int size)
{
	static t_sommet		**tab;
	t_adj_lst			*lst;
	int					i;

	lst = graph[0]->lst;
	if (!tab)
	{
		if (!(tab = malloc(sizeof(t_sommet *) * size)))
			return (0);
		lm_init_save_cur_ant_tab(tab, graph, size);
	}
	//	fonction pour initier les premieres fourmis de chaques path

	lm_send_first_ant_in_path(graph, tab, tab_of_ants, size); // attention a decrement mon tab	
	int stop = 0;
	while (stop++ < 6/**tab_of_ants > 0*/)
	{
		i = 0;
		while (i < size)//ants existe || ants in path)
		{
			lm_print_and_shift_path(graph, tab, tab_of_ants, i + 1);
			i++;
		}
		printf("\n");
	}

	exit(4);
	return (1);

}

void			lm_print_ants(t_sommet **graph, int ants)
{
	//	int			i;
	//int			path;
	int			*nb_ants_in_path;
	t_sommet	*cur;
	t_sommet	*second_cur;
	t_adj_lst	*lst;

	lm_sort_lst_byorder(graph);
	if (!lm_sort_begin_byorder(graph) || !nb_ants_in_path)
	{
		//verif si ya pas des trucs a free ...
		return ;
	}

	lst = graph[1]->lst;
	/*while (lst->next && ants > 0) // attention ici a trouver un vraie calcul
	  {
	  cur = lm_get_sommet(graph, lst->name);
	  second_cur = lm_get_sommet(graph, lst->next->name);
	  cur->ant = (cur->distance + ants) - (second_cur->distance + 1);
	  second_cur->ant = ants - cur->ant;
	  nb_ants_in_path += cur->ant;
	  ants -= cur->ant;	
	  lst = lst->next;
	  }*/
	cur = lm_get_sommet(graph, graph[1]->lst->name);
	cur->ant = ants;

	//		GERER LA VARIABLE PATH !!!!!!!!

	nb_ants_in_path = lm_fill_ants_per_path_tab(graph, 2);
	nb_ants_in_path[0] = 3;
	nb_ants_in_path[1] = 3;
	lm_display_one_turn(graph, nb_ants_in_path, 2);
	//	if (!lm_display_one_turn())
	//	{
	//		//free
	//		return ;
	//	}


	///print_ant_path(graph);
}
