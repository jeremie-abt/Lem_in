/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/09/07 14:13:40 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

int		main(int argc, char **argv)
{
	int			ants;
	int i = 0;
	char		*ligne;
	int			path;
	t_sommet	*graph[HASH_SIZE];
	t_sommet	**resid_graph;

	ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));	
	if ((ants = lm_parseur(graph)) == -1)
	{
		write(1, "ERROR\n", 6);
		lm_free_hashtable(graph);
		ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));
		return (0);
	}

	path = lm_find_best_flow(graph, ants);

//	printf("graph distance :\n\n");
//	print_hashtable_distance_and_prev(graph);
//	printf("\n\ngraph visited :\n\n");
//	print_hashtable_visited_and_prev(graph);

	if (!lm_print_ants(graph, ants, path))
	{
		printf("attention tu dois gerer ce cas lem_in.c ligne 47!!!! \n\n\n\n");
	}

	exit(5);
	
// gerer tout simplement mon flow et envoyer les fourmis correctement
// dans mes room je rajoute une variable foumis et voila 	

//	lm_suppr_internal_shortcut(graph);

	// faire une procedure pour free mon graph de resid
	
	
	//  je dois ici :
	//  	clean les internes shortcut
	//  	compter le nombre de path
	//  	REFLECHI BIEN A TES STRUCTURE DE DONNES



	lm_free_hashtable(graph);
	ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));
	return (0);
}
