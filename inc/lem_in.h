/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:37:05 by jabt              #+#    #+#             */
/*   Updated: 2018/09/12 15:02:01 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "assert.h"

# define HASH_SIZE 128

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_input;

typedef struct		s_sommet
{
	char				*name;
	int					distance;
	int					ant;
	int					visited;
	struct s_adj_lst	*lst;
	struct s_sommet		*next;
	struct s_sommet		*prev;
}					t_sommet;

typedef struct		s_adj_lst
{
	char				*name;
	int					flow;
	struct s_adj_lst	*next;
}					t_adj_lst;

typedef struct		s_queue
{
	t_sommet		*sommet;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_stack
{
	t_sommet		*sommet;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_control_queue
{
	t_queue		*head;
	t_queue		*tail;
}					t_control_queue;

typedef struct		s_shortcut
{
	t_sommet	*save_last_node;
	t_sommet	*cur_graph;
	t_sommet	*cur_resid_graph;
}					t_shortcut;

/*
** 	hashtable function
*/

int					lm_hash(char *str);
int					lm_add_sommet(t_sommet **graph, char *str);
int					lm_add_start_end(t_sommet **graph, int index);
t_sommet			**lm_copy_hashtable(t_sommet **graph);
t_sommet			*lm_copy_node(t_sommet **graph, t_sommet *src);
void				lm_update_main_graph(t_sommet **graph,
		t_sommet **resid_graph);
t_sommet			*lm_get_sommet(t_sommet **graph, char *needle);
t_sommet			*lm_get_next_sommet_by_flow(t_sommet **graph,
		t_sommet *cur);

/*
** 		manip de tab
*/

void				lm_fill_ants_per_path_tab(t_sommet **graph, int path,
		int ants, int *tab_of_ants);
void				lm_init_save_cur_ant_tab(t_sommet **tab, t_sommet **graph,
		int size);
int					lm_verif_ant_cur_tab(t_sommet **cur_tab, int size);

/*
**		quit
*/

t_sommet			**lm_quit_properly_copy_graph(t_sommet **resid_graph);

/*
** 		adjencency lst function
*/

int					lm_add_tube(t_sommet **graph, char *pattern);
int					lm_new_lst_node(t_adj_lst **lst, t_adj_lst *src);
int					lm_new_lst_node_atend(t_adj_lst **lst, char *name,
		int flow);

/*
** 		free procedure
*/

void				lm_free_adj_lst(t_adj_lst *adj_lst);
void				lm_free_hashtable(t_sommet **hashtab);
void				lm_free_resid_graph(t_sommet **resid_graph);
void				lm_free_queue(t_control_queue *control);
void				lm_free_adj_resid_graph_lst(t_adj_lst *adj_lst);
void				lm_free_resnode(t_sommet *node);

/*
** 		queue function
*/

int					lm_add_elem_queue(t_control_queue *control,
		t_sommet *new_elem);
t_sommet			*lm_pop_queue(t_control_queue *control);

/*
** 		algo
*/

int					lm_add_neighboor(t_sommet **graph, t_sommet *node,
		t_control_queue *control_queue);
int					lm_add_neighboor_relaxing(t_sommet **graph, t_sommet *node,
		t_control_queue *control_queue);
int					lm_add_neighboor_visited2(t_sommet **graph, t_sommet *node,
		t_control_queue *control_queue);
void				lm_fill_distance_flow(t_sommet **graph);
void				lm_sort_lst_byorder(t_sommet **graph);
int					lm_sort_begin_byorder(t_sommet **graph);
void				lm_clean_visited(t_sommet **graph);
void				lm_clean_resid_graph(t_sommet **resid_graph);
t_adj_lst			*lm_get_edge(t_adj_lst *lst, char *str);
int					lm_find_best_flow(t_sommet **graph, int ants);
int					lm_find_one_path_with_bfs(t_sommet **graph);
t_sommet			*lm_get_node_to_reverse_bfs(t_sommet **resid_graph);
int					lm_relaxing_bfs(t_sommet **resid_graph, t_sommet *node);
void				lm_reverse_valid_path(t_sommet **resid_graph,
		t_sommet **graph, t_sommet *node);
void				lm_reverse_wrong_path(t_sommet **resid_graph,
		t_sommet *node);

/*
** 		display
*/

int					lm_core_print_ants(t_sommet **graph, int ants,
		int path);
void				lm_send_first_ant_in_path(t_sommet **graph,
		t_sommet **tab, int *tab_of_ant, int size);
void				lm_remove_one_ant(int *tab_of_ant, int size);
void				lm_print_all_ants(char *end, int ants);

/*
** 	path manip
*/

int					lm_is_worth_path_bfs(t_sommet **graph, int ants,
		int path);
void				lm_bfs_valid_path(t_sommet **graph);
int					lm_is_worth_path_flow(t_sommet **graph,
		t_sommet **resid_graph, t_sommet *first_node, int ants);

/*
** 	parsing function
*/

int					lm_parse_ant(char *ligne);
int					lm_parseur(t_sommet **graph);
int					lm_is_good_room(char *room);
int					lm_parse_room_and_stock_room(t_sommet **sommet);
int					lm_is_good_name_room(t_sommet **sommet, char *room);
char				*lm_get_room_name(char *str);
int					lm_get_name_length(char *str);

/*
**		chepa
*/

int					stock_input(t_input **input);
int					get_line(char **line, t_input *input, int start);
void				freeanddisplay_input(t_input *input);

/*
** 	un peu d'utils
*/

char				*lm_get_room_name(char *str);
int					lm_verif_tube(char *str);
void				lm_swap_ptr(void **first_ptr, void **second_ptr);

int					lm_add_start(t_sommet **hashtable, char *str);
int					lm_add_end(t_sommet **hashtable, char *str);
void				print_sommet(t_sommet *hashtable);
void				print_hashtable(t_sommet **hashtable);
void				print_all_hashtable(t_sommet **hashtable);
void				print_resid_graph(t_sommet **);
void				print_all_hashtable_wdistance(t_sommet **hashtable);
void				print_hashtable_distance_and_prev(t_sommet **hashtable);
void				print_hashtable_visited_and_prev(t_sommet **hashtable);
void				debug_queue(t_sommet **hashtable);
void				print_path(t_sommet **hashtable, t_sommet *node);
void				print_queue(t_control_queue *control);
void				print_flow(t_sommet **hashtable);
void				print_node(t_sommet *);
void				print_adj_lst(t_sommet *, t_adj_lst *);
void				print_adj_lst_distance(t_sommet **, t_sommet *,
t_adj_lst *);
void				print_hashtable_flow(t_sommet **hashtable);
void				print_stack(t_stack *stack);
void				print_ant_path(t_sommet **graph);
int					is_node_in_graph(t_sommet **graph, t_sommet *node);
void				print_tab_ant(t_sommet **tab, int size);

#endif
