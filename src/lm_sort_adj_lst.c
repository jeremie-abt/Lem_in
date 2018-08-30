/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_sort_adj_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:39:26 by jabt              #+#    #+#             */
/*   Updated: 2018/08/29 16:35:36 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_swap_lst(t_adj_lst *first, t_adj_lst *second)
{
	printf("ya bien un swap\n");
	exit(4);
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

void			lm_sort_lst_byorder(t_sommet **sommet)
{
	t_adj_lst	*tmp;
	t_adj_lst	*secondtmp;
	t_sommet	*cur;
	t_sommet	*secondcur;

	tmp = sommet[1]->lst;
	while (tmp->next)
	{
		cur = lm_get_sommet(sommet, tmp->name);
		secondcur = lm_get_sommet(sommet, tmp->next->name);
		if (cur->distance > secondcur->distance)
		{
			lm_swap_lst(tmp, tmp->next);
			tmp = sommet[1]->lst;
		}
		else
			tmp = tmp->next;
	}
}

int				lm_sort_begin_byorder(t_sommet **sommet)
{
	t_adj_lst	*lst;
	t_adj_lst	*new_lst;
	t_sommet	*cur;

	new_lst = NULL;
	lst = sommet[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(sommet, lst->name);
		if (cur->prev)
		{
			while (cur->prev != sommet[0])
				cur = cur->prev;
			if (!(lm_new_lst_node_atend(&new_lst, cur->name, 0)))
			{
				// bien free le new_lst
				return (0);
			}
		}
		lst = lst->next;
	}
	lst = sommet[0]->lst;
	sommet[0]->lst = new_lst;
	return (1);
}
