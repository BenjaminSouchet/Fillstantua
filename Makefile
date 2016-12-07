# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpeguet <jpeguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 00:21:46 by jpeguet           #+#    #+#              #
#    Updated: 2016/12/07 03:38:32 by gmonein          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ./srcs/ft_place.c \
		./srcs/ft_main.c \
		./srcs/ft_strlen.c \
		./srcs/ft_list_valid.c \
		./srcs/ft_list_tool.c \
		./srcs/ft_convert_tools.c \
		./srcs/ft_data_one.c \
		./srcs/ft_data_two.c \
		./srcs/ft_data_three.c \
		./srcs/ft_data_four.c \
		./srcs/ft_data_five.c \
		./srcs/ft_new_fill.c \
		./srcs/ft_print_map.c \
		./srcs/ft_utility.c \
		./srcs/ft_bzero.c \
		./srcs_sas/ft_place.c \
		./srcs_sas/ft_print_map.c \
		./srcs_sas/bits_sas.c \
		./srcs_sas/bit_p.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -I ./include -Wall -Werror -Wextra

$(NAME):$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

all:$(NAME)

clean:
				@rm -rf $(OBJS)

fclean: clean
				@rm -f $(NAME)

re : fclean all

test : re
				@clear
				@./fillit samples
