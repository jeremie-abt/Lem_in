/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_adj_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:40:21 by jabt              #+#    #+#             */
/*   Updated: 2018/08/23 17:53:41 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
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
*/
static int		lm_add_neighbor(t_sommet *first_sommet, t_sommet *second_sommet, 
		char *first_neighbor, char *second_neighbor)
{
	t_adj_lst		*tmp;

	tmp = first_sommet->lst;
	if (!(first_sommet->lst = malloc(sizeof(t_adj_lst))))
		return (-1);
	first_sommet->lst->next = tmp;
	first_sommet->lst->name = first_neighbor;


	tmp = second_sommet->lst;
	if (!(second_sommet->lst = malloc(sizeof(t_adj_lst))))
	{
		lm_free_adj_lst(first_sommet->lst); // atention fonction pour free une lst
		return (-1);
	}
	second_sommet->lst->next = tmp;
	second_sommet->lst->name = second_neighbor;
	first_sommet->lst->flow = 1;
	second_sommet->lst->flow = 1;
	return (1);
}

int				lm_add_tube(t_sommet **sommet, char *pattern)
{
	char		*second;
	char		*first;
	t_sommet	*first_sommet;
	t_sommet	*second_sommet;

	if (lm_verif_tube(pattern) == -1)
		return (-1);
	second = ft_strchr(pattern, '-') + 1;
	if (!(first = ft_strsub(pattern, 0, (second - pattern) - 1)))
	{
		//	free(second);
		return (-1);
	}
	if (!(second = ft_strdup(second)))
	{
		free(first);
		return (-1);
	}
	if (!(first_sommet = lm_get_sommet(sommet, first)) ||
			!(second_sommet = lm_get_sommet(sommet, second)))
	{
		free(second);
		free(first);
		return (-1);
	}
	lm_add_neighbor(first_sommet, second_sommet, second, first);
	//free(first);
	return (1);
}

int				lm_new_lst_node(t_adj_lst **lst, char *name, int flow)
{
	t_adj_lst	*tmp;

	tmp = *lst;
	if (!(*lst = malloc(sizeof(t_adj_lst))))
		return (0);
	(*lst)->name = name;
	(*lst)->flow = flow;
	(*lst)->next = tmp;
	return (1);
}

	
/*
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

*/
