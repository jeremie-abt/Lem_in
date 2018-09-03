/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:29:35 by jabt              #+#    #+#             */
/*   Updated: 2018/09/03 18:45:46 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_adj_lst	*lm_copy_lst(t_sommet *node)
{
	t_adj_lst	*new_lst;
	t_adj_lst	*tmp_lst;
	t_adj_lst	*lst;
	t_sommet	*cur;

	lst = node->lst;
	new_lst = NULL;
	while (lst)
	{
		cur = lm_get_sommet(sommet, lst->name);
		tmp_lst = lm_get_edge(cur->lst, node->name);
		if (!(lm_new_lst_node(&new_lst, lst)))
		{
			// attention a bin free;
			return (NULL);
		}
		lst = lst->next;
	}
	return (new_lst);
}

void			lm_update_prev(t_sommet **resid_graph, t_sommet **graph)
{
	int			i;
	t_sommet	*cur;
	t_sommet	*resid_cur;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (graph[i])
		{
			cur = graph[i];
			resid_cur = resid_graph[i];
			while (cur)
			{
				if (cur->prev)
					resid_cur->prev = lm_get_sommet(resid_graph, cur->prev->name);
				cur = cur->next;
				resid_cur = resid_cur->next;
			}
		}
		i++;
	}
}

t_sommet		**lm_copy_hashtable(t_sommet **graph)
{
	t_sommet	**resid_graph;
	int			i;

	if (!(resid_graph = malloc(sizeof(t_sommet *) * HASH_SIZE)))
		return (NULL);
	ft_bzero(resid_graph, sizeof(t_sommet *) * HASH_SIZE);
	i = 0;
	while (i < HASH_SIZE)
	{
		if (graph[i])// attention je ne copie pas chaque node la
		{
			if (!(resid_graph[i] = lm_copy_node(graph[i])))
				return (NULL);
			if (!(resid_graph[i]->lst = lm_copy_lst(graph[i])))
				return (NULL);
		}
		i++;
	}
	lm_update_prev(resid_graph, graph);
	return (resid_graph);
}

t_sommet		*lm_copy_node(t_sommet *src)
{
	t_sommet	*dst;

	if (!(dst = malloc(sizeof(t_sommet))))
		return (NULL);
	else
		ft_memcpy((void *)dst, (void *)src, sizeof(t_sommet));
	return (dst);
}
