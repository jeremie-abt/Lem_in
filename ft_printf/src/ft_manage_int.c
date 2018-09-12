/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:42:30 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:05:30 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_manage_signed_int(va_list *ap, t_percent *f, char *buffer,
		int *j)
{
	intmax_t	container;

	if (f->type == 'D')
	{
		container = (long int)va_arg(*ap, long int);
		return (ft_putsignednb_inbuf(f, buffer, j, container));
	}
	if (*f->size)
	{
		if (*(f->size + 1) == 'h')
			container = (char)va_arg(*ap, int);
		else if (*f->size == 'h')
			container = (short)va_arg(*ap, int);
		else if (*(f->size + 1) == 'l')
			container = (intmax_t)va_arg(*ap, long long int);
		else if (*f->size == 'l')
			container = (intmax_t)va_arg(*ap, long);
		else if (*f->size == 'z')
			container = (intmax_t)va_arg(*ap, ssize_t);
		else
			container = va_arg(*ap, intmax_t);
	}
	else
		container = (int)va_arg(*ap, int);
	return (ft_putsignednb_inbuf(f, buffer, j, container));
}

int		ft_manage_unsigned_int(va_list *ap, t_percent *f, char *buffer,
		int *j)
{
	uintmax_t	container;

	if (*f->size || f->type == 'U' || f->type == 'O')
		if ((*f->size == 'l' && !(*(f->size + 1))) || ft_strchr("UO", f->type))
			container = (unsigned long)va_arg(*ap, unsigned long);
		else if (*(f->size + 1) == 'h')
			container = (unsigned char)va_arg(*ap, unsigned int);
		else if (*f->size == 'h')
			container = (unsigned short)va_arg(*ap, unsigned int);
		else if (*(f->size + 1) == 'l')
			container = (unsigned long long)va_arg(*ap, unsigned long long);
		else if (*f->size == 'z')
			container = (size_t)va_arg(*ap, size_t);
		else
			container = va_arg(*ap, uintmax_t);
	else
		container = (unsigned int)va_arg(*ap, unsigned int);
	if (container == 0 && ((ft_strchr("xX", f->type))))
		ft_removeflag(f, '#');
	if ((ft_strchr("oO", f->type)) && container == 0 && f->precision != 0)
		ft_removeflag(f, '#');
	if (f->type == 'b')
		return ((ft_putbinaire_inbuf(f, buffer, j, container)));
	return ((ft_putunsignednb_inbuf(f, buffer, j, container)));
}
