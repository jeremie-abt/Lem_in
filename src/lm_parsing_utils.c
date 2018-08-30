/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:15:42 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 11:48:23 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * 		read on the standart input one ligne, convert string
 * 		into numbers
 * 		return : -1 if the string is not at the good format
 * 		or number of ants
 */

int		lm_parse_ant(int *ants)
{
	char	*ligne;

	get_next_line(0, &ligne); // si ligne == NULL
	if (ligne)
	{
		*ants = ft_atoi(ligne);
		printf("%s\n", ligne);
		free(ligne);
	}
	else
		return (-1);
	return (1);
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
