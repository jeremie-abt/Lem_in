/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:12:23 by jabt              #+#    #+#             */
/*   Updated: 2018/02/23 12:51:40 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/ft_printf.h"

void		ft_putprecision_forint(char *buffer, t_percent *f, int *j)
{
	if (f->type == 'b')
		f->precision = 0;
	while (f->precision > 0)
	{
		ft_putc_inbuf(buffer, '0', j);
		f->precision--;
	}
}
