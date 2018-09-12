/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:29:10 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:03:31 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ft_printf.h"

/*
**		i'm adding the real width and precision with the two funs underneath
*/

static void			ft_add_pre(t_percent *f)
{
	int		tmppre;

	tmppre = f->precision;
	if (f->precision <= -1)
	{
		f->precision = -1;
		tmppre = 0;
	}
	if (f->precision > 0)
		f->precision = tmppre - f->intinfo->len;
	if (tmppre == f->intinfo->len)
		f->precision = -1;
}

void				ft_add_widthandpre_toint(t_percent *f)
{
	int		sign;

	sign = 0;
	if (f->intinfo->sign == ' ' || f->intinfo->sign == '-'
		|| f->intinfo->sign == '+' || f->intinfo->sign == '0')
	{
		sign = 1;
	}
	else if (f->intinfo->sign == 'x' || f->intinfo->sign == 'X')
		sign = 2;
	if (f->precision > f->intinfo->len)
		f->width -= f->precision + sign;
	else
		f->width -= f->intinfo->len + sign;
	if (f->width < 0)
		f->width = 0;
	ft_add_pre(f);
}

int					ft_turninto_fourbytes_precision(t_percent *f, wchar_t *str,
		int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && j < f->precision)
		if (str[i] > 65535)
		{
			j += 4;
			len -= (j <= f->precision) ? 3 : 0;
		}
		else if (str[i] > 2047)
		{
			j += 3;
			len -= (j <= f->precision) ? 2 : 0;
		}
		else if (str[i++] > 127)
		{
			j += 2;
			len -= (j <= f->precision) ? 1 : 0;
		}
		else
			j++;
	return (len);
}

/*
**		fourbytespre = precision turn into one byte precision
**		for instance Í = just 1 instead of 2;
**		but i let my real precision into f->precision for the result
**		so fourbytespre is used for print the good number of carac
**		when f->precisions is used for calculate the return of my function
*/

int					ft_add_widthandpre_towchar(t_percent *f, wchar_t *str,
		int len)
{
	int		fourbytespre;

	fourbytespre = ft_turninto_fourbytes_precision(f, str, len);
	f->width -= (f->precision >= 0 && f->precision < len) ? f->precision : len;
	return (fourbytespre);
}
