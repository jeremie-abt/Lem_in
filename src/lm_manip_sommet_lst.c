/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_sommet_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:16:32 by jabt              #+#    #+#             */
/*   Updated: 2018/09/27 15:22:00 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_init_sommet(t_sommet *cur_head, char *str)
{
	t_sommet	*graph;

	if (!(graph = malloc(sizeof(t_sommet))))
		return (NULL);
	graph->name = str;
	graph->ant = 0;
	graph->distance = -1;
	graph->visited = 0;
	graph->lst = NULL;
	graph->prev = NULL;
	graph->next = cur_head;
	return (graph);
}

/*
** 		EXECUTION
** 		put all visited node that are equal to 1 to 0 and put their prev to NULL
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

	i = -1;
	while (++i < HASH_SIZE)
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
	resid_graph[0]->visited = 1;
	resid_graph[0]->distance = 0;
	resid_graph[1]->visited = 0;
	resid_graph[1]->distance = 0;
}

int					lm_add_sommet(t_sommet **sommet, char *str)
{
	int		key;
	char	*tmp;

	if (!(tmp = ft_strsub(str, 0, lm_get_name_length(str))))
		return (-2);
	key = lm_hash(tmp);
	if (!(sommet[key] = lm_init_sommet(sommet[key], tmp)))
		return (-2);
	return (1);
}

int					lm_add_start_end(t_sommet **graph, int index)
{
	char	*line;

	if (graph[index])
		return (-1);
	get_line(&line, NULL, 0);
	if (lm_is_good_room(line) == 1)
	{
		if (!(graph[index] = malloc(sizeof(t_sommet))))
			return (-2);
		ft_bzero(graph[index], sizeof(t_sommet));
		if (!(graph[index]->name =
			ft_strsub(line, 0, lm_get_name_length(line))))
			return (-2);
	}
	else
		return (-1);
	return (1);
}
