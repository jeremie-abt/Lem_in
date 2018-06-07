/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:11 by jabt              #+#    #+#             */
/*   Updated: 2018/06/07 11:25:33 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void print_adj_list(t_adj_list *adj_list)
{
	while (adj_list)
	{
		printf("neghbor : %s\n", adj_list->name);
		adj_list = adj_list->next;
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
			print_adj_list(sommet[i]->lst);
//			printf("just first one : %s\n", sommet[i]->lst->name);
		}
		i++;
	}
}
