/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manage_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:02:54 by galemair          #+#    #+#             */
/*   Updated: 2018/06/15 16:10:56 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_in_queue(t_sommet **queue, t_sommet *to_add)
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

t_sommet	*exit_queue(t_sommet **queue)
{
	t_sommet *tmp;
	t_sommet *tmp2;

	tmp = *queue;
	if (!(*queue)->queue)
	{
		*queue = NULL;
		return (tmp);
	}
	while ((tmp->queue)->queue)
		tmp = tmp->queue;
	tmp2 = tmp->queue;
	tmp->queue = NULL;
	return (tmp2);
}
