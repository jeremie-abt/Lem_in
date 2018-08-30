/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_hashtable_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:52:59 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 17:24:13 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*lm_get_room_name(char *str)
{
	char	*room_name;
	int		length;

	room_name = ft_strchr(str, ' ');
	if (room_name)
	{
		length = room_name - str;
		if (!(room_name = ft_strsub(str, 0, length)))
			return (NULL);
		return (room_name);
	}
	else
		return (NULL);
}
