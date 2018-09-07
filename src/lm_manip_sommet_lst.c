/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_sommet_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:16:32 by jabt              #+#    #+#             */
/*   Updated: 2018/09/07 13:20:51 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_init_sommet(t_sommet *cur_head, char *str)
{
	t_sommet	*graph;

	if (!(graph = malloc(sizeof(t_sommet))))
		return (NULL);
	graph->name  = str;//a voir si ici je ne peux pas simplement faire un bzero
	graph->ant = 0;
	graph->distance = -1;
	graph->visited = 0;
	graph->lst = NULL;
	graph->prev = NULL;
	graph->next = cur_head;
//	graph->queue = NULL;
	return (graph);
}

/*
// attention a la gestion derreur de malloc ici


int					lm_init_graph(t_sommet **graph)
{
	t_control_queue		control;
	t_sommet			*cur;

	ft_bzero(&control, sizeof(t_control_queue));
	lm_add_elem_queue(&control, graph[1]);
	graph[1]->visited = 1; // ??
	while (control.tail || control.head)
	{
		cur = lm_pop_queue(&control);
		lm_add_neighboor(graph, cur, &control);
		printf("cur : %s\n", cur->name);
		lm_init_neighboor_edge(graph, cur);
	}
	return (1);
}
*/

/*
 * 		EXECUTION
 * 		put all visited node that are equal to 1 to 0 and put their prev to NULL
 */

void				lm_clean_visited(t_sommet **graph)
{
	int			i;
	t_sommet	*tmp;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (graph[i])
		{
			tmp = graph[i];
			while (tmp)
			{
				if (tmp->visited == 1 && i != 0)
				{
					tmp->visited = 0;
					tmp->prev = NULL;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void				lm_clean_resid_graph(t_sommet **resid_graph)
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
				if ((tmp->visited == 1 || tmp->visited == 0) && i != 0)
				{
					tmp->visited = 0;
					tmp->prev = NULL;
					tmp->distance = -1;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	resid_graph[0]->visited = 1;
	resid_graph[0]->distance = 0;
	resid_graph[1]->visited = 0;
	resid_graph[1]->distance = 0;
}

int					lm_add_sommet(t_sommet **graph, char *str)
{
	char	*new_str;
	int		key;

	new_str = lm_get_room_name(str);
	if (new_str)
	{
		key = lm_hash(new_str);
		if (!(graph[key] = lm_init_sommet(graph[key], new_str)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int					lm_add_start_end(t_sommet **graph, int index)
{
	char	*line;
	char	*new_room;

	if (graph[index])
	{
		printf("\n\n\ngere ce cas bolloosss lm_manip_sommet.c\n\n\n");
		assert(0);
		return (-1);//pour l'instant non gere aussi
	}

	get_line(&line, NULL, 0);
	new_room = lm_get_room_name(line);
	if (new_room && lm_is_good_room(new_room))
	{
		if (!(graph[index] = malloc(sizeof(t_sommet))))
		{
			free(line);
			if (new_room)
				free(new_room);
			return (-1);
		}
	}
	else
	{
		free(line);
		if (new_room)
			free(new_room);
		return (-1);
	}
	free(line);
	ft_bzero(graph[index], sizeof(t_sommet));
	graph[index]->name = new_room;
	return (1);
}
