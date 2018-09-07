/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manage_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:17:06 by galemair          #+#    #+#             */
/*   Updated: 2018/09/04 16:02:49 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	freeanddisplay_input(t_input *input)
{
	t_input	*tmp;

	while (input)
	{
		printf("%s\n", input->line);
		tmp = input;
		input = input->next;
		free(tmp);
	}
}

int		get_line(char **line, t_input *input, int start)
{
	static t_input	*current_line;

	if (start)
		current_line = input;
	if (!current_line)
	{
		*line = NULL;
		return (0);
	}
	*line = current_line->line;
	current_line = current_line->next;
	return (1);
}

int		check_line_validity(char *str)
{
	int	mp_flag;

	if (*str == '#')
		;
	else if (lm_is_good_room(str) != -1)
		;
	else if (lm_verif_tube(str) != -1)
		;
	else
		return (-1);
	return (1);
}

int		stock_input(t_input **input)
{
	t_input	*tmp;
	char	*line;

	if ((*input = malloc(sizeof(t_input))) == NULL)
		return (-1);
	get_next_line(0, &((*input)->line));
	tmp = *input;
	while (get_next_line(0, &line))
	{
		if ((tmp->next = malloc(sizeof(t_input))) == NULL)
			return (-1);
		tmp = tmp->next;
		tmp->line = line;
		tmp->next = NULL;
		if (check_line_validity(line) == -1)
			return (-1);
	}
	return (1);
}
