/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:42:34 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 14:16:03 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_free(t_percent *f)
{
	if (f->intinfo)
		free(f->intinfo);
	if (f)
		free(f);
}

static void		ft_fill_tabfunc(t_conv *tabfunc)
{
	tabfunc[0].str = "OUXxuob";
	tabfunc[0].conv = &ft_manage_unsigned_int;
	tabfunc[1].str = "diD";
	tabfunc[1].conv = &ft_manage_signed_int;
	tabfunc[2].str = "cC";
	tabfunc[2].conv = &ft_manage_char;
	tabfunc[3].str = "p";
	tabfunc[3].conv = &ft_manage_addr;
	tabfunc[4].str = "s";
	tabfunc[4].conv = &ft_manage_string;
	tabfunc[5].str = "S";
	tabfunc[5].conv = &ft_manage_wide_string;
}

int				ft_transformpercent(const char **format, va_list *ap,
		char *buffer, int *j)
{
	t_percent		*f;
	int				i;
	static	t_conv	tabfunc[6];
	int				ret;

	ret = 0;
	i = -1;
	if (!tabfunc[0].str)
		ft_fill_tabfunc(tabfunc);
	f = ft_initstruct();
	ft_fillstruct(format, ap, &f);
	if (!f)
		return (0);
	while (++i < 6)
		if (ft_strcarac(tabfunc[i].str, f->type))
		{
			ret = tabfunc[i].conv(ap, f, buffer, j);
			ft_free(f);
			return (ret);
		}
	if (f->type)
		ret = ft_putcarac(f->type, f, buffer, j);
	ft_free(f);
	return (ret);
}

char			*ft_transformcolor(const char **format)
{
	char	*newstr;
	int		*ret;
	char	*tmp;

	ret = ft_givecolor(format);
	if (!ret)
		return (NULL);
	newstr = malloc(7 + 1);
	ft_memset(newstr, '\0', 8);
	if (ret[1] == EOC)
		ret[1] = 0;
	ft_strncpy(newstr, "\e[", 2);
	tmp = ft_itoa(ret[0]);
	ft_strcat(newstr, tmp);
	free(tmp);
	tmp = ft_itoa(ret[1]);
	ft_strcat(newstr, ";");
	ft_strcat(newstr, tmp);
	free(tmp);
	ft_strcat(newstr, "m");
	return (newstr);
}
