/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/09/07 16:00:22 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int			ants;
	int			path;
	t_sommet	*graph[HASH_SIZE];

	ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));
	if ((ants = lm_parseur(graph)) == -1)
	{
		write(1, "ERROR\n", 6);
		lm_free_hashtable(graph);
		ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));
		return (0);
	}
	path = lm_find_best_flow(graph, ants);
	if (!lm_print_ants(graph, ants, path))
	{
		// bien free
		exit(-1);
	}
	lm_free_hashtable(graph);
	ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));
	return (0);
}
