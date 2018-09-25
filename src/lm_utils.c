/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:15:42 by jabt              #+#    #+#             */
/*   Updated: 2018/09/24 10:39:12 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** 	here just to recup number of ant
*/

int			lm_parse_ant(char *ligne)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (ligne[i])
	{
		if (ligne[i] && (ligne[i] >= '0' && ligne[i] <= '9'))
			ret = (ret * 10) + ligne[i] - '0';
		else
			return (-1);
		i++;
	}
	if (ret <= 0)
		return (-1);
	return (ret);
}

void		lm_swap_ptr(void **first_ptr, void **second_ptr)
{
	void	*tmp;

	tmp = *first_ptr;
	*first_ptr = *second_ptr;
	*second_ptr = tmp;
}

/*
**		print_all ant in one go when start and end are connected
*/

void		lm_print_all_ants(char *end, int ants)
{
	int		i;

	i = 0;
	while (i < ants)
	{
		ft_printf("%d-%s ", i, end);
		i++;
	}
	ft_printf("\n");
}
