/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_verif_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:42:46 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 17:24:22 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
//#include <stdio.h>
//#include <ctype.h>

int		lm_is_good_room(char *room)
{
	int		i;

	i = 0;
	if (*room == 'L')
		return (-1);
	while (*room && *room != ' ')
		room++;
	while (*room)
	{
		if (*room == ' ')
			i++;
		else if (!ft_isdigit(*room))
			return (-1);
		room++;
	}
	if (i == 2)
		return (1);
	return (-1);
}

int			lm_verif_tube(char *str)
{	
	int		i;
	int		state;

	state = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			state++;
		i++;
	}
	if (state != 1)
		return (-1);
	return (1);
}
//int	main(int argc, char **argv)
//{
//	printf("%d\n", lm_is_good_room(argv[1]));
//	return(0);
//}
