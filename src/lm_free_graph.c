/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:43:57 by jabt              #+#    #+#             */
/*   Updated: 2018/09/24 11:20:23 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_free_hashtable(t_sommet **hashtab)
{
	int			i;
	t_sommet	*tmp;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtab[i])
		{
			tmp = hashtab[i];
			while (tmp)
			{
				if (tmp->lst)
					lm_free_adj_lst(tmp->lst);
				if (tmp->name)
				{
					free(tmp->name);
					tmp->name = NULL;
				}
				tmp = tmp->next;
				free(hashtab[i]);
				hashtab[i] = tmp;
			}
			hashtab[i] = NULL;
		}
		i++;
	}
}

void			lm_free_resid_graph(t_sommet **resid_graph)
{
	int			i;
	t_sommet	*tmp;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (resid_graph[i])
		{
			tmp = resid_graph[i];
			while (tmp)
			{
				if (tmp->lst)
					lm_free_adj_resid_graph_lst(tmp->lst);
				tmp = tmp->next;
				free(resid_graph[i]);
				resid_graph[i] = tmp;
			}
			resid_graph[i] = NULL;
		}
		i++;
	}
}

void			lm_free_resnode(t_sommet *node)
{
	t_sommet	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}
