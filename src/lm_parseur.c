/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:58:27 by jabt              #+#    #+#             */
/*   Updated: 2018/06/20 15:16:04 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_handle_command(t_sommet **sommet, char *ligne)
{
	if (ligne[1] == '#')
	{
		if (ft_strequ(&ligne[2], "start"))
			lm_add_start_end(sommet, 0);
		else if (ft_strequ(&ligne[2], "end"))
			lm_add_start_end(sommet, 1);
	}
	return (1);
}

int		lm_parse_tube(t_sommet **sommet, char *ligne)
{
//	char	*tmp;
	int		ret;
/*	if (lm_verif_tube(ligne) == -1)
		return (-1);*/
	if (lm_add_tube(sommet, ligne) == -1)
		return (-1);
	while (get_next_line(0, &ligne))
	{
		if (lm_add_tube(sommet, ligne) == -1)
			return (-1);
		free(ligne);
	}
	return (1);
}

int		lm_parse_room(t_sommet **sommet, char *ligne)
{
	char	*ptr;
	//int		ret;///// vraiment utile ?
	
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
		else
		{
			if (lm_parse_tube(sommet, ligne) == -1)
			{
			//	free(ligne);
				return (-1);
			}
		}
	}
	// peut etre verif que les sommets sont bons
	return (1);
}

int		lm_parseur(t_sommet **sommet)
{
	int		ret;
//	int		tmp;
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
		{
			free(ligne);
			return (-1);
		}
		/*if (lm_parse_room(sommet, ligne) == -1)
			return (-1);*/
		free(ligne);
	}
	return (ret);
}
