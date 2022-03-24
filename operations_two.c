/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:17:07 by danisanc          #+#    #+#             */
/*   Updated: 2022/03/23 23:19:17 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pbandprint(int *stack_a, int *stack_b, int *argc, int *argb)
{
	push_ab(stack_a, stack_b, argc, argb);
	write(1, "pb\n", 3);
}

void	double_r(int *stack_a, int *stack_b, int argc, int argb)
{
	ft_rotate(stack_b, 'c', argb);
	ft_rotate(stack_a, 'c', argc);
	write(1, "rr\n", 3);
}

void	double_r_r(int *stack_a, int *stack_b, int argc, int argb)
{
	rotate_r(stack_a, 'c', argc);
	rotate_r(stack_b, 'c', argb);
	write(1, "rrr\n", 4);
}

void	rotate_r_remainder(int *counter, int *stack, int argnum, char c)
{
	while (*counter > 0)
	{
		rotate_r(stack, c, argnum);
		*counter = *counter - 1;
	}
}

void	rotate_remainder(int *counter, int *stack, int argnum, char c)
{
	while (*counter > 0)
	{
		ft_rotate(stack, c, argnum);
		*counter = *counter - 1;
	}
}
