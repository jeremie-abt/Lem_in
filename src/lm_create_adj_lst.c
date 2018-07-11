/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_create_adj_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:23:37 by jabt              #+#    #+#             */
/*   Updated: 2018/07/11 17:15:26 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 *
 * 			int and out lst are list wich permit to transform the graph
 * 			into a flow problem, one nodes are now two nodes,
 * 			one with the ingoing edges wich were comming into the node
 * 			and the second with the outgoing edges wich were outgoing
 * 			from the node
 */


t_adj_lst		*lm_create_inlst(t_sommet **sommet, t_sommet *node)
{
	int			distance;
	t_sommet	*cur;
	t_adj_lst	*tmp;
	t_adj_lst	*inlst;

	inlst = NULL;
	distance = node->distance;
	tmp = node->lst;
	while (tmp)
	{
		cur = lm_get_sommet(sommet, tmp->name);
		if (cur->distance <= distance)
		{
			if (cur->distance == 0)
			{
				if (cur == sommet[0])
					if (lm_add_node_lst(&inlst, cur->name) == -1)
						return (NULL);
			}
			else
				if (lm_add_node_lst(&inlst, cur->name) == -1)
					return (NULL);
		}
		tmp = tmp->next;
	}
	return (inlst);
}

t_adj_lst  *lm_create_outlst(t_sommet **sommet, t_sommet *node)
{
	int			distance;
	t_sommet	*cur;
	t_adj_lst	*tmp;
	t_adj_lst	*outlst;

	outlst = NULL;
	distance = node->distance;
	tmp = node->lst;
	while (tmp)
	{
		cur = lm_get_sommet(sommet, tmp->name);
		if (cur->distance > distance)
		{
			if (lm_add_node_lst(&outlst, cur->name) == -1)
				return (NULL);
		}
		else if (cur->distance == 0 && cur == sommet[1])
		{
			if (lm_add_node_lst(&outlst, cur->name) == -1)
				return (NULL);
		}
		tmp = tmp->next;
	}
	return (outlst);
}

t_adj_lst	*lm_copy_lst(t_adj_lst *src)
{
	t_adj_lst	*ret;
	
	if (!(ret = malloc(sizeof(t_adj_lst))))
		return (NULL);
//	ft_memcpy((void *)ret, (void *)src, sizeof(t_adj_lst));
	ret->name = src->name;
	if (src->next)
	{
		if (!(ret->next = lm_copy_lst(src->next)))
		{
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}
