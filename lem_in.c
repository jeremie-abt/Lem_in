/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 19:16:06 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int			i;
	int 		ret;
	t_sommet	*sommet[128];

	i = 3;
	
	lm_add_start(sommet, argv[1]);
	lm_add_end(sommet, argv[2]);
	print_sommet(sommet[0]);
	print_sommet(sommet[1]);

	while (i < argc)
	{
		ret = lm_add_sommet(sommet, argv[i]);
		i++;
	}
	return (0);
}
