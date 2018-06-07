/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/06/07 11:55:43 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int 		ret;
	int			ant;
	int i = 0;
	char		*ligne;
	t_sommet	*sommet[HASH_SIZE];

	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
/*	while (get_next_line(0, &ligne))
	{
		if ((ret = lm_parseur(ligne)) == -1)
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
		if (ret >= 0)
			ant = ret;
	}*/
	if ((ant = lm_parseur(sommet)) == -1)
	{
		write(1, "ERROR\n", 6);
		lm_free_hashtable(sommet);
		ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
		sleep(150);
		return (0);
	}

	print_all_hashtable(sommet);
	lm_free_hashtable(sommet);
	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
	sleep(150);
	return (0);
}
