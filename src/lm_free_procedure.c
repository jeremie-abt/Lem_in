/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_procedure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:54:06 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 17:09:28 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lm_free_adj_lst(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		free(adj_lst->name);
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}

void		lm_free_adj_lst_resid_graph(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		printf("voici le next : %p\n", adj_lst->next);
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}

void		lm_free_hashtable(t_sommet **hashtab)
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

/*
 * 		INPUT
 * 		struct t_control_queue which must not be dynamically allocated
 * 		t_control_queue.head point on a chained list which must be free
 * 		but the variable inside this head must not be freed
 */

void		lm_free_queue(t_control_queue *control)
{
	t_queue		*cur;
	t_queue		*tmp;

	cur = control->head;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}
