/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:46:59 by jabt              #+#    #+#             */
/*   Updated: 2018/06/15 14:04:01 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_find_neighbor(t_sommet **sommet, t_adj_lst *adj_lst, int distance)
{
	int		key;
	int		nb;

	nb = 0;
	while (adj_list)
	{
		key = lm_hash(adj_list->name);
		if (sommet[key]->name == distance)
			nb++;
		adj_lst = adj_lst->next;
	}
	return (nb);
}

int		lm_find_path_node(t_sommet *sommet)
{
	return (1);
}

int		lm_find_path_core(t_sommet **sommet)
{
	t_sommet	*queue;
	t_sommet	*tmp;
	t_adj_list	*adj_list;
	int			nb;

	queue = sommet[0];
	adj_list = sommet[0]->lst;
	while (adj_lst)
	{
		nb = 	
		adj_lst = adj_lst->next;
	}
	add_in_queue(&queue, );	
	return (1);
}
