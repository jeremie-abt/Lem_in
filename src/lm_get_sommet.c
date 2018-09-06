/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get_sommet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:07:39 by jabt              #+#    #+#             */
/*   Updated: 2018/09/06 11:44:59 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_get_start_end(t_sommet **sommet, char *needle)
{
	if (ft_strequ(sommet[0]->name, needle))
		return (sommet[0]);
	else if (ft_strequ(sommet[1]->name, needle))
		return (sommet[1]);
	else
		return (NULL);
}

t_sommet			*lm_get_sommet(t_sommet **sommet, char *needle)
{
	int			key;
	t_sommet	*iter;

	key = lm_hash(needle);
	iter = sommet[key];
	if (!iter || ft_strequ(needle, sommet[0]->name) || ft_strequ(needle, sommet[1]->name))
		return (lm_get_start_end(sommet, needle));
	while (!ft_strequ(iter->name, needle))
		iter = iter->next;
	return (iter);
}



t_sommet			*lm_get_next_sommet_by_flow(t_sommet **graph, t_sommet *cur)
{
	t_adj_lst	*lst;

	lst = cur->lst;
	if (graph[1] == cur)
	{
		printf("iiici \n");
		exit(5);
	}
	while (lst->flow)
		lst = lst->next;
	return (lm_get_sommet(graph, lst->name));
}


/*
t_sommet			*lm_get_next_node(t_sommet **graph, t_sommet *node)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	t_sommet	*tmp;

	cur = NULL;
	lst = node->lst;
	while (lst)
	{
		tmp = lm_get_sommet(graph, lst->name);
		if (lst->flow == 1 && !tmp->visited)
		{
			cur = lm_get_sommet(graph, lst->name);
			return (cur);
		}
		lst = lst->next;
	}
	return (cur);
}
*/

t_sommet			*lm_get_last_node_of_path(t_sommet **graph, t_sommet *node)
{
	t_adj_lst	*lst;
	t_sommet	*tmp;

	tmp = lm_get_next_sommet_by_flow(graph, node);
	while (tmp != graph[1])
	{
		node = tmp;
		tmp = lm_get_next_sommet_by_flow(graph, node);
	}
	return (node); // attention a bien test
}
