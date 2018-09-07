/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:11:37 by galemair          #+#    #+#             */
/*   Updated: 2018/09/07 15:11:36 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_handle_command(t_sommet **graph, char *line)
{
	if (line[1] == '#')
	{
		if (ft_strequ(&line[2], "start"))
			lm_add_start_end(graph, 0);
		else if (ft_strequ(&line[2], "end"))
			lm_add_start_end(graph, 1);
	}
	return (1);
}

int					lm_parse_room(t_sommet **graph, char *line)
{
	int	mp_flag;

	mp_flag = 1;
	if (*line == '#' && (mp_flag = lm_handle_command(graph, line)) != -1)
		;
	else if (lm_is_good_room(line) != -1)
		mp_flag = lm_add_sommet(graph, line);
	else if (lm_verif_tube(line) != -1)
		mp_flag = lm_add_tube(graph, line);
	else
		return (-1);
	if (mp_flag == -1)
		return (-1);
	return (1);
}

int					lm_parseur(t_sommet **graph)
{
	int		ants;
	char	*line;
	t_input	*input;

	stock_input(&input);
	get_line(&line, input, 1);
	while (line[0] == '#')
		get_line(&line, input, 0);
	if ((ants = lm_parse_ant(line)) == -1)
		return (-1);
	while (get_line(&line, input, 0))
	{
		if (lm_parse_room(graph, line) == -1)
		{
		//	if (lm_find_max(graph) > 0)
		//	{
		//		freeanddisplay(input);
		//		return (ants);
		//	}
			return (-1);
		}
	}
	freeanddisplay_input(input);
	return (ants);
}
