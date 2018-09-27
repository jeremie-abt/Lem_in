/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:11:00 by jabt              #+#    #+#             */
/*   Updated: 2018/09/27 18:12:52 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lm_error_quit_properly(t_sommet **graph)
{
	write(1, "ERROR\n", 6);
	lm_free_hashtable(graph);
	while (1);
	exit(0);
}

static void		lm_quit_properly(t_sommet **graph)
{
	lm_free_hashtable(graph);
	while (1);
	exit(0);
}

int				main(void)
{
	t_parsing	datas;
	t_sommet	*graph[HASH_SIZE];

	ft_bzero(&datas, sizeof(t_parsing));
	ft_bzero(graph, HASH_SIZE * sizeof(t_sommet *));
	if (lm_parseur(graph, &datas) < 0)
		lm_error_quit_properly(graph);
	ft_printf("\n");
	if (graph[1]->prev == graph[0])
	{
		lm_print_all_ants(graph[1]->name, datas.ants);
		lm_quit_properly(graph);
	}
	if (lm_core_print_ants(graph, datas.ants, datas.path) == -1)
		lm_error_quit_properly(graph);
	lm_quit_properly(graph);
	return (0);
}
