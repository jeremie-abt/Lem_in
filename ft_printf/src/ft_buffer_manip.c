/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_manip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:07:24 by jabt              #+#    #+#             */
/*   Updated: 2018/02/26 10:29:59 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_putbuf(char *buffer, int *j)
{
	if (*j == BUFF_SIZE - 1)
		write(1, buffer, BUFF_SIZE - 1);
	else
		write(1, buffer, (*j));
}

void		ft_putc_inbuf(char *buffer, char c, int *j)
{
	if (*j == BUFF_SIZE)
	{
		ft_putbuf(buffer, j);
		ft_memset(buffer, '\0', BUFF_SIZE + 1);
		*j = 0;
		buffer[*j] = c;
		(*j)++;
	}
	else
	{
		buffer[*j] = c;
		(*j)++;
	}
}

void		ft_putstr_inbuf(char *buffer, char *str, int *j)
{
	int		ret;

	ret = ft_strlen(str);
	if ((ret + *j) < BUFF_SIZE)
	{
		ft_strncat(&buffer[*j], str, ret);
		*j += ret;
	}
	else
	{
		while (*str)
		{
			if (*j == BUFF_SIZE)
				ft_putc_inbuf(buffer, *str, j);
			else
			{
				buffer[*j] = *str;
				*j += 1;
			}
			str++;
		}
	}
}
