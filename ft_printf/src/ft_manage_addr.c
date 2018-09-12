/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:23:32 by jabt              #+#    #+#             */
/*   Updated: 2018/04/25 14:40:16 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_manage_addr(va_list *ap, t_percent *f, char *buffer,
		int *j)
{
	long unsigned int	container;

	ft_addflag(f, '#');
	container = (long unsigned int)va_arg(*ap, void *);
	f->type = 'x';
	return (ft_putunsignednb_inbuf(f, buffer, j, container));
}
