# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabt <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Createdf: 2018/02/15 11:39:11 by jabt              #+#    #+#              #
#    Updated: 2018/09/19 13:07:14 by galemair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=libftprintf.a
LIB=libft/libft.a
INC=inc/ft_printf.h
FLAGS=-Wall -Werror -Wextra


.PHONY: clean fclean re libft

SRC= $(wildcard src/*.c) \
ft_printf.c

PATHLIB=./libft/

SRCLIBFT=ft_itoa.c \
		 ft_memdel.c \
		 ft_memmove.c \
		 ft_memset.c \
		 ft_strcarac.c \
		 ft_strcat.c \
		 ft_strchr.c \
		 ft_strdel.c \
		 ft_strlen.c \
		 ft_strncat.c \
		 ft_strnchr.c \
		 ft_strncpy.c \
		 ft_strnew.c \
		 ft_strstr.c \
		 ft_strtrim.c
OBJLIBFT= $(SRCLIBFT:.c=.o)

OBJ= $(addprefix obj/,$(notdir $(SRC:.c=.o)))

all: libft $(NAME)

$(NAME): obj $(OBJ)
	@ar rc $(NAME) $(OBJ) ../libft/libft.a
	@ranlib $(NAME) ;
	@echo "\n\033[1;32m FT_PRINTF COMPILED MAMENE\033[0m"

obj/%.o: src/%.c $(INC)
	@printf "🐜 "
	@$(CC) $(CFLAGS) -o $@ -c $< 

obj/ft_printf.o: ft_printf.c $(INC)
	@printf "🐜 "
	@$(CC) $(FLAGS) -o $@ -c $< 

obj:
	@mkdir obj

clean:
	rm -rf $(OBJ);
	rm -rf $(addprefix $(PATHLIB), $(OBJLIBFT))

fclean: clean
	rm -rf $(NAME)
	rm -rf $(PATHLIB)/libft.a

re: fclean libft $(NAME)
