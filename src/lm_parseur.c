/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:11:37 by galemair          #+#    #+#             */
/*   Updated: 2018/09/20 16:23:31 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			lm_handle_command(t_sommet **graph, char *line)
{
	int	return_value;


	if (line[1] == '#')
	{
		if (ft_strequ(&line[2], "start"))
		{
			if ((return_value = lm_add_start_end(graph, 0)) < 0)
				return (return_value);
		}
		else if (ft_strequ(&line[2], "end"))
		{
			if ((return_value = lm_add_start_end(graph, 1)) < 0)
				return (return_value);
		}
	}
	return (1);
}

int					lm_parse_room(t_sommet **graph, char *line)
{
	int	mp_flag;

	mp_flag = 1;
	if (*line == '#' && (mp_flag = lm_handle_command(graph, line)) > -1)
		;
	else if (lm_is_good_room(line) != -1)
		mp_flag = lm_add_sommet(graph, line);
	else if (lm_verif_tube(line) != -1)
		mp_flag = lm_add_tube(graph, line);
	else
		return (-1);
	return (mp_flag);
}

int					lm_parseur(t_sommet **graph)
{
	int		ants;
	char	*line;
	t_input	*input;
	int		return_value;

	if (stock_input(&input) == -2)
	{
		free_input(input);
		return (-2);
	}
	get_line(&line, input, 1);
	while (line[0] == '#')
		get_line(&line, input, 0);
	if ((ants = lm_parse_ant(line)) == -1)
	{
		freeanddisplay_input(input);
		return (-1);
	}
	while (get_line(&line, input, 0))
	{
		if ((return_value = lm_parse_room(graph, line)) == -1 &&
			graph[0] && graph[1])
		{
			if (lm_find_shortest_distinct_path(graph, ants) > 0)
			{
				freeanddisplay_input(input);
				return (ants);
			}
			free_input(input);
			return (-1);
		}
		if (return_value == -1)
		{
			freeanddisplay_input(input);
			return (-1);
		}
		else if (return_value == -2)
		{
			free_input(input);
			return (-2);
		}
	}
	freeanddisplay_input(input);
	if (!graph[0] || !graph[1])
		return (-1);
	return (ants);
}
