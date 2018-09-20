/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_get_sommet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:07:39 by jabt              #+#    #+#             */
/*   Updated: 2018/09/20 16:17:37 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_get_start_end(t_sommet **graph, char *needle)
{
	if (ft_strequ(graph[0]->name, needle))
		return (graph[0]);
	else if (ft_strequ(graph[1]->name, needle))
		return (graph[1]);
	else
		return (NULL);
}

t_sommet			*lm_get_sommet(t_sommet **graph, char *needle)
{
	int			key;
	t_sommet	*iter;

	key = lm_hash(needle);
	iter = graph[key];
	if (!iter || ft_strequ(needle, graph[0]->name) ||
		ft_strequ(needle, graph[1]->name))
		return (lm_get_start_end(graph, needle));
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
		return (NULL);
	}
	while (lst->flow)
		lst = lst->next;
	return (lm_get_sommet(graph, lst->name));
}
