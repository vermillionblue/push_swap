/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:07:02 by danisanc          #+#    #+#             */
/*   Updated: 2022/03/23 23:33:44 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

//check for input errors
long	ft_atol(const char *str);
int		senderror(char **argv);
int		ft_checkdup(char **arr);
int		issmallest(int num, int *arr, int argc);
int		isbiggest(int num, int *arr, int argc);
int		issorted(int *arr, int argc);
int		*placenums(int argc, char **argv);
//operations
void	push_ab(int	*stack_a, int *stack_b, int *argc, int *argb);
void	rotate_r(int *arr, char c, int argc);
void	ft_rotate(int *arr, char c, int argc);
void	ft_swap(int *arr, char c);
void	ft_swapab(int *arr1, int *arr2);
void	pbandprint(int *stack_a, int *stack_b, int *argc, int *argb);
void	double_r(int *stack_a, int *stack_b, int argc, int argb);
void	double_r_r(int *stack_a, int *stack_b, int argc, int argb);
void	rotate_r_remainder(int *counter, int *stack, int argnum, char c);
void	rotate_remainder(int *counter, int *stack, int argnum, char c);

///find spot
int		findindexbiggest(int *stack_b, int argb);
int		findindexsmallest(int *stack_b, int argb);
int		findspot(int num, int *stack_b, int argb);
///choose number to push
int		choosesize(int argc);
int		exploretop(int *stack_a, int size, int *stack_b, int argb);
int		explorebottom(int *stack_a, int argc, int size, int *stack_b, int argb);
#endif