/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_transform_flowpb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:21:17 by jabt              #+#    #+#             */
/*   Updated: 2018/07/11 17:30:59 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		lm_copy_start_end(t_sommet **sommet, t_sommet **extend_graph)
{
	if (!(extend_graph[0] = lm_copy_node(sommet[0])))
		return (-1);
	if (!(extend_graph[1] = lm_copy_node(sommet[1])))
	{
		free(extend_graph[0]);
		return (-1);
	}
	if (!(extend_graph[0]->lst = lm_copy_lst(sommet[0]->lst)))
	{
		free(extend_graph[0]);
		free(extend_graph[1]);
		return (-1);
	}
	if (!(extend_graph[1]->lst - lm_copy_lst(sommet[1]->lst)))
	{
		lm_free_adj_lst(extend_graph[0]->lst);
		free(extend_graph[0]);
		free(extend_graph[1]);
		return (1);
	}
	return (1);
}

t_sommet		**lm_extend_graph(t_sommet **sommet)
{
	int			i;
	t_sommet	**extend_graph;

	i = 2;
	if (!(extend_graph = malloc(sizeof(t_sommet *) * HASH_SIZE)))
		return (NULL);

	ft_bzero(extend_graph, sizeof(t_sommet *) * HASH_SIZE);

	while (i < HASH_SIZE)
	{
		if (sommet[i])// attention au debut et fin je les geres pas pour l'instant
		{
			if (!(extend_graph[i] = lm_double_node(sommet, extend_graph[i], sommet[i])))
			{
//				lm_free_hashtable(extend_graph + 2);// FFRRREEEEEEEEE
				free(extend_graph);
				return (NULL);
			}
		}
		i++;
	}
	lm_copy_start_end(sommet, extend_graph);
	return (extend_graph);//really ???
}
