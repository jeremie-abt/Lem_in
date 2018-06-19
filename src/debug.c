/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:11 by jabt              #+#    #+#             */
/*   Updated: 2018/06/19 14:15:44 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void print_adj_lst(t_adj_lst *adj_lst)
{
	while (adj_lst)
	{
		printf("neghbor : %s\n", adj_lst->name);
		adj_lst = adj_lst->next;
	}
}

void	print_sommet(t_sommet *sommet)
{
	printf("sommet : %s\n", sommet->name);
}

void	print_hashtable(t_sommet **sommet)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (sommet[i])
		{
			printf("HEAD %d : %s\n", i, sommet[i]->name);

		}
		i++;
	}
}

void	print_all_hashtable(t_sommet **sommet)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (sommet[i])
		{
			printf("HEAD %d : %s neighbor ->\n", i, sommet[i]->name);
			print_adj_lst(sommet[i]->lst);
//			printf("just first one : %s\n", sommet[i]->lst->name);
		}
		i++;
	}
}

void	print_all_hashtable_wdistance(t_sommet **sommet)
{
	int		i;
	
	i = 0;
	while (i < HASH_SIZE)
	{
		if (sommet[i])
		{
			printf("HEAD %d : %s sa distance : %d  neighbor ->\n", i, sommet[i]->name, sommet[i]->distance);
			print_adj_lst(sommet[i]->lst);
//			printf("just first one : %s\n", sommet[i]->lst->name);
		}
		i++;
	}

}

void	debug_queue(t_sommet **sommet)
{
	int	i = 0;

	while (i < HASH_SIZE)
	{
		if (sommet[i] && sommet[i]->queue)
		{
			printf("cette queue exist index : %d de la hashtable name : %s\n", i, sommet[i]->name);
		}
		i++;
	}
}
