/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:13:06 by danisanc          #+#    #+#             */
/*   Updated: 2022/03/23 23:13:51 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_push(int *arr, int *argc)
{
	int	temp;
	int	temp2;
	int	i;

	i = *argc - 2;
	temp = arr[*argc - 2];
	while (i >= 0)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i--;
	}
}

static void	rotate_r_push(int *arr, int *argc)
{
	int	temp;
	int	temp2;
	int	i;

	i = 1;
	temp = arr[0];
	while (i < *argc)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i++;
	}
}

void	push_ab(int	*stack_a, int	*stack_b, int *argc, int *argb)
{
	int	temp;

	temp = stack_a[0];
	rotate_push(stack_a, argc);
	*argc = *argc - 1;
	if (*argb == 0)
	{
		stack_b[0] = temp;
		*argb = 2;
	}
	else
	{
		rotate_r_push(stack_b, argb);
		stack_b[0] = temp;
		*argb = *argb + 1;
	}
}
