/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:41:31 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:30:20 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_checkcarac(char *color)
{
	if (*color == 'B' && *(color + 1) == ':')
		color = color + 2;
	while (*color)
	{
		if (!(*color >= 'A' && *color <= 'Z') &&
			!(*color >= '0' && *color++ <= '9'))
			return (0);
		color++;
	}
	return (1);
}

static char		*ft_mallocbrace(const char **format)
{
	char	*tmp;
	int		length;
	char	*save;

	if (!(tmp = ft_strchr(*format + 1, '}')))
		return (NULL);
	if ((length = tmp - (*format + 1)) > 16)
		return (NULL);
	tmp = ft_strnew(length + 1);
	ft_strncpy(tmp, *format + 1, length);
	save = tmp;
	tmp = ft_strtrim(tmp);
	free(save);
	return (tmp);
}

int				*ft_givecolor(const char **format)
{
	char			*color;
	int				*ret;
	int				k;

	k = 0;
	if (!(color = ft_mallocbrace(format)) || !(ft_checkcarac(color)))
	{
		ft_strdel(&color);
		return (0);
	}
	ret = ft_findrightcolor(color);
	if (ret[1] == 0)
	{
		ft_strdel(&color);
		return (0);
	}
	while (**format != '}')
	{
		(*format)++;
	}
	(*format)++;
	ft_strdel(&color);
	return (ret);
}
