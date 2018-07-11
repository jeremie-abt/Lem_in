/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_hashtable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:05:59 by jabt              #+#    #+#             */
/*   Updated: 2018/07/11 18:00:28 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void		lm_free_extend_graph(t_sommet **extend_graph)
{
	int			i;
	t_sommet	*tmp;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (extend_graph[i])
		{
			printf("ishish\n\n\n");
			tmp = extend_graph[i];
			while (tmp)
			{
				if (tmp->lst)
				{
					lm_free_adj_lst_extend_graph(tmp->lst);
				}
				tmp = tmp->next;
				free(extend_graph[i]);
				extend_graph[i] = tmp;
			}
			extend_graph[i] = NULL;
		}
		i++;
	}
}

