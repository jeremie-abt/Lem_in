/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hash_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:44:07 by jabt              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/06/15 12:32:58 by jabt             ###   ########.fr       */
=======
/*   Updated: 2018/06/15 14:22:07 by galemair         ###   ########.fr       */
>>>>>>> origin/gdev1.1
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_hash(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
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
