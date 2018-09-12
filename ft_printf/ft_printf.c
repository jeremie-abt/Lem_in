/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:31:29 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 12:29:57 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

static int		ft_handlebracket(const char **format, char *buffer, int *j)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if ((tmp = ft_transformcolor(format)))
	{
		ret = ft_strlen(tmp);
		ft_putstr_inbuf(buffer, tmp, j);
		return (ret);
	}
	else
	{
		ft_putc_inbuf(buffer, '{', j);
		(*format)++;
		return (1);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	char	buffer[BUFF_SIZE + 1];
	int		j;
	int		ret;

	ft_memset(buffer, '\0', BUFF_SIZE + 1);
	va_start(ap, format);
	j = 0;
	ret = 0;
	while (*format)
	{
		if (*format == '%')
			ret += ft_transformpercent(&format, &ap, buffer, &j);
		else if (*format == '{')
			ret += ft_handlebracket(&format, buffer, &j);
		else if (*format)
		{
			ft_putc_inbuf(buffer, *format, &j);
			format++;
			ret++;
		}
	}
	va_end(ap);
	ft_putbuf(buffer, &j);
	return (ret);
}
