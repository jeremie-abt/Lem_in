/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_adj_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:40:21 by jabt              #+#    #+#             */
/*   Updated: 2018/06/06 14:02:03 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				lm_add_neighbor(t_sommet *sommet, char *neighbor)
{
	return (1);
}

int				lm_add_tube(t_sommet **sommet, char *pattern)
{
	char		*second;
	char		*first;
	t_sommet	*node;

	if (lm_verif_tube(pattern) == -1)
		return (-1);
	second = ft_strchr(pattern, '-') + 1;
	if (!(first = ft_strsub(pattern, 0, (second - pattern) - 1)))
		return (-1);
///	key = lm_hash(first);
	printf("je vais chercher : %s\n", first);
	node = lm_get_sommet(sommet, first);
	printf("est je bon : %s\n", node->name);
	exit(4);
//	lm_add_meighbor(sommet[key]);
	free(first);
	return (1);
}
