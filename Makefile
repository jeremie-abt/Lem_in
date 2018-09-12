# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galemair <galemair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 13:49:33 by galemair          #+#    #+#              #
#    Updated: 2018/09/12 14:39:32 by jabt             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM			=	rm -rf

NAME		=	lem-in

INCLUDES	=	inc/

SRCS		=	main.c							\
				src/debug.c						\
				src/lm_algo.c					\
				src/lm_algo_dfs.c				\
				src/lm_bfs_core.c				\
				src/lm_fill_distance.c			\
				src/lm_free_procedure.c			\
				src/lm_get_sommet.c				\
				src/lm_hash_algo.c				\
				src/lm_hashtable_ants.c			\
				src/lm_hashtable_core.c			\
				src/lm_manage_input.c			\
				src/lm_manage_queue.c			\
				src/lm_manip_adj_lst.c			\
				src/lm_manip_edge.c				\
				src/lm_manip_sommet_lst.c		\
				src/lm_manip_tab.c				\
				src/lm_max_flow_prob.c			\
				src/lm_parseur.c				\
				src/lm_parsing_utils.c			\
				src/lm_print_ants.c				\
				src/lm_sort_adj_lst.c			\
				src/lm_update_main_graph.c		\
				src/lm_verif_format.c			\
				src/lm_manip_sommet_lst_helper.c\

OBJS	=		$(SRCS:.c=.o)

$(NAME): lib printf $(OBJS) 
	@gcc -o $@ $(OBJS) libft/libft.a
	@printf "\nLEM IN COMPILED\n"

all:	$(NAME)

lib:
	@make -C libft/

printf:
	@make -C ft_printf/

%.o : %.c
	@printf "🐜 "
	@gcc -o $@ -c $< -I $(INCLUDES)

clean:
	@rm -f $(OBJS)
	@make clean -C libft/
	@make clean -C ft_printf/

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@make fclean -C ft_printf/

re: fclean all

.PHONY: clean fclean re

