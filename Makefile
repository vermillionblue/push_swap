# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alessa <alessa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:32:55 by danisanc          #+#    #+#              #
#    Updated: 2022/03/08 21:15:49 by alessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target: dependencies
#	action

#targets ...: target-pattern: prereq-patterns ...
#   commands

NAME = push_swap

LIB = libft/libft.a 

SRCS = push_swap.c ft_atol.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@ 

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re