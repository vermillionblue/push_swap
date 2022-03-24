# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alessa <alessa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:32:55 by danisanc          #+#    #+#              #
#    Updated: 2022/03/23 22:43:46 by alessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target: dependencies
#	action

#targets ...: target-pattern: prereq-patterns ...
#   commands

NAME = push_swap

LIB = libft/libft.a 

SRCS = algo.c checkers.c errors.c operation_push.c operations.c \
 starting.c  choosenum.c findspot.c operations_two.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g -Werror -Wextra -Wall

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@ 

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re