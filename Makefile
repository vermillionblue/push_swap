# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:32:55 by danisanc          #+#    #+#              #
#    Updated: 2022/04/16 19:11:44 by danisanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target: dependencies
#	action

#targets ...: target-pattern: prereq-patterns ...
#   commands

NAME = push_swap

LIB = libft/libft.a 

SRCS = algo.c checkers.c errors.c operation_push.c operations.c \
 choosenum.c findspot.c operations_two.c utils.c

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