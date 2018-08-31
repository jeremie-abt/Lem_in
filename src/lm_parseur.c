/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parseur.c                                       :+:      :+:    :+:   */
/*   lm_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:58:27 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 18:10:48 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_handle_command(t_sommet **sommet, char *line)
{
	if (line[1] == '#')
	{
		if (ft_strequ(&line[2], "start"))
			lm_add_start_end(sommet, 0);
		else if (ft_strequ(&line[2], "end"))
			lm_add_start_end(sommet, 1);
		else
			return (-1); // line beginning with ## are commands
	}
	return (1);
}


int		lm_parse_room(t_sommet **sommet, char *line)
{
	int	mp_flag;

	mp_flag = 1;
	if (*line == '#' && (mp_flag = lm_handle_command(sommet, line)) != -1)
		;
	else if (lm_is_good_room(line) != -1)
		mp_flag = lm_add_sommet(sommet, line);
	else if (lm_verif_tube(line) != -1)
		mp_flag = lm_add_tube(sommet, line);
	else
		return (-1);
	if (mp_flag == -1)
		return (-1);
	return (1);
}

int		lm_parseur(t_sommet **sommet)
{
	int		ants;
	char	*line;
	t_input	*input;

	input = stock_input();
	get_line(&line, input, 1);
	if ((ants = lm_parse_ant(line)) == -1)
		return (-1);
	while (get_line(&line, input, 0))
	{
		if (lm_parse_room(sommet, line) == -1)
		{
		//	if (lm_find_max(sommet) > 0)
		//	{
		//		freeanddisplay(input);
		//		return (ants);
		//	}
			return (-1);
		}
	}
	print_all_hashtable(sommet);
	exit (0);
	freeanddisplay_input(input);
	return (ants);
}
