/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int_inbuf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:23 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 14:16:37 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_putmynb(char *buffer, char c, t_percent *f, int *j)
{
	if (c <= '9')
		ft_putc_inbuf(buffer, c, j);
	else
		ft_putc_inbuf(buffer, (c - '0' - 10) + (f->type - 23), j);
}

void			ft_add_unsigned_len(t_percent *f, uintmax_t *nb,
		uintmax_t *div)
{
	uintmax_t		stock;

	*div = 1;
	while ((stock = *nb / *div) >= (unsigned)f->intinfo->base)
	{
		*div = *div * f->intinfo->base;
		f->intinfo->len++;
	}
	if (*nb == 0 && f->precision == 0)
		f->intinfo->len--;
}

int				ft_putunsignednb_inbuf(t_percent *f, char *buffer,
		int *j, uintmax_t nb)
{
	uintmax_t		div;
	char			c;
	int				ret;

	ft_init_int_struct(f);
	ft_add_unsigned_len(f, &nb, &div);
	ft_add_widthandpre_toint(f);
	ret = f->intinfo->len + f->width;
	ret += (f->precision > 0) ? f->precision : 0;
	if (f->width > 0 && !(ft_strchr(f->flags, '-')))
		ret += ft_putwidth_int(buffer, f, j);
	if (f->intinfo->sign && ((f->intinfo->sign == '0' && f->precision < 1)
				|| f->intinfo->sign != '0'))
		ret += ft_putsign(buffer, f, j);
	if (f->precision > 0)
		ft_putprecision_forint(buffer, f, j);
	while (f->intinfo->len--)
	{
		c = (((nb / div) % f->intinfo->base) + '0');
		ft_putmynb(buffer, c, f, j);
		div = div / f->intinfo->base;
	}
	if (f->width > 0 && (ft_strchr(f->flags, '-')))
		ft_putwidth_int(buffer, f, j);
	return (ret);
}
