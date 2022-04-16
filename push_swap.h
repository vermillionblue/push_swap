/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:07:02 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/16 19:39:56 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_data
{
	int	len_a;
	int	len_b;
	int	*stack_a;
	int	*stack_b;
}				t_data;

//check for input errors
int		senderror(char **argv);
int		ft_checkdup(char **arr);
int		issorted(int *arr, int len);
int		*placenums(int argc, char **argv);

// helper functions
int		issmallest(int num, int *arr, int len);
int		isbiggest(int num, int *arr, int len);
void	bottom_is_closer(t_data *data, int hold_bottom);
void	top_is_closer(t_data *data, int hold_top);
void	loop_til_spot(t_data *data, int spot, int x);
void	pushbackin(t_data *data);

//operations
void	push_ab(int *stack_a, int *stack_b, int *argc, int *argb);
void	rotate_r(int *arr, char c, int argc);
void	ft_rotate(int *arr, char c, int argc);
void	ft_swap(int *arr, char c);
void	ft_swapab(t_data *data);
void	pbandprint(t_data *data);
void	double_r(t_data *data);
void	double_r_r(t_data *data);
void	rotate_r_remainder(int *counter, int *stack, int argnum, char c);
void	rotate_remainder(int *counter, int *stack, int argnum, char c);

///find spot
int		findindexbiggest(int *stack_b, int argb);
int		findindexsmallest(int *stack_b, int argb);
int		findspot(int num, t_data *data);

///choose number to push
int		choosesize(int num);
int		exploretop(t_data *data, int size);
int		explorebottom(t_data *data, int size);

#endif