/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:29:35 by jabt              #+#    #+#             */
/*   Updated: 2018/07/10 17:08:27 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_sommet		*lm_copy_node(t_sommet *src)
{
	t_sommet	*dst;

	if (!(dst = malloc(sizeof(t_sommet))))
		return (NULL);
	else
		ft_memcpy((void *)dst, (void *)src, sizeof(t_sommet));
	return (dst);
}

t_sommet			**lm_copy_hashtable(t_sommet **src)
{
	t_sommet	**dst;
	int			i;

	i = 0;
	if (!(dst = malloc(HASH_SIZE * sizeof(t_sommet *))))
		return (NULL);
	ft_bzero(dst, HASH_SIZE * sizeof(t_sommet *));
	while (i < HASH_SIZE)
	{
		if (src[i] && !(dst[i] = lm_copy_node(src[i])))
			return (NULL);//attention au leaks encore et encore
		i++;
	}
	return (dst);
}
