# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galemair <galemair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 13:49:33 by galemair          #+#    #+#              #
#    Updated: 2018/09/24 11:24:41 by galemair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM			=	rm -rf

NAME		=	lem-in

DEBUG		=	-g -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	inc/

SRCS		=	lem_in.c									\
				src/debug.c									\
				src/lm_algo.c								\
				src/lm_bfs_core.c							\
				src/lm_fill_distance.c						\
				src/lm_free_graph.c                         \
				src/lm_free_procedure.c                     \
				src/lm_get_sommet.c                         \
				src/lm_hash_algo.c                          \
				src/lm_hashtable_ants.c                     \
				src/lm_hashtable_core.c                     \
				src/lm_is_worth_path.c                      \
				src/lm_is_worth_reverse.c                   \
				src/lm_manage_input.c                       \
				src/lm_manage_queue.c                       \
				src/lm_manip_adj_lst.c                      \
				src/lm_manip_edge.c                         \
				src/lm_manip_sommet_lst.c                   \
				src/lm_manip_sommet_lst_helper.c            \
				src/lm_manip_tab.c                          \
				src/lm_neighboor_bfs.c                      \
				src/lm_parseur.c                            \
				src/lm_path_manip.c                         \
				src/lm_print_ants.c                         \
				src/lm_quit_properly_resid_graph.c          \
				src/lm_reverse_path.c                       \
				src/lm_reverse_wrong_path.c                 \
				src/lm_sort_adj_lst.c                       \
				src/lm_update_main_graph.c                  \
				src/lm_utils.c                              \
				src/lm_verif_format.c                       \

OBJS		=	$(SRCS:.c=.o)
			

$(NAME): lib printf $(OBJS) 
	@gcc -g -o $@ $(OBJS) libft/libft.a ft_printf/libftprintf.a
	@echo "\n\033[1;32m LEM-IN COMPILED\033[0m"

all:	$(NAME)

lib:
	@make -C libft/

printf:
	@make -C ft_printf/

%.o : %.c
	@printf "🐜 "
	@gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES)

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

