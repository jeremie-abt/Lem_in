/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:58:27 by jabt              #+#    #+#             */
/*   Updated: 2018/06/05 18:46:19 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_handle_command(t_sommet **sommet, char *ligne)
{
	if (ligne[1] == '#')
	{
		if (ft_strequ(&ligne[2], "start"))
		{
			get_next_line(0, &ligne);
			if (lm_add_start(sommet, ligne) == -1)
				return (-1);
		}
		else if (ft_strequ(&ligne[2], "end"))
		{
			get_next_line(0, &ligne);
			if (lm_add_end(sommet, ligne) == -1)
				return (-1);
		}
	}
	return (1);
}

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

int		lm_parse_room(t_sommet **sommet, char *ligne)
{
	char	*ptr;
	
	if (*ligne == '#')
	{
		if (lm_handle_command(sommet, ligne) == -1)
			return (-1);
	}
	else
	{
		if (lm_is_good_room(ligne))
		{
			lm_add_sommet(sommet, ligne);
		}
	}
	// peut etre verif que les sommets sont bons
	return (1);
}

int		lm_parseur(t_sommet **sommet)
{
	int		ret;
	char	*ligne;

	get_next_line(0, &ligne);
	if ((ret = lm_parse_ant(ligne)) == -1)
	{
		free(ligne);
		return (-1);
	}
	free(ligne);
	while (get_next_line(0, &ligne))
	{
		if (lm_parse_room(sommet, ligne) == -1)
			return (-1);
		free(ligne);
	}
	return (ret);
}
