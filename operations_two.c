/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:17:07 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/15 18:11:07 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pbandprint(t_data *data)
{
	push_ab(&data);
	write(1, "pb\n", 3);
}

void	double_r(t_data *data)
{
	ft_rotate(data->stack_b, 'c', data->len_b);
	ft_rotate(data->stack_a, 'c', data->len_a);
	write(1, "rr\n", 3);
}

void	double_r_r(t_data *data)
{
	rotate_r(data->stack_a, 'c', data->len_a);
	rotate_r(data->stack_b, 'c', data->len_b);
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
