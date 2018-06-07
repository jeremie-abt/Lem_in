/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_free_adj_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:07:35 by jabt              #+#    #+#             */
/*   Updated: 2018/06/07 11:20:39 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lm_free_adj_list(t_adj_list *adj_list)
{
	t_adj_list	*save;

	while (adj_list)
	{
		free(adj_list->name);
		save = adj_list;
		adj_list = adj_list->next;
		free(save);
	}
}
