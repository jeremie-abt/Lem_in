/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:51:11 by jabt              #+#    #+#             */
/*   Updated: 2018/06/05 18:46:23 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			printf("HEAD %d : %s\n", i, sommet[i]->name);
		i++;
	}
}
