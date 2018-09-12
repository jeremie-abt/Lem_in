/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:54:40 by jabt              #+#    #+#             */
/*   Updated: 2018/02/23 12:39:31 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_put_nullstring(char *buffer, t_percent *f, int *j)
{
	int		i;
	char	*nullstr;
	int		ret;

	nullstr = "(null)";
	i = 0;
	f->width -= (f->precision < 6 && f->precision != -1) ? f->precision : 6;
	f->precision = (f->precision >= 0 && f->precision < 6) ? f->precision : 6;
	ret = (f->width > 0) ? f->width + f->precision : f->precision;
	if (f->width > 0 && !(ft_strchr(f->flags, '-')))
		ft_putwidth(buffer, f, j);
	while (i < f->precision)
	{
		ft_putc_inbuf(buffer, nullstr[i], j);
		i++;
	}
	if (f->width > 0)
		ft_putwidth(buffer, f, j);
	return (ret);
}

int				ft_str_wide_len(wchar_t *str, t_percent *f)
{
	int		i;
	int		ret;
	int		j;

	j = 0;
	i = -1;
	ret = 0;
	while (str[++i] && (j < f->precision || f->precision == -1))
		if (str[i] > 65535 && (j += 4))
			ret += (j <= f->precision || f->precision == -1) ? 4 : 0;
		else if (str[i] > 2047 && (j += 3))
			ret += (j <= f->precision || f->precision == -1) ? 3 : 0;
		else if (str[i] > 127 && (j += 2))
			ret += (j <= f->precision || f->precision == -1) ? 2 : 0;
		else if (j <= f->precision || f->precision == -1)
		{
			j++;
			ret++;
		}
	return (ret);
}

int				ft_manage_wide_string(va_list *ap, t_percent *f,
		char *buffer, int *j)
{
	int			ret;
	wchar_t		*str;
	int			i;
	int			fourbytespre;

	i = 0;
	str = va_arg(*ap, wchar_t *);
	if (!str)
		return (ft_put_nullstring(buffer, f, j));
	ret = ft_str_wide_len(str, f);
	fourbytespre = ft_add_widthandpre_towchar(f, str, ret);
	f->precision = ret;
	ret += (f->width > 0) ? f->width : 0;
	if (f->width > 0 && !(ft_strchr(f->flags, '-')))
		ft_putwidth(buffer, f, j);
	while (str[i] && fourbytespre-- > 0)
		ft_put_wide_carac(&str[i++], buffer, j);
	if (f->width > 0)
		ft_putwidth(buffer, f, j);
	return (ret);
}

int				ft_manage_string(va_list *ap, t_percent *f,
		char *buffer, int *j)
{
	int		i;
	char	*str;
	int		ret;

	i = 0;
	if (*f->size == 'l' && !*(f->size + 1))
		return (ft_manage_wide_string(ap, f, buffer, j));
	str = va_arg(*ap, char *);
	if (!str)
		return (ft_put_nullstring(buffer, f, j));
	ret = ft_strlen(str);
	if (f->precision == -1)
		f->precision = ret;
	if (f->precision >= 0 && f->precision < ret)
		ret = f->precision;
	f->width -= ret;
	ret = (f->width > 0) ? ret + f->width : ret;
	if (f->width > 0 && !(ft_strchr(f->flags, '-')))
		ft_putwidth(buffer, f, j);
	while (str[i] && f->precision-- > 0)
		ft_putc_inbuf(buffer, str[i++], j);
	if (f->width > 0)
		ft_putwidth(buffer, f, j);
	return (ret);
}
