/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:39:02 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 18:27:58 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 		INPUT
 * 		une hashtable de taille HASH_SIZE
 * 		un nombre de fourmis qui doit etre sup a 0 normalement
 * 		qui represente un graph flow
 * 		le node debut est hashtable[0] et celui de fin est hashtable[1]
 * 		le but est de renvoyer le maximum de shortest path distinct
 * 		via un bfs donc sans faire attention aux shortcut
 */

int			lm_find_best_flow(t_sommet **sommet, int ants)
{
	int		ret;
	int		path;

	// il me faut une subroutine de BFS simple qui va la ou visited == 0	

	ret = 0;
	path = 0;
	while (path < ants && (ret = lm_find_one_path_with_bfs(sommet)))
	{
		if (ret == 2)
		{
			printf("attention a ce que tu fais dans ce cas la lm_algo.c\n\n");
			exit(4);
			return (1);
		}
		path++;
		lm_clean_visited(sommet);
	}
}

/*
 * 		RETURN
 * 		nombre de path
 */
