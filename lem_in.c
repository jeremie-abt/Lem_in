/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 11:41:55 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int			i;
	t_adj_list	*adj_list[128];

	i = 1;
	lm_add_start();
	while (i < argc)
	{
		lm_add_hashmap(adj_list, argv[i]);
		i++;
	}
	return (0);
}
