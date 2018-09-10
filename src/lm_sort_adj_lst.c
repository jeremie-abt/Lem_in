/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_sort_adj_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:39:26 by jabt              #+#    #+#             */
/*   Updated: 2018/09/10 18:56:05 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_swap_lst(t_adj_lst *first, t_adj_lst *second)
{
	t_adj_lst		swap;
	t_adj_lst		*tmp;
	t_adj_lst		*secondtmp;

	tmp = second;
	secondtmp = second->next;
	ft_memcpy(&swap, first, sizeof(t_adj_lst));
	ft_memcpy(first, second, sizeof(t_adj_lst));
	ft_memcpy(second, &swap, sizeof(t_adj_lst));
	first->next = tmp;
	second->next = secondtmp;
}

/*
** 		PROCEDURE'S GOAL
** 		order the lst of the end node by shortest path
** 		meaning that the head of the lst end node is the shortest path
** 		the second node is the second shortest path etc...
*/

void			lm_sort_lst_byorder(t_sommet **graph)
{
	t_adj_lst	*tmp;
	t_sommet	*cur;
	t_sommet	*secondcur;

	tmp = graph[1]->lst;
	while (tmp->next)
	{
		cur = lm_get_sommet(graph, tmp->name);
		secondcur = lm_get_sommet(graph, tmp->next->name);
		if (secondcur->distance == -1)
			tmp = tmp->next;
		else if (cur->distance == -1 && secondcur->distance > 0)
		{
			lm_swap_lst(tmp, tmp->next);
			tmp = graph[1]->lst;
		}
		else if (cur->distance > secondcur->distance)
		{
			lm_swap_lst(tmp, tmp->next);
			tmp = graph[1]->lst;
		}
		else
			tmp = tmp->next;
	}
}

/*
** 		INPUT
** 		hashtable with the end node lst sorted by shortest path
** 		to longest path
*/

int				lm_sort_begin_byorder(t_sommet **graph)
{
	t_adj_lst	*lst;
	t_adj_lst	*new_lst;
	t_sommet	*cur;

	new_lst = NULL;
	lst = graph[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		if (cur->prev)
		{
			while (cur->prev != graph[0])
				cur = cur->prev;
			if (!(lm_new_lst_node_atend(&new_lst, cur->name, 0)))
			{
				lm_free_adj_lst(new_lst);
				return (-1);
			}
		}
		lst = lst->next;
	}
	lst = graph[0]->lst;
	graph[0]->lst = new_lst;
	return (1);
}

/*
** 		OUTPOUT
** 		the begin's node lst sorted by shortest path to longest path
** 		CARE OF
** 		what to do with non used path
*/
