# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 10:15:44 by kkotliar          #+#    #+#              #
#    Updated: 2017/09/06 13:22:51 by kkotliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = ft_buble_sort.o ft_check.o ft_operations.o ft_pivot.o ft_quic_sort.o main.o


HEADER = push_swap.h

LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) -o $@ $^ $(LIB) $(CFLAG) 

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft

