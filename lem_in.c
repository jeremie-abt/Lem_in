/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/09/12 11:38:56 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_error_quit_properly(t_sommet **graph)
{
	write(1, "ERROR\n", 6);
	lm_free_hashtable(graph);
	exit(42);
}

static void		lm_quit_properly(t_sommet **graph)
{
	lm_free_hashtable(graph);
	exit(42);
}

int				main(int argc, char **argv)
{
	int			ants;
	int			path;
	t_sommet	*graph[HASH_SIZE];

	ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));
	if ((ants = lm_parseur(graph)) == -1)
		lm_error_quit_properly(graph);
	printf("\n");
	path = lm_find_best_flow(graph, ants);
	if (path <= 0)
		lm_error_quit_properly(graph);
	if (graph[1]->prev == graph[0])
	{
		lm_print_all_ants(graph[1]->name, ants);
		lm_quit_properly(graph);
	}
	if (lm_core_print_ants(graph, ants, path) == -1)
		lm_error_quit_properly(graph);
	lm_quit_properly(graph);
	return (0);
}
