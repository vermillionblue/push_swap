/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:13:06 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/15 18:09:16 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_push(int *arr, int *len)
{
	int	temp;
	int	temp2;
	int	i;

	i = *len - 2;
	temp = arr[*len - 2];
	while (i >= 0)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i--;
	}
}

static void	rotate_r_push(int *arr, int *len)
{
	int	temp;
	int	temp2;
	int	i;

	i = 1;
	temp = arr[0];
	while (i < *len)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i++;
	}
}

void	push_ab(t_data*	data)
{
	int	temp;

	temp = data->stack_a[0];
	rotate_push(data->stack_a, data->len_a);
	data->len_a = data->len_a - 1;
	if (data->len_b == 0)
	{
		data->stack_b[0] = temp;
		data->len_b = 2;
	}
	else
	{
		rotate_r_push(data->stack_b, data->len_b);
		data->stack_b[0] = temp;
		data->len_b = data->len_b + 1;
	}
}
