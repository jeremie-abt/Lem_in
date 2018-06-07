/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:37:05 by jabt              #+#    #+#             */
/*   Updated: 2018/06/07 11:20:31 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

# define HASH_SIZE 128

typedef struct		s_sommet
{
	char				*name;
	int					distance;
	int					visited;
	struct s_adj_list	*lst;
	struct s_sommet		*next;
	struct s_sommet		*file;
}					t_sommet;

typedef struct	s_adj_list
{
	char				*name;
	struct s_adj_list	*next;
}				t_adj_list;

/*
** 	hashtable function
*/

int			lm_hash(char *str);
int			lm_add_hashmap(t_sommet **sommet, char *str);
int			lm_add_sommet(t_sommet **sommet, char *str);
int			lm_add_start_end(t_sommet **sommet, int index);
t_sommet	*lm_get_sommet(t_sommet **sommet, char *needle);
void		lm_free_hashtable(t_sommet **hashtab);

/*
 * 		adjencency list function
 */

int			lm_add_tube(t_sommet **sommet, char *pattern);
void		lm_free_adj_list(t_adj_list *adj_list);

/*
 * 	parsing function
 */

int			lm_parse_ant(char *ligne);
int			lm_parse_digit(char *ligne);
int			lm_parseur(t_sommet **sommet);
int			lm_is_good_room(char *room);

/*
 * 	un peu d'utils
 */

char		*lm_get_room_name(char *str);
int			lm_verif_tube(char *str);

/*
 *	debug ou temporaire
 */

int			lm_add_start(t_sommet **sommet, char *str);
int			lm_add_end(t_sommet **sommet, char *str);
void		print_sommet(t_sommet *sommet);
void		print_hashtable(t_sommet **sommet);
void		print_all_hashtable(t_sommet **sommet);

#endif
