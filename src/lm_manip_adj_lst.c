/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_adj_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:40:21 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 11:56:19 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adj_list		*lm_add_node_adj_lst(char *name)
{
	t_adj_list		*node;

	if (!(node = malloc(sizeof(*node))))
		return (NULL);
	node->neighbor = name;
	return (node);
}
