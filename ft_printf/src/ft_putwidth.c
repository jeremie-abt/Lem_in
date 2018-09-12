/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:29:10 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:08:20 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_putsign(char *buffer, t_percent *f, int *j)
{
	if (f->intinfo->sign == 'x' || f->intinfo->sign == 'X')
	{
		ft_putc_inbuf(buffer, '0', j);
		ft_putc_inbuf(buffer, f->type, j);
		f->intinfo->sign = '\0';
		return (2);
	}
	else
	{
		ft_putc_inbuf(buffer, f->intinfo->sign, j);
	}
	f->intinfo->sign = '\0';
	return (1);
}

/*
**		putwidth_int don't return the length of the width
**		but the length of the sign
**		for instance if there's a - or + to print it return 1
**		if there's 0x to print it return 2
*/

int				ft_putwidth_int(char *buffer, t_percent *f, int *j)
{
	char	c;
	int		ret;

	ret = 0;
	if ((ft_strchr(f->flags, '0')) && !(ft_strchr(f->flags, '-'))
			&& f->precision == -1 && f->type != 'b')
		c = '0';
	else
		c = ' ';
	if (f->precision == -1 && !(ft_strchr(f->flags, '-')) && c == '0'
		&& (f->intinfo->sign))
	{
		ret = ft_putsign(buffer, f, j);
	}
	while (f->width > 0)
	{
		ft_putc_inbuf(buffer, c, j);
		f->width--;
	}
	if (f->intinfo->sign && !ft_strchr(f->flags, '-'))
	{
		ret = ft_putsign(buffer, f, j);
	}
	return (ret);
}

void			ft_putwidth(char *buffer, t_percent *f, int *j)
{
	char	c;

	if ((ft_strchr(f->flags, '0')) && !(ft_strchr(f->flags, '-')))
		c = '0';
	else
		c = ' ';
	while (f->width-- > 0)
	{
		ft_putc_inbuf(buffer, c, j);
	}
}
