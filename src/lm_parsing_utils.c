/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:15:42 by jabt              #+#    #+#             */
/*   Updated: 2018/08/26 12:09:38 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 	here just for recup number of ant
 */

int		lm_parse_ant(char *ligne)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (ligne[i])
	{
		if (ligne[i] && (ligne[i] >= '0' && ligne[i] <= '9' ))
			ret = (ret * 10) + 	ligne[i] - '0';
		else
			return (-1);
		i++;
	}
	return (ret);
}

/*
 * 	here for parse a numbre like 1-5
 * 	first call'll return 1 and second 5
 */

int		lm_parse_digit(char *ligne)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (ligne[i])
	{
		if (ligne[i] && (ligne[i] >= '0' && ligne[i] <= '9' ))
			ret = (ret * 10) + 	ligne[i] - '0';
		else if (ligne[i] == '-' || !ligne[i])
			return (ret);
		else
			return (-1);
		i++;
	}
	return (ret);
}
