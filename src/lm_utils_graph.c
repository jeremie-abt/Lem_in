/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_utils_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:17:03 by jabt              #+#    #+#             */
/*   Updated: 2018/06/20 15:29:36 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// fonction pour return le node qui a le moins de node de niv n-1
//

int				lm_nb_child(t_sommet **sommet, t_sommet *parent)
{

	return (1);
}

t_sommet		*lm_loneliest_node(t_sommet *parent, t_sommet **sommet)
{
	int			distance;
	int			ret;
	t_adj_lst	*adj_lst;
	t_sommet	*cur_node;
	t_nb_child	nb_child;

	distance = parent->distance - 1;// faire gaf pour le node final
	nb_child.nb = 2147483647;
	nb_child.parent = NULL;
	adj_lst = parent->lst;
	while (adj_lst)
	{
		cur_node = lm_get_sommet(sommet, adj_lst->name);	
		if (!cur_node->visited && distance == cur_node->distance)// cur_node est bien un enfant
		{
			ret = lm_nb_child(sommet, cur_node);
			if (ret < nb_child.nb)
			{
				if (ret == 1)
					return (cur_node);
				nb_child.nb = ret;
				nb_child.parent = cur_node;
			}
		}
		adj_lst = adj_lst->next;
	}
	return (nb_child.parent);
}
