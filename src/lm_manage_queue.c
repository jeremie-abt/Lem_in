/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manage_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:33:49 by jabt              #+#    #+#             */
/*   Updated: 2018/09/25 18:18:51 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 		INPUT
** 		struct t_control_queue which must not be dynamically allocated
** 		t_control_queue.head point on a chained list which must be free
** 		but the variable inside this head must not be freed
*/

void			lm_free_queue(t_control_queue *control)
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

/*
** 	To use this queue, you need :
** 	to declare a t_control_queue control
** 	to make a ft_bzero to 0ed the structure and after you can use it by those
** 	two functions
*/

t_sommet		*lm_pop_queue(t_control_queue *control)
{
	t_sommet		*ret;
	t_queue			*save;
	static int		stop;

	stop++;
	ret = control->tail->sommet;
	save = control->head;
	if (save->next)
	{
		while (save->next->next)
			save = save->next;
		free(save->next);
		save->next = NULL;
		control->tail = save;
	}
	else
	{
		if (control->head)
			free(control->head);
		control->head = NULL;
		control->tail = NULL;
	}
	return (ret);
}

int				lm_add_elem_queue(t_control_queue *control, t_sommet *new_elem)
{
	t_queue					*new_head;
	static int stop;

	if (!(new_head = malloc(sizeof(t_queue))))
		return (-1);
	new_head->sommet = new_elem;
	new_head->next = NULL;
	if (!control->head)
	{
		control->head = new_head;
		control->tail = new_head;
	}
	else
	{
		new_head->next = control->head;
		control->head = new_head;
	}
	stop++;
/*	if (stop == 13)
	{
		printf("issou\n");
		while (1);
	}*/
	return (1);
}
