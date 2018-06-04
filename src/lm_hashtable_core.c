/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:29:35 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 11:59:06 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// debut vraie fichier



/*
 *			du tempo
 */

/*
 *		pour l'instant adj_list[0] == start	adj_list[1] == end
 */

int			lm_add_start(t_adj_list **adj_list, char *str)
{
	if (!(adj_list[0] = lm_add_node_adj_lst(str)))
		return (NULL);
}

int			lm_add_end(t_adj_list **adj_list, char *str)
{
	if (!(adj_list[1] = lm_add_node_adj_lst(str)))
		return (NULL);
}
