/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/09/03 19:30:08 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

int		main(int argc, char **argv)
{
	int 		tmp_fourmis;
	int			ants;
	int i = 0;
	char		*ligne;
	int			path;
//	t_sommet	*sommet[HASH_SIZE];
	t_sommet	**resid_graph;

	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
	if ((ants = lm_parseur(sommet)) == -1)
	{
		write(1, "ERROR\n", 6);
		lm_free_hashtable(sommet);
		ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));
		return (0);
	}


//	lm_fill_distance(sommet, ants);
	
/*	resid_graph = lm_copy_hashtable();
	while (lm_search_path_dfs(resid_graph))
	{
		printf("ouai\n");
		lm_update_main_graph(sommet, resid_graph);// pas besoins de copier le prev
	}*/
	tmp_fourmis = ants;
	path = lm_find_best_flow(sommet, &tmp_fourmis);


	//print_hashtable_visited_and_prev(sommet);
	//exit(4);
	//printf("exit dans lem_in.c apres le lm_find_best_flowi avec ce nombre de path : %d\n", path);
	//exit(5);

	//path = lm_find_max_flow(sommet);

	//lm_fill_distance_flow(sommet);

	// il faut vraiment que je gere cette variable

	if (!lm_print_ants(sommet, ants, path))
	{
		printf("attention tu dois gerer ce cas lem_in.c ligne 47!!!! \n\n\n\n");
	}

	exit(5);
	
// gerer tout simplement mon flow et envoyer les fourmis correctement
// dans mes room je rajoute une variable foumis et voila 	

//	lm_suppr_internal_shortcut(sommet);

	// faire une procedure pour free mon graph de resid
	
	
	//  je dois ici :
	//  	clean les internes shortcut
	//  	compter le nombre de path
	//  	REFLECHI BIEN A TES STRUCTURE DE DONNES



	lm_free_hashtable(sommet);
	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));
	return (0);
}
