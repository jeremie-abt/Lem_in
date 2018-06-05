/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_sommet_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:16:32 by jabt              #+#    #+#             */
/*   Updated: 2018/06/05 18:37:43 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_init_sommet(t_sommet *cur_head, char *str)
{
	t_sommet	*sommet;
	static int test;
	test++;

	if (test == 13 || !(sommet = malloc(sizeof(t_sommet))))
		return (NULL);
	sommet->name  = str;
	sommet->distance = -1;
	sommet->visited = 0;
	sommet->lst = NULL;
	sommet->next = cur_head;
	return (sommet);
}

int			lm_add_sommet(t_sommet **sommet, char *str)
{
	char	*new_str;
	int		key;
	int		length;

	new_str = ft_strchr(str, ' ');
	if (new_str)
	{
		length = new_str - str;
		new_str = ft_strsub(str, 0, length);
		key = lm_hash(str);
		if (!(sommet[key] = lm_init_sommet(sommet[key], new_str)))
			return (0);
	}
	else
		return (0);
	return (1);
}
