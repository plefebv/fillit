# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 16:16:52 by plefebvr          #+#    #+#              #
#    Updated: 2016/03/14 22:48:51 by plefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fillit
HEADER =		fillit.h
CC =			gcc
FLAGS =			-Wall -Wextra -Werror
LIBFT =			libft/libft.a

SRCS =			main.c \
				ft_read_argv.c \
				ft_count_tetros.c \
				ft_valid_tetros.c \
				ft_lst_tetros.c \
				fillit.c \
				ft_adj_tetro.c \
				ft_map.c \
				ft_solve.c

OBJS =			$(SRCS:.c=.o)

all:			$(NAME)

$(LIBFT):
			make -C libft/ fclean
			make -C libft/

$(NAME):		$(LIBFT) $(OBJS)
			$(CC) $(FLAGS) -o $@ $(OBJS) $(LIBFT)

%.o:				%.c
			$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
			make -C libft/ fclean
			/bin/rm -f $(OBJS)

fclean:			clean
			/bin/rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
