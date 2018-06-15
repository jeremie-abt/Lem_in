/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hash_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:44:07 by jabt              #+#    #+#             */
/*   Updated: 2018/06/14 18:45:47 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_hash(char *str, t_sommet *sommet)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (ft_strcmp(str, sommet[0].name) == 0)
		return (0);
	if (ft_strcmp(str, sommet[1].name) == 0)
		return (1);
	while (str[i])
	{
		ret += str[i];
		i++;
	}
	ret %= HASH_SIZE;
	if (ret == 0 || ret == 1)
		return (ret + 2);
	return (ret);
}

t_sommet	*lm_get_adress(char *str, t_sommet **sommet)
{
	int			index;
	t_sommet	*adress;

	index = lm_hash(str, *sommet);
	adress = sommet[index];
	while (ft_strcmp(adress->name, str) != 0)
		adress = adress->next;
	return (adress);
}
