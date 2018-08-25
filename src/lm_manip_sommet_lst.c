/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_sommet_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:16:32 by jabt              #+#    #+#             */
/*   Updated: 2018/08/25 16:45:11 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_init_sommet(t_sommet *cur_head, char *str)
{
	t_sommet	*sommet;

	if (!(sommet = malloc(sizeof(t_sommet))))
		return (NULL);
	sommet->name  = str;//a voir si ici je ne peux pas simplement faire un bzero
	sommet->ant = 0;
	sommet->distance = -1;
//	sommet->capacity = 0;
	sommet->lst = NULL;
	sommet->prev = NULL;
	sommet->next = cur_head;
//	sommet->queue = NULL;
	return (sommet);
}

/*
// attention a la gestion derreur de malloc ici


int					lm_init_graph(t_sommet **sommet)
{
	t_control_queue		control;
	t_sommet			*cur;

	ft_bzero(&control, sizeof(t_control_queue));
	lm_add_elem_queue(&control, sommet[1]);
	sommet[1]->visited = 1; // ??
	while (control.tail || control.head)
	{
		cur = lm_pop_queue(&control);
		lm_add_neighboor(sommet, cur, &control);
		printf("cur : %s\n", cur->name);
		lm_init_neighboor_edge(sommet, cur);
	}
	return (1);
}
*/
void				lm_clean_visited(t_sommet **sommet)
{
	int			i;
	t_sommet	*tmp;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (sommet[i])
		{
			tmp = sommet[i];
			while (tmp)
			{
				tmp->visited = 0;
				tmp = tmp->next;
			}
		}
		i++;
	}
}

int					lm_add_sommet(t_sommet **sommet, char *str)
{
	char	*new_str;
	int		key;

	new_str = lm_get_room_name(str);
	if (new_str)
	{
		key = lm_hash(new_str);
		if (!(sommet[key] = lm_init_sommet(sommet[key], new_str)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int					lm_add_start_end(t_sommet **sommet, int index)
{
	char	*ligne;
	char	*new_room;

	if (sommet[index])
		return (-1);//pour l'instant non gere aussi
	get_next_line(0, &ligne);
	new_room = lm_get_room_name(ligne);
	if (new_room && lm_is_good_room(new_room))
	{
		if (!(sommet[index] = malloc(sizeof(t_sommet))))
		{
			free(ligne);
			if (new_room)
				free(new_room);
			return (-1);
		}
	}
	else
	{
		free(ligne);
		if (new_room)
			free(new_room);
		return (-1);
	}
	free(ligne);
	ft_bzero(sommet[index], sizeof(t_sommet));
	sommet[index]->name = new_room;
	return (1);
}
