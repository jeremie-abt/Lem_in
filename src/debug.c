/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:11 by jabt              #+#    #+#             */
/*   Updated: 2018/08/22 17:45:42 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
static void	print_flow(t_adj_lst *lst)
{
	while (lst)
	{
		printf("vers : %s -> %d\n", lst->name, lst->flow);
		lst = lst->next;
	}
}

void	print_hashtable_flow(t_sommet **hashtable)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			printf("HEAD %d : %s\n", i, hashtable[i]->name);
			print_flow(hashtable[i]->lst);
		}
		i++;
	}
}
*/

void	 print_adj_lst(t_sommet *node, t_adj_lst *adj_lst)
{
	printf("voila le node : %s ces voisins et leurs edges :\n\n", node->name);
	while (adj_lst)
	{
		printf("	lst : %s\n", adj_lst->name);
		adj_lst = adj_lst->next;
	}
	printf("\n");
}

void	 print_adj_lst_distance(t_sommet **hashtable, t_sommet *node, t_adj_lst *adj_lst)
{
	t_sommet	*cur;

	printf("voila le node : %s ces voisins et leurs edges :\n\n", node->name);
	while (adj_lst)
	{
		printf("	lst : %s ", adj_lst->name);
		cur = lm_get_sommet(hashtable, adj_lst->name);
		printf("ca distance : %d\n", cur->distance);
		adj_lst = adj_lst->next;
	}
	printf("\n");
}

void	print_sommet(t_sommet *hashtable)
{
	printf("sommet : %s\n", hashtable->name);
}

void	print_hashtable(t_sommet **hashtable)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			printf("HEAD %d : %s\n", i, hashtable[i]->name);
		}
		i++;
	}
}
void	print_all_hashtable(t_sommet **hashtable)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			printf("HEAD %d : %s neighbor ->\n", i, hashtable[i]->name);
			print_adj_lst(hashtable[i], hashtable[i]->lst);
//			printf("just first one : %s\n", hashtable[i]->lst->name);
		}
		i++;
	}
}

void	print_resid_graph(t_sommet **resid_graph)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (resid_graph[i])
		{
			printf("in)%s neighbor ->\n", resid_graph[i]->name);
			print_adj_lst(resid_graph[i], resid_graph[i]->lst);
			printf("(out)%s neighbor ->\n", resid_graph[i]->next->name);
			print_adj_lst(resid_graph[i], resid_graph[i]->next->lst);

//			printf("just first one : %s\n", hashtable[i]->lst->name);
		}
		i++;
	}
}

void	print_all_hashtable_wdistance(t_sommet **hashtable)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			printf("HEAD %d : %s sa distance : %d  neighbor ->\n", i, hashtable[i]->name, hashtable[i]->distance);
			print_adj_lst(hashtable[i], hashtable[i]->lst);
//			printf("just first one : %s\n", hashtable[i]->lst->name);
		}
		i++;
	}

}


void	print_hashtable_distance_and_prev(t_sommet **hashtable)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			if (hashtable[i]->prev)
				printf("HEAD %d : %s sa distance : %d  prev -> %s\n", i, hashtable[i]->name, hashtable[i]->distance, hashtable[i]->prev->name);
			else
				printf("HEAD %d : %s sa distance : %d  prev -> NULL\n", i, hashtable[i]->name, hashtable[i]->distance);

//			printf("just first one : %s\n", hashtable[i]->lst->name);
		}
		i++;
	}

}
void	print_flow(t_sommet **hashtable)
{
	int		i;
	t_adj_lst		*lst;
	t_sommet		*cur;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			printf("HEAD %d : %s flow :\n", i, hashtable[i]->name);
			lst = hashtable[i]->lst;
			while (lst)
			{
				printf("flow vers %s : %d\n", lst->name, lst->flow);
				lst = lst->next;
			}
			printf("\n");
//			printf("just first one : %s\n", hashtable[i]->lst->name);
		}
		i++;
	}

}




void	print_node(t_sommet *node)
{
	printf("voici le name : %s\n", node->name);
	printf("voici la distance : %d\n", node->distance);
	printf("lst : %p\n", node->lst);
	printf("next : %p\n", node->next);
	//printf("queue %p\n", node->queue);
}


/*void	print_path(t_sommet **hashtable, t_sommet *node)
{
	printf("%s->", hashtable[1]->name);
	while (node)
	{
		printf("%s->", node->name);
		node = node->queue;
	}
	printf("\n");
}
*/
void	print_queue(t_control_queue *control)
{
	t_queue	*tail;

	tail = control->tail;
	while (tail)
	{
		printf("current : %s\n", tail->sommet->name);
		tail = tail->next;
	}
}


void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("stack : %s addr : %p\n", stack->sommet->name, stack);
		stack = stack->next;
	}
}
