/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parseur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:11:37 by galemair          #+#    #+#             */
/*   Updated: 2018/09/27 18:42:22 by galemair         ###   ########.fr       */
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
	int			mp_flag;
	static int	room = 0;

	mp_flag = 1;
	if (*line == '#' && (mp_flag = lm_handle_command(graph, line)) > -1)
		;
	else if (room == 0 && lm_is_good_room(line) != -1)
		mp_flag = lm_add_sommet(graph, line);
	else if (lm_verif_tube(line) != -1)
	{
		room = 1;
		mp_flag = lm_add_tube(graph, line);
	}
	else
		return (-1);
	return (mp_flag);
}

static int			lm_get_input(t_input **input)
{
	int ret;

	ret = stock_input(input);
	if (ret < 0)
		freeanddisplay_input(*input, DISPLAY_MAP);
	return (ret);
}

int					lm_parseur(t_sommet **graph, t_parsing *datas)
{
	char	*line;
	t_input	*input;
	int		return_value;

	if (lm_get_input(&input) < 0)
		return (-2);
	get_line(&line, input, 1);
	while (line[0] == '#')
		get_line(&line, input, 0);
	if ((datas->ants = lm_get_ants(line, input)) == -1)
		return (-1);
	if ((return_value = lm_parser_main_loop(graph, input, datas)) < 0)
		return (return_value);
	if (return_value == -3)
		return (1);
	if (!graph[0] || !graph[1] || ((datas->path = lm_find_best_flow(graph, datas->ants)) <= 0))
	{
		freeanddisplay_input(input, DISPLAY_MAP);
		return (-1);
	}
	freeanddisplay_input(input, 1);
	return (1);
}
