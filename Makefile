# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:32:55 by danisanc          #+#    #+#              #
#    Updated: 2022/04/16 22:03:41 by danisanc         ###   ########.fr        #
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

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $^ $(LIB) -o $@ 

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re