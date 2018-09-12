/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:22:42 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:30:42 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_readstar(va_list *ap)
{
	int		ret;

	ret = va_arg(*ap, int);
	return (ret);
}

void			ft_checkflag(t_percent *f, char *sign, const char **c)
{
	char *tmp;

	if (**c)
	{
		tmp = NULL;
		if ((tmp = ft_strnchr(sign, **c, 5)))
		{
			if (*tmp == ' ' && !ft_strchr(f->flags, '+'))
				f->flags[ft_strlen(f->flags)] = ' ';
			else if (*tmp == '+' && (tmp = ft_strchr(f->flags, ' ')))
				*tmp = '+';
			else if (!(ft_strchr(f->flags, **c)))
				f->flags[ft_strlen(f->flags)] = **c;
			{
				(*c)++;
				return ;
			}
		}
		return ;
	}
}

void			ft_checkwidth(t_percent *f, va_list *ap, const char **format)
{
	if (**format)
	{
		if (**format == '0')
			return ;
		if (**format == '*')
		{
			(*format)++;
			f->width = (ft_readstar(ap));
			if (f->width < 0)
			{
				ft_addflag(f, '-');
				f->width *= -1;
			}
			return ;
		}
		if (**format > '0' && **format <= '9')
			f->width = 0;
		while (**format >= '0' && **format <= '9')
		{
			f->width = 10 * f->width + (**format - '0');
			(*format)++;
		}
	}
}

void			ft_checkprecision(t_percent *f, va_list *ap,
		const char **format)
{
	if (**format)
	{
		if (**format && **format != '.')
			return ;
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			f->precision = (ft_readstar(ap));
			if (f->precision < 0)
				f->precision = -1;
			return ;
		}
		f->precision = 0;
		while (**format >= '0' && **format <= '9')
		{
			f->precision = (10 * f->precision) + (**format - '0');
			(*format)++;
		}
	}
}

void			ft_checksize(t_percent *f, const char **format, char *sign)
{
	char	*tmp;

	if (**format)
	{
		tmp = NULL;
		if ((tmp = ft_strnchr(sign, **format, 4)))
		{
			if (*tmp == 'h' || *tmp == 'l' || *tmp == 'j' || *tmp == 'z')
			{
				if ((*tmp == 'h' || *tmp == 'l') && *tmp == format[0][1])
				{
					f->size[0] = *tmp;
					f->size[1] = *tmp;
					*format = *format + 2;
					return ;
				}
				f->size[0] = *tmp;
				f->size[1] = '\0';
				(*format)++;
				return ;
			}
		}
	}
}
