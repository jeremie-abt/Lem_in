/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:29:10 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:31:40 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ft_printf.h"

static void		ft_putmynb(char *buffer, intmax_t *nb, t_percent *f, int *j)
{
	int			sign;
	char		c;

	if (*nb < 0)
		sign = -1;
	else
		sign = 1;
	while (*f->intinfo->div >= 1 && f->intinfo->len--)
	{
		if (*f->intinfo->div == 1 && sign == -1)
			c = (*nb % -10) * -1 + '0';
		else
			c = (((*nb / (*f->intinfo->div)) * sign) % 10) + '0';
		ft_putc_inbuf(buffer, c, j);
		*f->intinfo->div = *f->intinfo->div / 10;
	}
}

static void		ft_addlen(t_percent *f, intmax_t *nb, intmax_t *div)
{
	intmax_t		stock;

	*div = 1;
	if (*nb < 0)
	{
		while (!((stock = *nb / *div) < 0 && stock >= -9))
		{
			*div = *div * 10;
			f->intinfo->len++;
		}
	}
	else
	{
		while (!((stock = *nb / *div) >= 0 && stock <= 9))
		{
			*div = *div * 10;
			f->intinfo->len++;
		}
	}
	if (*nb == 0 && f->precision == 0)
		f->intinfo->len--;
}

int				ft_putsignednb_inbuf(t_percent *f, char *buffer,
		int *j, intmax_t nb)
{
	intmax_t		div;
	char			*sign;
	int				ret;

	ft_init_int_struct(f);
	if (nb < 0)
		f->intinfo->sign = '-';
	else if ((sign = ft_strchr(f->flags, '+'))
			|| (sign = ft_strchr(f->flags, ' ')))
		f->intinfo->sign = *sign;
	f->intinfo->div = &div;
	ft_addlen(f, &nb, &div);
	ft_add_widthandpre_toint(f);
	ret = f->intinfo->len + f->width;
	ret += (f->precision > 0) ? f->precision : 0;
	if (f->width > 0 && !(ft_strchr(f->flags, '-')))
		ret += ft_putwidth_int(buffer, f, j);
	if (f->intinfo->sign && ret++)
		ft_putc_inbuf(buffer, f->intinfo->sign, j);
	if (f->precision > 0 || (nb == 0 && f->precision == 0))
		ft_putprecision_forint(buffer, f, j);
	ft_putmynb(buffer, &nb, f, j);
	if (f->width > 0)
		ft_putwidth_int(buffer, f, j);
	return (ret);
}
