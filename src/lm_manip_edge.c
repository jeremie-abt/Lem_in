/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:38:38 by jabt              #+#    #+#             */
/*   Updated: 2018/08/31 09:35:40 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adj_lst		*lm_get_edge(t_adj_lst *lst, char *str)
{
	while (lst)
	{
		if (ft_strequ(lst->name, str))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
