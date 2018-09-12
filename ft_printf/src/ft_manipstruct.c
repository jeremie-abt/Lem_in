/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:10:20 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 14:16:18 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_addflag(t_percent *f, char c)
{
	int		i;

	i = 0;
	while (f->flags[i] && f->flags[i] != c)
		i++;
	if (i < 5)
		f->flags[i] = c;
}

void			ft_removeflag(t_percent *f, char c)
{
	int		i;

	i = 0;
	while (f->flags[i] != c && i < 5)
		i++;
	if (i < 5)
		ft_memmove(&f->flags[i], &f->flags[i + 1], 5 - i);
}

t_percent		*ft_initstruct(void)
{
	t_percent	*f;

	if (!(f = malloc(sizeof(t_percent))))
		return (NULL);
	ft_memset(f->flags, '\0', 6);
	f->width = 0;
	f->precision = -1;
	ft_memset(f->size, '\0', 3);
	f->type = 0;
	f->intinfo = NULL;
	return (f);
}

void			ft_init_int_struct(t_percent *f)
{
	t_formatint		*formatint;

	f->intinfo = malloc(sizeof(t_formatint));
	formatint = f->intinfo;
	formatint->len = 1;
	formatint->sign = '\0';
	formatint->base = 10;
	if (f->type == 'x' || f->type == 'X')
		formatint->base = 16;
	else if (f->type == 'o' || f->type == 'O')
		formatint->base = 8;
	else if (f->type == 'b')
	{
		formatint->base = 2;
		return ;
	}
	if ((ft_strchr(f->flags, '#')))
	{
		if (f->type == 'x' || f->type == 'X')
			formatint->sign = f->type;
		if ((f->type == 'o' || f->type == 'O'))
			formatint->sign = '0';
	}
}

void			ft_fillstruct(const char **format, va_list *ap, t_percent **f)
{
	char	*save;
	char	*sign;

	sign = "#+-0 hljzsSpdDioOuUxXcCb%";
	(*format)++;
	while (**format)
	{
		save = (char *)*format;
		ft_checkflag(*f, sign, format);
		ft_checkwidth(*f, ap, format);
		ft_checkprecision(*f, ap, format);
		ft_checksize(*f, format, &sign[5]);
		if (save == *format || (ft_strcarac(&sign[9], **format)))
		{
			(*f)->type = **format;
			(*format)++;
			return ;
		}
	}
	if (!**format)
		return (ft_memdel((void **)f));
}
