/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parseur_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:12:54 by galemair          #+#    #+#             */
/*   Updated: 2018/09/27 18:48:14 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lm_get_ants(char *line, t_input *input)
{
	int ants;

	ants = lm_parse_ant(line);
	if (ants == -1)
		freeanddisplay_input(input, DISPLAY_MAP);
	return (ants);
}

int		lm_parser_main_loop(t_sommet **graph, t_input *input, t_parsing *datas)
{
	int		return_value;
	char	*line;

	while (get_line(&line, input, 0))
	{
		if ((return_value = lm_parse_room(graph, line)) == -1 &&
			graph[0] && graph[1])
		{
			if ((datas->path = lm_find_best_flow(graph, datas->ants)) > 0)
			{
				freeanddisplay_input(input, 1);
				return (2);
			}
		}
		if (return_value < 0)
		{
			freeanddisplay_input(input, DISPLAY_MAP);
			return (return_value);
		}
	}
	return (1);
}
