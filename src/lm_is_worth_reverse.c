/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_is_worth_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:05:37 by jabt              #+#    #+#             */
/*   Updated: 2018/09/10 14:33:54 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_count_third_part(t_sommet **resid_graph,
		t_sommet *res_first_node, t_sommet *res_second_node, int cur_ret)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	int			ret;
	int			distance;

	ret = 0;
	distance = res_second_node->distance;
	while (cur_ret > 0)
	{
		lst = resid_graph[1]->lst;
		while (lst)
		{
			cur = lm_get_sommet(resid_graph, lst->name);
			if (cur != res_first_node && cur != res_second_node)
			{
				if (cur->distance < distance)
					ret++;
			}
			lst = lst->next;
		}
		ret++;
		cur_ret--;
		distance++;
	}
	return (ret);
}

static int			lm_count_second_part(t_sommet **resid_graph,
		t_sommet *res_first_node, t_sommet *res_second_node)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	int			ret;

	ret = res_second_node->distance - res_first_node->distance;
	lst = resid_graph[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(resid_graph, lst->name);
		if (cur != res_first_node && cur != res_second_node)
		{
			if (cur->distance < res_second_node->distance && cur->distance > 0)
			{
				if (cur->distance <= res_first_node->distance)
					ret += res_second_node->distance - res_first_node->distance;
				else
					ret += res_second_node->distance - cur->distance;
			}
		}
		lst = lst->next;
	}
	return (ret);
}

/*
** 	INPUT
** 	resid_graph and two node within this graph
** 	i want to find all the lower distance than the input distance  nodes link
** 	to the end, that aren't equals to first or second_node
*/

static int			lm_count_first_part(t_sommet **resid_graph,
		t_sommet *res_first_node, t_sommet *res_second_node,
		t_sommet *first_node)
{
	t_adj_lst	*lst;
	t_sommet	*cur;
	int			ret;
	int			distance;

	distance = res_first_node->distance;
	ret = 0;
	lst = resid_graph[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(resid_graph, lst->name);
		if (cur != res_first_node && cur != res_second_node)
		{
			if (cur->distance < distance && cur->distance > 0)
			{
				ret += distance - cur->distance;
			}
		}
		lst = lst->next;
	}
	ret += res_first_node->distance - first_node->distance;
	return (ret);
}

/*
** 	INPUT
** 	graph et resid_graph et les deux extremite de ma shortcut
**	dans le resid_graph et le first node de la shortcut a reverse
**	dans le vraie graph
*/

int					lm_is_worth_path_flow(t_sommet **graph,
		t_sommet **resid_graph, t_sommet *first_node, int ants)
{
	t_sommet	*res_first_node;
	t_sommet	*tmp;
	t_sommet	*res_sec_node;
	int			save;
	int			ret;

	res_sec_node = resid_graph[1]->prev;
	res_first_node = lm_get_sommet(resid_graph, first_node->name);
	save = res_first_node->distance;
	while ((tmp = lm_get_next_sommet_by_flow(resid_graph, res_first_node)) !=
			resid_graph[1] && (save++ || save))
		res_first_node = tmp;
	res_first_node->distance = save;
	while ((tmp = lm_get_next_sommet_by_flow(graph, first_node)) != graph[1])
		first_node = tmp;
	if (res_sec_node->distance < res_first_node->distance)
		lm_swap_ptr((void **)&res_first_node, (void **)&res_sec_node);
	save = lm_count_first_part(resid_graph, res_first_node,
			res_sec_node, first_node);
	ret = 0;
	if (res_first_node->distance != res_sec_node->distance)
		ret = lm_count_second_part(resid_graph, res_first_node, res_sec_node);
	ret += save;
	ret += lm_count_third_part(resid_graph, res_first_node, res_sec_node, save);
	return (ants >= ret);
}
