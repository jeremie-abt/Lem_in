/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:29:35 by jabt              #+#    #+#             */
/*   Updated: 2018/09/20 14:54:03 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	RETURN
**	toute la liste a partir du node copie
**	null si pb
*/

static t_adj_lst		*lm_copy_lst(t_sommet *node)
{
	t_adj_lst	*new_lst;
	t_adj_lst	*lst;

	lst = node->lst;
	new_lst = NULL;
	while (lst)
	{
		if (!(lm_new_lst_node(&new_lst, lst)))
		{
			lm_free_adj_lst(new_lst);
			exit (0);
		}
		lst = lst->next;
	}
	return (new_lst);
}

void					lm_update_prev(t_sommet **resid_graph, t_sommet **graph)
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
					resid_cur->prev = lm_get_sommet(resid_graph,
							cur->prev->name);
				cur = cur->next;
				resid_cur = resid_cur->next;
			}
		}
		i++;
	}
}

t_sommet				**lm_copy_hashtable(t_sommet **graph)
{
	t_sommet	**resid_graph;
	int			i;

	if (!(resid_graph = malloc(sizeof(t_sommet *) * HASH_SIZE)))
		return (NULL);
	ft_bzero(resid_graph, sizeof(t_sommet *) * HASH_SIZE);
	i = 0;
	while (i < HASH_SIZE)
	{
		if (graph[i])
		{
			if (!(resid_graph[i] = lm_copy_node(graph, graph[i])))
				return (NULL);
		}
		i++;
	}
	lm_update_prev(resid_graph, graph);
	return (resid_graph);
}

/*
** 	recursively copy all t_sommet *lst and duplicate all the lst var
*/

t_sommet				*lm_copy_node(t_sommet **graph, t_sommet *src)
{
	t_sommet	*resid_node;

	if (src)
	{
		if (!(resid_node = malloc(sizeof(t_sommet))))
			return (NULL);
		else
			ft_memcpy((void *)resid_node, (void *)src, sizeof(t_sommet));
		resid_node->lst = lm_copy_lst(src);
		if (src->next)
		{
			resid_node->next = lm_copy_node(graph, src->next);
			return (resid_node);
		}	
	}
	else
		return (NULL);
	return (resid_node);
}
