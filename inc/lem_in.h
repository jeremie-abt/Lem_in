/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:37:05 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 19:16:14 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_sommet
{
	char				*name;
	int					distance;
	int					visited;
	struct s_adj_list	*lst;
	struct s_sommet		*next;
}					t_sommet;

typedef struct	s_adj_list
{
	char				*neighbor;
	struct s_adj_list	*next;
}				t_adj_list;

/*
** 	hashtable function
*/

int			lm_hash(char *str);
int			lm_add_hashmap(t_sommet **sommet, char *str);
int			lm_add_sommet(t_sommet **sommet, char *str);



/*
 *	debug ou temporaire
 */

int			lm_add_start(t_sommet **sommet, char *str);
int			lm_add_end(t_sommet **sommet, char *str);
void		print_sommet(t_sommet *sommet);

#endif
