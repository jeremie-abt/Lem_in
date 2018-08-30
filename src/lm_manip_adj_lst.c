/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_manip_adj_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:40:21 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 18:10:28 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int		lm_add_neighbor(t_sommet *first_sommet, t_sommet *second_sommet, 
		char *first_neighbor, char *second_neighbor)
{
	t_adj_list		*tmp;
	//t_adj_list		*new;

	tmp = first_sommet->lst;
	if (!(first_sommet->lst = malloc(sizeof(t_adj_list))))
		return (-1);
	first_sommet->lst->next = tmp;
	first_sommet->lst->name = first_neighbor;
	
	
	tmp = second_sommet->lst;
	if (!(second_sommet->lst = malloc(sizeof(t_adj_list))))
	{
		lm_free_adj_list(first_sommet->lst); // atention fonction pour free une list
		return (-1);
	}
	second_sommet->lst->next = tmp;
	second_sommet->lst->name = second_neighbor;
	return (1);
}

int				lm_add_tube(t_sommet **sommet, char *pattern)
{
	char		*second;
	char		*first;
	t_sommet	*first_sommet;
	t_sommet	*second_sommet;

	second = ft_strchr(pattern, '-') + 1;
	if (!(first = ft_strsub(pattern, 0, (second - pattern) - 1)))
	{
		return (-1);
	}
	if (!(second = ft_strdup(second)))
	{
		free(first);
		return (-1);
	}
//	key = lm_hash(first);
//	printf("%s\n", first);
//	printf("%s\n", second);
	if (!(first_sommet = lm_get_sommet(sommet, first)) ||
			!(second_sommet = lm_get_sommet(sommet, second)))
	{
		free(second);
		free(first);
		return (-1);
	}
	lm_add_neighbor(first_sommet, second_sommet, second, first);
/*	printf("first_sommet : %s\n", first_sommet->name);
	printf("son new voisin : %s\n", first_sommet->lst->name);
	printf("second_sommet : %s\n", second_sommet->name);
	printf("son new voisin : %s\n", second_sommet->lst->name);*/
//	lm_add_meighbor(sommet[key]);
	//free(first);
	return (1);
}
