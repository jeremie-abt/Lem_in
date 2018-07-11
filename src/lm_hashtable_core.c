/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:29:35 by jabt              #+#    #+#             */
/*   Updated: 2018/07/11 15:52:45 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_sommet		*lm_copy_node(t_sommet *src)
{
	t_sommet	*dst;

	if (!(dst = malloc(sizeof(t_sommet))))
		return (NULL);
	else
		ft_memcpy((void *)dst, (void *)src, sizeof(t_sommet));
	return (dst);
}
/*
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
*/
t_sommet				*lm_double_node(t_sommet **sommet, t_sommet *dst,
		t_sommet *src)
{
	t_sommet	*ret;
	t_sommet	*tmp;

	if (dst)
	{
		;	// attention a ca meme si je pense le patch dans la fonction appelante
		// rapelle toi en
	}
	if (!(ret = lm_copy_node(src)))
		return (NULL);
	tmp = ret;
	if (!(ret->lst = lm_create_inlst(sommet, src)) ||
			lm_add_node_lst(&ret->lst, src->name) == -1)
	{
		free(ret);
		return (NULL);
	}
	if (!(ret = lm_copy_node(src)))
	{
		free(tmp);
		return (NULL);
	}
	if (!(ret->lst = lm_create_outlst(sommet, src)) ||
			lm_add_node_lst(&ret->lst, src->name) == -1)
	{
		free(tmp);
		free(ret);
		return (NULL);
	}
	tmp->next = ret;
	tmp->next->next = dst;
	return (tmp);
}
