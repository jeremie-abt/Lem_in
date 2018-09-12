/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbinaire_inbuf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:49:47 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:33:21 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_put_some_zero(char *buffer, size_t len, int *j)
{
	while (len-- > 0)
	{
		ft_putc_inbuf(buffer, '0', j);
	}
}

int				ft_putbinaire_inbuf(t_percent *f, char *buffer, int *j,
		uintmax_t nb)
{
	uintmax_t	div;
	int			space;
	int			ret;

	ret = 8;
	div = 1;
	ft_init_int_struct(f);
	ft_add_unsigned_len(f, &nb, &div);
	while (ret < f->intinfo->len)
		ret += 8;
	space = ret - f->intinfo->len + 1;
	if (f->intinfo->len < ret)
		ft_put_some_zero(buffer, ret - f->intinfo->len, j);
	while (div >= 1)
	{
		ft_putc_inbuf(buffer, (((nb / div) % 2) + '0'), j);
		if (space++ == 8 && div != 1)
		{
			ft_putc_inbuf(buffer, ' ', j);
			space = 1;
		}
		div = div / 2;
	}
	return (ret + ((ret / 8) - 1));
}
