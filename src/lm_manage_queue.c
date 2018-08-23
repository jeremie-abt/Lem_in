/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manage_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:33:49 by jabt              #+#    #+#             */
/*   Updated: 2018/08/23 10:46:59 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 	for use this queue, you need :
 * 	declare a t_control_queue control
 * 	make a ft_bzero to 0ed the structure and after you can use it by those
 * 	two functions
 */

t_sommet		*lm_pop_queue(t_control_queue *control)
{
	t_sommet		*ret;
	t_queue			*save;

	save = control->tail;
	ret = control->tail->sommet;
	if (control->tail->next)
		control->tail = control->tail->next;
	else
		ft_bzero(control, sizeof(t_control_queue));
	free(save);
	return (ret);
}

t_sommet			*lm_pop_stack(t_stack **head)
{
	t_sommet	*ret;
	t_stack		*tmp;

	if (*head)
	{
		tmp = (*head)->next;
		ret = (*head)->sommet;
		free(*head);
		(*head) = tmp;
	}
	else
		return (NULL);
	return (ret);
}

int		lm_add_elem_queue(t_control_queue *control, t_sommet *new_elem)
{
//	static t_control_queue	*control;
	t_queue					*new_head;

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
		control->head->next = new_head;
		control->head = new_head;
	}
	return (1);
}

int		lm_add_elem_stack(t_stack **head, t_sommet *new_elem)
{
	t_stack				*new_head;

	if (!(new_head = malloc(sizeof(t_stack))))
		return (-1);
	new_head->sommet = new_elem;
	new_head->next = *head;
	*head = new_head;
	return (1);
}
