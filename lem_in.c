/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/07/10 17:01:40 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int 		ret;
	int			ants;
	int i = 0;
	char		*ligne;
	t_sommet	*sommet[HASH_SIZE];
	t_sommet	**extend_graph;


	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
	if ((ants = lm_parseur(sommet)) == -1)
	{
		write(1, "ERROR\n", 6);
		lm_free_hashtable(sommet);
		ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
		sleep(150);
		return (0);
	}

	lm_fill_distance(sommet, ants);
	extend_graph = lm_extend_graph(sommet);
//	lm_extend_graph(sommet);
//	lm_find_path_core(sommet);
	lm_free_hashtable(sommet);
	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
//	sleep(150);
	return (0);
}
