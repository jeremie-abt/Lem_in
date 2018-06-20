/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_adj_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:07:35 by jabt              #+#    #+#             */
/*   Updated: 2018/06/18 15:34:11 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lm_free_adj_lst(t_adj_lst *adj_lst)
{
	t_adj_lst	*save;

	while (adj_lst)
	{
		free(adj_lst->name);
		save = adj_lst;
		adj_lst = adj_lst->next;
		free(save);
	}
}