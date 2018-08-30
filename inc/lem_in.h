/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:37:05 by jabt              #+#    #+#             */
/*   Updated: 2018/08/30 17:23:04 by galemair         ###   ########.fr       */
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

typedef	struct	s_input t_input;

struct		s_input
{
	char	*line;
	t_input	*next;
};

typedef struct		s_sommet
{
	char				*name;
	int					distance;
	int					visited;
	struct s_adj_list	*lst;
	struct s_sommet		*next;
	struct s_sommet		*queue;
}					t_sommet;

typedef struct	s_adj_list
{
	char				*name;
	struct s_adj_list	*next;
}				t_adj_list;

/*
**		lm_hash_algo.c
*/
int			lm_hash(char *str);

/*
**			lm_get_sommet.c
*/
t_sommet	*lm_get_sommet(t_sommet **sommet, char *needle);

/*
**		lm_hashtable_utils.c
*/
char		*lm_get_room_name(char *str);

/*
**		lm_hashtable_core.c
*/
int			lm_add_end(t_sommet **sommet, char *str);
int			lm_add_start(t_sommet **sommet, char *str);

/*
**		lm_free_hashtable.c
*/
void		lm_free_hashtable(t_sommet **hashtab);

/*
** 		lm_free_adj_lst.c
*/
void		lm_free_adj_list(t_adj_list *adj_list);

/*
**		lm_manip_adj_lst.c
*/
int			lm_add_tube(t_sommet **sommet, char *pattern);

/*
**		lm_manip_sommet_lst.c
*/
int			lm_add_start_end(t_sommet **sommet, int index);
int			lm_add_sommet(t_sommet **sommet, char *str);

/*
**		lm_parseur.c
*/
int			lm_parseur(t_sommet **sommet);
int			lm_parse_room(t_sommet **sommet, char *line);
int			lm_parse_tube(t_sommet **sommet, char *line);

/*
**		lm_parsing_utils.c
*/
int			lm_parse_digit(char *ligne);	
int			lm_parse_ant(char *ligne);
/*
**		lm_manage_input.c
*/

t_input		*stock_input(void);
int			get_line(char **line, t_input *input, int start);
void		freeanddisplay_input(t_input *input);

/*
**		lm_verif_format.c	
*/
int			lm_is_good_room(char *room);
int			lm_verif_tube(char *str);

/*
 * 		queue function
 */

t_sommet	*exit_queue(t_sommet **queue);
void		add_in_queue(t_sommet **queue, t_sommet *to_add);

/*
 * 		algo
 */

void		lm_queue_neighbor(t_sommet *head, t_sommet **queue, t_sommet **sommet);
int			get_distance(t_sommet **sommet, t_sommet **queue);
int			lm_start_algo(t_sommet **sommet, int ants);


/*
 *	debug ou temporaire
 */

int			lm_add_start(t_sommet **sommet, char *str);
int			lm_add_end(t_sommet **sommet, char *str);
void		print_sommet(t_sommet *sommet);
void		print_hashtable(t_sommet **sommet);
void		print_all_hashtable(t_sommet **sommet);

#endif
