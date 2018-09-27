# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabt <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:14:05 by jabt              #+#    #+#              #
#    Updated: 2018/09/27 15:13:04 by galemair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Werror -Wextra -Wall

SOURCE = $(wildcard *.c)

OBJET = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJET)
	@ar rc $(NAME) $(OBJET) ;
	@ranlib $(NAME)
	@echo "\n\033[1;32m LIBFT COMPILED \033[0m"

%.o: %.c
	@printf "🐜 "
	@gcc $(FLAG) -I includes/ -o $@ -c $<

clean :
	@rm -f $(OBJET)
	@echo "\033[1;32m clean  OK \033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1;32m fclean OK \033[0m"

re : fclean $(NAME)
