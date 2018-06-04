/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:29:35 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 19:00:37 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// debut vraie fichier
/*
static int			lm_add_start_end(t_sommet **sommet, char *str)
{
	int	key;
	return (key);
}
*/
/*
 *			du tempo
 */

/*
 *		pour l'instant sommet[0] == start	sommet[1] == end
 */

int			lm_add_start(t_sommet **sommet, char *str)
{
	if (!(sommet[0] = malloc(sizeof(t_sommet))))
		return (0);
	ft_bzero(sommet[0], sizeof(t_sommet));
	sommet[0]->name = str;
	return (1);
}

int			lm_add_end(t_sommet **sommet, char *str)
{
	if (!(sommet[1] = malloc(sizeof(t_sommet))))
		return (0);
	ft_bzero(sommet[1], sizeof(t_sommet));
	sommet[1]->name = str;
	return (1);
}
