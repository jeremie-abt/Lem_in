/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_adj_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:40:21 by jabt              #+#    #+#             */
/*   Updated: 2018/09/20 16:19:31 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		lm_add_neighbor(t_sommet *first_sommet,
	t_sommet *second_sommet, char *first_neighbor, char *second_neighbor)
{
	t_adj_lst		*tmp;

	tmp = first_sommet->lst;
	if (!(first_sommet->lst = malloc(sizeof(t_adj_lst))))
		return (-2);
	first_sommet->lst->next = tmp;
	first_sommet->lst->name = first_neighbor;
	tmp = second_sommet->lst;
	if (!(second_sommet->lst = malloc(sizeof(t_adj_lst))))
	{
		lm_free_adj_lst(first_sommet->lst);
		return (-2);
	}
	second_sommet->lst->next = tmp;
	second_sommet->lst->name = second_neighbor;
	first_sommet->lst->flow = 1;
	second_sommet->lst->flow = 1;
	return (1);
}

int				lm_add_tube(t_sommet **graph, char *pattern)
{
	t_sommet	*first_sommet;
	t_sommet	*second_sommet;
	char		*first;

	first = NULL;
	if (!(graph[1]) || !(graph[0]))
		return (-1);
	if (!(first = ft_strsub(pattern, 0,
		(ft_strchr(pattern, '-') - pattern))))
	{
		free(first);
		return (-2);
	}
	if (!(first_sommet = lm_get_sommet(graph, first)) ||
			!(second_sommet = lm_get_sommet(graph, (ft_strchr(pattern, '-') + 1))))
	{
		free(first);
		return (-1);
	}
	if (lm_add_neighbor(first_sommet, second_sommet, second_sommet->name, first_sommet->name) == -2)
	{
		free(first);
		return (-2);
	}
	free(first);
	return (1);
}

int				lm_new_lst_node(t_adj_lst **head, t_adj_lst *src)
{
	t_adj_lst	*tmp;

	tmp = *head;
	if (!(*head = malloc(sizeof(t_adj_lst))))
		return (0);
	(*head)->name = src->name;
	(*head)->flow = src->flow;
	(*head)->next = tmp;
	return (1);
}

int				lm_new_lst_node_atend(t_adj_lst **lst, char *name, int flow)
{
	t_adj_lst	*tmp;
	t_adj_lst	*new_lst;

	if (!(new_lst = malloc(sizeof(t_adj_lst))))
		return (0);
	tmp = *lst;
	if (!tmp)
		*lst = new_lst;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst;
	}
	new_lst->name = name;
	new_lst->flow = flow;
	new_lst->next = NULL;
	return (1);
}
