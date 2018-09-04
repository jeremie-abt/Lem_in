/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_sommet_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:16:32 by jabt              #+#    #+#             */
/*   Updated: 2018/09/04 16:09:45 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static t_sommet		*lm_init_sommet(t_sommet *cur_head, char *str)
{
	t_sommet	*sommet;

	if (!(sommet = malloc(sizeof(t_sommet))))
		return (NULL);
	sommet->name = str;
	sommet->ant = 0;
	sommet->distance = -1;
	sommet->lst = NULL;
	sommet->prev = NULL;
	sommet->next = cur_head;
	return (sommet);
}

int					lm_add_sommet(t_sommet **sommet, char *str)
{
	int		key;

	key = lm_hash(lm_get_room_name(str));
	if (!(sommet[key] = lm_init_sommet(sommet[key],
		ft_strsub(str, 0, lm_get_name_length(str)))))
		return (-1);
	return (1);
}

int					lm_add_start_end(t_sommet **sommet, int index)
{
	char	*line;

	if (sommet[index])
		return (-1);
	get_line(&line, NULL, 0);
	if (lm_is_good_room(line) == 1)
	{
		if (!(sommet[index] = malloc(sizeof(t_sommet))))
			return (-1);
		ft_bzero(sommet[index], sizeof(t_sommet));
		sommet[index]->name = ft_strsub(line, 0, lm_get_name_length(line));
	}
	else
		return (-1);
	return (1);
}
