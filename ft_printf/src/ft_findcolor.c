/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:45:37 by jabt              #+#    #+#             */
/*   Updated: 2018/02/14 15:22:50 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_returncolorcode(char *color)
{
	enum e_color e_codecolor;

	e_codecolor = EOC;
	if (*color == 'B' && color[2] == 'A')
		e_codecolor = BLACK;
	else if (*color == 'R')
		e_codecolor = RED;
	else if (*color == 'G')
		e_codecolor = GREEN;
	else if (*color == 'Y')
		e_codecolor = YELLOW;
	else if (*color == 'B')
		e_codecolor = BLUE;
	else if (*color == 'M')
		e_codecolor = MAGENTA;
	else if (*color == 'C')
		e_codecolor = CYAN;
	return (e_codecolor);
}

int					*ft_findrightcolor(char *color)
{
	char			tabcolor[38];
	char			*tmp;
	int				*tab;

	tab = malloc(2 * sizeof(int));
	tab[1] = 0;
	tabcolor[37] = '\0';
	ft_strncpy(tabcolor, "BLACKREDGREENYELLOWBLUEMAGENTACYANEOC", 37);
	if (*color == 'B' && *(color + 1) == ':')
	{
		tab[1] = 10;
		color = color + 2;
	}
	tmp = ft_strstr(tabcolor, color);
	tab[0] = 0;
	if (!tmp && *color == 'B')
	{
		tab[0] = 1;
		tmp = ft_strstr(tabcolor, color + 1);
	}
	if (tmp)
		tab[1] += ft_returncolorcode(tmp);
	else
		tab[1] = 0;
	return (tab);
}
