/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:11 by jabt              #+#    #+#             */
/*   Updated: 2018/09/25 16:36:32 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	 print_adj_lst(t_sommet *node, t_adj_lst *adj_lst)
{
	ft_printf("voila le node : %s ces voisins et leurs edges :\n\n", node->name);
	while (adj_lst)
	{
		ft_printf("	lst : %s\n", adj_lst->name);
		adj_lst = adj_lst->next;
	}
	ft_printf("\n");
}

void	 print_adj_lst_distance(t_sommet **hashtable, t_sommet *node, t_adj_lst *adj_lst)
{
	t_sommet	*cur;

	ft_printf("voila le node : %s ces voisins et leurs edges :\n\n", node->name);
	while (adj_lst)
	{
		ft_printf("	lst : %s ", adj_lst->name);
		cur = lm_get_sommet(hashtable, adj_lst->name);
		ft_printf("ca distance : %d\n", cur->distance);
		adj_lst = adj_lst->next;
	}
	ft_printf("\n");
}

void	print_sommet(t_sommet *hashtable)
{
	ft_printf("sommet : %s\n", hashtable->name);
}

void	print_hashtable(t_sommet **hashtable)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			ft_printf("HEAD %d : %s\n", i, hashtable[i]->name);
		}
		i++;
	}
}
void	print_all_hashtable(t_sommet **hashtable)
{
	int			i;
	t_sommet	*cur;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			cur = hashtable[i];
			while (cur)
			{
				ft_printf("HEAD %d : %s neighbor ->\n", i, cur->name);
				print_adj_lst(cur, cur->lst);
				cur = cur->next;
			}
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
			ft_printf("in)%s neighbor ->\n", resid_graph[i]->name);
			print_adj_lst(resid_graph[i], resid_graph[i]->lst);
			ft_printf("(out)%s neighbor ->\n", resid_graph[i]->next->name);
			print_adj_lst(resid_graph[i], resid_graph[i]->next->lst);

//			ft_printf("just first one : %s\n", hashtable[i]->lst->name);
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
			ft_printf("HEAD %d : %s sa distance : %d  neighbor ->\n", i, hashtable[i]->name, hashtable[i]->distance);
			print_adj_lst(hashtable[i], hashtable[i]->lst);
//			ft_printf("just first one : %s\n", hashtable[i]->lst->name);
		}
		i++;
	}

}


void	print_hashtable_distance_and_prev(t_sommet **hashtable)
{
	int		i;
	t_sommet *cur;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			cur = hashtable[i];
			while (cur)
			{
				if (cur->prev)
					ft_printf("HEAD %d : %s sa distance : %d  prev -> %s\n", i, cur->name, cur->distance, cur->prev->name);
				else
					ft_printf("HEAD %d : %s sa distance : %d  prev -> NULL\n", i, cur->name, cur->distance);
				cur = cur->next;
			}

//			ft_printf("just first one : %s\n", hashtable[i]->lst->name);
		}
		i++;
	}

}

void	print_hashtable_visited_and_prev(t_sommet **hashtable)
{
	int			i;
	t_sommet	*cur;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (hashtable[i])
		{
			cur = hashtable[i];
			while (cur)
			{
				if (cur->prev)
					ft_printf("HEAD %d : %s visited : %d  prev -> %s\n", i, cur->name, cur->visited, cur->prev->name);
				else
					ft_printf("HEAD %d : %s sa visited : %d  prev -> NULL\n", i, cur->name, cur->visited);
				cur = cur->next;
			}
//			ft_printf("just first one : %s\n", cur->lst->name);
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
			cur = hashtable[i];
			while (cur)
			{
				ft_printf("HEAD %d : %s flow :\n", i, cur->name);
				lst = cur->lst;
				while (lst)
				{
					if (lst->name)
						ft_printf("flow vers %s : %d\n", lst->name, lst->flow);
					else
						ft_printf("FLOW MAIS YA PAS DNAME : %d\n",lst->flow);

					lst = lst->next;
				}
				ft_printf("\n");
				cur = cur->next;
			}
		}
		i++;
	}

}

void	print_node(t_sommet *node)
{
	ft_printf("voici le name : %s\n", node->name);
	ft_printf("voici la distance : %d\n", node->distance);
	ft_printf("lst : %p\n", node->lst);
	ft_printf("next : %p\n", node->next);
	//ft_printf("queue %p\n", node->queue);
}


/*void	print_path(t_sommet **hashtable, t_sommet *node)
{
	ft_printf("%s->", hashtable[1]->name);
	while (node)
	{
		ft_printf("%s->", node->name);
		node = node->queue;
	}
	ft_printf("\n");
}
*/
void	print_queue(t_control_queue *control)
{
	t_queue	*head;

	head = control->head;
	while (head)
	{
		ft_printf("current : %s\n", head->sommet->name);
		head = head->next;
	}
}


void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("stack : %s addr : %p\n", stack->sommet->name, stack);
		stack = stack->next;
	}
}

void	print_ant_path(t_sommet **graph)
{
	t_adj_lst	*lst;
	t_sommet	*cur;

	ft_printf("voici le nombre de fourmis sur chacun de tes paths :\n\n");
	lst = graph[1]->lst;
	while (lst)
	{
		cur = lm_get_sommet(graph, lst->name);
		ft_printf("voici le nombre de fourmis ici : %s -> %d\n", cur->name, cur->ant);
		lst = lst->next;
	}
}

int		is_node_in_graph(t_sommet **graph, t_sommet *node)
{
	int		i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (graph[i] == node)
			return (1);
		i++;
	}
	return (0);
}

void	print_tab_ant(t_sommet **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i])
		{
			ft_printf("tab[%d] : %s\n", i, tab[i]->name);
		}
		else
			ft_printf("tab[%d] : NULL\n", i);
		i++;
	}
}
