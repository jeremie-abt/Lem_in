/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_quit_properly_resid_graph.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:45:57 by jabt              #+#    #+#             */
/*   Updated: 2018/09/18 18:25:56 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 	PROCEDURE
**	quit properly the function lm_copy_hashtable
*/

t_sommet		**lm_quit_properly_copy_graph(t_sommet **resid_graph)
{
	lm_free_resid_graph(resid_graph);
	free(resid_graph);
	return (NULL);
}
