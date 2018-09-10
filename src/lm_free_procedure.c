/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_procedure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:54:06 by jabt              #+#    #+#             */
/*   Updated: 2018/09/10 13:53:47 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_free_adj_resid_graph_lst(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}

void			lm_free_adj_lst(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}

void			lm_free_adj_lst_resid_graph(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}

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
				free(tmp->name);
				if (tmp->lst)
				{
					lm_free_adj_lst(tmp->lst);
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
