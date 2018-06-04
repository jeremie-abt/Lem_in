/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:37:05 by jabt              #+#    #+#             */
/*   Updated: 2018/06/04 13:28:43 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_adj_list
{
	char				*neighbor;
	struct s_adj_list	*next;
}				t_adj_list;

int			lm_hash(char *str);
int			lm_add_hashmap(t_adj_list **adj_list, char *str);
t_adj_list	*lm_add_node_adj_lst(char *name);
