/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_carac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:57:59 by jabt              #+#    #+#             */
/*   Updated: 2018/02/21 12:59:07 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_manage_char(va_list *ap, t_percent *f, char *buffer, int *j)
{
	wchar_t		container;

	container = (wchar_t)va_arg(*ap, wint_t);
	if (f->type == 'C' || ((*f->size == 'l') && !*(f->size + 1)))
	{
		return (ft_put_wide_carac(&container, buffer, j));
	}
	else
		return (ft_putcarac(container, f, buffer, j));
	return (1);
}
