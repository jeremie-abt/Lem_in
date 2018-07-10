/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_transform_flowpb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:21:17 by jabt              #+#    #+#             */
/*   Updated: 2018/07/10 17:01:17 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_sommet		**lm_extend_graph(t_sommet **sommet)
{
	t_sommet **extend_graph;

	extend_graph = lm_copy_hashtable(sommet);
	return (extend_graph);//really ???
}
