/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_augmenting_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:48:38 by jabt              #+#    #+#             */
/*   Updated: 2018/08/22 17:14:04 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 	the goal of augmenting path is to find a blocking flow
 * 	meaning for example an edge wich cut two or more path
 * 	so if we don't take this edge maybe several more paths will
 * 	appear and this point is exactly what the augmenting paths are doing
 */

/*
** 		in this file i'm only working on hashtable->capacity
*/
/*
static void		lm_update_path(t_sommet *start, t_sommet *node)
{
	node->capacity = -1;
	while (node != start)
	{
		node->capacity = -1;
		node = node->prev;
	}
}

static void		lm_update_flow(t_sommet **sommet)
{
	t_sommet	*cur;
	t_adj_lst	*lst;
	int			i;

	lst = sommet[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(sommet, lst->name);
		lm_update_path(sommet[0], cur);
		lst = lst->next;
	}
	i = 2;
	while (i < HASH_SIZE)
	{
		if (sommet[i] && sommet[i]->capacity == 0)
			sommet[i]->capacity = 1;
		i++;
	}
} 
int			lm_augmenting_path(t_sommet **sommet)
{
	t_control_queue		control;
	t_sommet			*cur;
	t_adj_lst			*adj_lst;

//	lm_update_flow(sommet);
	adj_lst = sommet[0]->lst;
	ft_bzero(&control, sizeof(t_control_queue));
	while (adj_lst)
	{

	}
	while (control.tail || control.head)
	{
		cur = lm_pop_queue(&control);
	}
	return (1);
}*/
