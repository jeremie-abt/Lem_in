/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manage_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:02:54 by galemair          #+#    #+#             */
/*   Updated: 2018/06/19 13:43:18 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lm_clear_all_queue(t_sommet **sommet)
{
	int		i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (sommet[i])
			sommet[i]->queue = NULL;
		i++;
	}
}

void		lm_sort_ins_in_queue(t_sommet **queue, t_sommet *to_add)
{
	t_sommet *tmp;

	if (!*queue)
		*queue = to_add;
	else
	{
		tmp = *queue;
		*queue = to_add;
		(*queue)->queue = tmp;
	}
}

t_sommet	*pop_queue(t_sommet **queue)
{
	t_sommet *tmp;
	t_sommet *tmp2;

	tmp = *queue;
	if (!tmp->queue)
	{
		*queue = NULL;
		return (NULL);
	}
	while ((tmp->queue)->queue)
		tmp = tmp->queue;
	tmp2 = tmp->queue;
	tmp->queue = NULL;
	return (tmp2);
}
