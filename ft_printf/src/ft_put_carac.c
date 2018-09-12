/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:42:30 by jabt              #+#    #+#             */
/*   Updated: 2018/02/23 12:50:40 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**		underneath's this byte-length :
**		11110XXX 10XXXXXX 10XXXXXX 10XXXXXX
*/

static int		ft_put_fourbyte_carac(char *buffer, int *j, wchar_t *container)
{
	unsigned char	c;
	wchar_t			swap;

	swap = *container;
	container = &swap;
	c = ((*container) >> 18) + 240;
	ft_putc_inbuf(buffer, c, j);
	(*container) = ((*container) & 262143);
	c = ((*container) >> 12) + 128;
	ft_putc_inbuf(buffer, c, j);
	(*container) = ((*container) & 4095);
	c = ((*container) >> 6) + 128;
	ft_putc_inbuf(buffer, c, j);
	(*container) = ((*container) & 63);
	c = (*container) + 128;
	ft_putc_inbuf(buffer, c, j);
	return (4);
}

/*
** 			underneath's this length :
**			1110XXXX 10XXXXXX 10XXXXXX
*/

static int		ft_put_threebyte_carac(char *buffer, int *j, wchar_t *container)
{
	unsigned char	c;
	wchar_t			swap;

	swap = *container;
	container = &swap;
	c = ((*container) >> 12) + 224;
	ft_putc_inbuf(buffer, c, j);
	(*container) = ((*container) & 4095);
	c = ((*container) >> 6) + 128;
	ft_putc_inbuf(buffer, c, j);
	(*container) = ((*container) & 63);
	c = (*container) + 128;
	ft_putc_inbuf(buffer, c, j);
	return (3);
}

/*
**	 		underneath's this length :
**			110XXXXX 10XXXXXX
*/

static int		ft_put_twobyte_carac(char *buffer, int *j, wchar_t *container)
{
	unsigned char	c;
	wchar_t			swap;

	swap = *container;
	container = &swap;
	c = ((*container) >> 6) + 192;
	ft_putc_inbuf(buffer, c, j);
	(*container) = ((*container) & 63);
	c = (*container) + 128;
	ft_putc_inbuf(buffer, c, j);
	return (2);
}

int				ft_put_wide_carac(wchar_t *container, char *buffer, int *j)
{
	if (MB_CUR_MAX == 4 && (*container) <= 2097151 && (*container) >= 65536)
		return (ft_put_fourbyte_carac(buffer, j, container));
	else if (MB_CUR_MAX == 4 && (*container) <= 65535 && (*container) >= 2048)
		return (ft_put_threebyte_carac(buffer, j, container));
	else if (MB_CUR_MAX == 4 && (*container) <= 2047 && (*container) >= 128)
		return (ft_put_twobyte_carac(buffer, j, container));
	else if ((*container) <= 255)
	{
		ft_putc_inbuf(buffer, (*container), j);
		return (1);
	}
	return (-1);
}

int				ft_putcarac(char c, t_percent *f, char *buffer, int *j)
{
	int		ret;

	f->width--;
	ret = f->width;
	f->precision = 0;
	if (f->width <= 0)
	{
		ft_putc_inbuf(buffer, c, j);
		return (1);
	}
	else
	{
		if (!(ft_strchr(f->flags, '-')))
			ft_putwidth(buffer, f, j);
		ft_putc_inbuf(buffer, c, j);
		if (f->width > 0)
			ft_putwidth(buffer, f, j);
	}
	return (ret + 1);
}
