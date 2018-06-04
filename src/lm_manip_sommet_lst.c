/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_sommet_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:16:32 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 19:16:18 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_sommet	*lm_adefinir(t_sommet *head, char *str)
{
	t_sommet	*new_head;

	if (!(new_head = malloc(t_sommet)))
		return (NULL);
	
}

int			lm_add_sommet(t_sommet **sommet, char *str)
{
//	t_sommet	*node;
	int		key;

	key = lm_hash(str);
	if (!sommet[key])
	{
		if (!(sommet[key] = malloc(sizeof(t_sommet))))
			return (0);
		sommet[key]->name  = str;
		sommet[key]->distance = -1;
		sommet[key]->visited = 0;
		sommet[key]->lst = NULL;
		sommet[key]->next = NULL;
	}
	else
	{
		
	}
		printf("attention collision : %s\n", str);
	return (1);
}
