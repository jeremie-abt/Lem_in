/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_procedure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:54:06 by jabt              #+#    #+#             */
/*   Updated: 2018/09/12 13:52:25 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lm_free_adj_resid_graph_lst(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}

void			lm_free_adj_lst(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}

void			lm_free_adj_lst_resid_graph(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}
