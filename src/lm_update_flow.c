/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_update_flow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:20:34 by jabt              #+#    #+#             */
/*   Updated: 2018/08/22 13:29:34 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 		update flow is a procedure which take as input my hashtable
 * 		and send a flow in the different shortest possible until its
 * 		possible (until it's blocked because no path from S to T)
*/
/*
static void		lm_fill_path(t_sommet *start, t_sommet *node)
{
	t_adj_lst	*lst;

	while (node != start)
	{
		lst = lm_get_edge(node->lst, node->prev->name);
		lst->flow = 0;
		node = node->prev;
	}
//	lst = lm_get_edge(node->lst, node->prev->name);
//	lst->flow = 1;
//	node = node->prev;
}

static void		lm_update_path(t_sommet **sommet, t_sommet *node)
{
	static int stop;
	t_sommet	*prev;
	t_sommet	*cur;
	t_adj_lst	*edge;
	stop++;


	prev = node->prev;
	cur = node;
	edge = lm_get_edge(cur->lst, prev->name);
	while (prev != sommet[0] && edge->flow > 0)
	{
//		if (prev)
//			printf("prev : %s\n", prev->name);
//		else
//			printf("prev n'existe pas\n");
		cur = prev;
		prev = cur->prev;
		edge = lm_get_edge(cur->lst, prev->name);
	}
	if (prev == sommet[0] && edge->flow > 0)
	{
		lm_fill_path(sommet[0], node);
		edge = lm_get_edge(sommet[1]->lst, node->name);
		edge->flow = 0;
	}
}
*/
/*
 *		prendre un node
 *		parcourir ca list (get_sommet)
 *		if il est pas visited
 *		inverse les deux edges si la backward est 0
 *		et inverse juste la premiere sinon
 *
 *
 *
 *
 *
 *
 */
/*
static void		lm_reverse_edge(t_sommet **sommet, char *first, char *second)
{
	//printf("first : %s\n", first);
	//printf("second : %s\n\n", second);
	t_sommet	*cur;
	t_sommet	*secondcur;
	t_adj_lst	*first_edge;
	t_adj_lst	*second_edge;

	cur = lm_get_sommet(sommet, first);
	secondcur = lm_get_sommet(sommet, second);
	first_edge = lm_get_edge(cur->lst, second);
	second_edge = lm_get_edge(secondcur->lst, first);
	if (first_edge->flow == 0 || second_edge->flow == 0)
	{
//		printf("first\n");
		first_edge->flow ^= 1;//sert a inverser le bit 1 -> 0 et 0 -> 1
		second_edge->flow ^= 1;
	}
	else
	{
		
		if (cur->distance > secondcur->distance)
		{
//			printf("seocnd\n");
			first_edge->flow = 0;
		}
		else
		{
//			printf("third\n");
			second_edge->flow = 0;
		}
	}
}

static void		lm_reverse_flow(t_sommet **sommet)
{
	t_control_queue		control;
	t_sommet			*cur;
	t_sommet			*secondcur;
	t_adj_lst			*lst;

	ft_bzero(&control, sizeof(t_control_queue));
	lm_add_elem_queue(&control, sommet[1]);
	sommet[1]->visited = 1;
	while (control.tail || control.head)
	{
		cur = lm_pop_queue(&control);
		lst = cur->lst;
		while (lst)
		{
			secondcur = lm_get_sommet(sommet, lst->name);
			if (!secondcur->visited)
			{
				lm_reverse_edge(sommet, cur->name, secondcur->name);
			}
			lst = lst->next;
		}
		lm_add_neighboor(sommet, cur, &control);
	}
}

void			lm_update_flow(t_sommet	**sommet)
{
	t_adj_lst		*lst;
	t_sommet		*cur;

//	printf("list avant :\n");
//	print_adj_lst_distance(sommet, sommet[1], sommet[1]->lst);	
//

	lm_init_graph(sommet);
	print_flow(sommet);	
exit(5);

	lm_sort_lst_byorder(sommet);
	lst = sommet[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(sommet, lst->name);
		lm_update_path(sommet, cur);		
		lst = lst->next;
	}

//	printf("avant de reverse :\n\n");
//	print_flow(sommet);
//	printf("\n\n");
	lm_reverse_flow(sommet);
//	printf("apres reverse :\n\n");
//	print_flow(sommet);
//	lm_update_forward_edge();
//	printf("list apres :\n");
//	print_adj_lst_distance(sommet, sommet[1], sommet[1]->lst);
}*/
