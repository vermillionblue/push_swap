/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findspot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:06:43 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/15 17:54:17 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findindexbiggest(int *stack_b, int argb)
{
	int	i;
	int	num;
	int	index;

	i = 1;
	index = 0;
	num = stack_b[0];
	while (i < argb - 1)
	{
		if (stack_b[i] > num)
		{
			num = stack_b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	findindexsmallest(int *stack_b, int argb)
{
	int	i;
	int	num;
	int	index;

	i = 1;
	index = 0;
	num = stack_b[0];
	while (i < argb - 1)
	{
		if (stack_b[i] < num)
		{
			num = stack_b[i];
			index = i;
		}	
		i++;
	}
	return (index);
}

int	findspot(int num, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_b - 2)
	{
		if (isbiggest(num, data->stack_b, data->len_b))
			return (findindexbiggest(data->stack_b, data->len_b));
		if (issmallest(num, data->stack_b, data->len_b))
			return (findindexsmallest(data->stack_b, data->len_b) + 1);
		if ((issmallest(data->stack_b[i], data->stack_b, data->len_b)
				&& isbiggest(data->stack_b[i + 1], data->stack_b, data->len_b))
			|| (issmallest(data->stack_b[i + 1], data->stack_b, data->len_b)
				&& isbiggest(data->stack_b[i], data->stack_b, data->len_b) && data->len_b > 3))
		{
			i++;
			continue ;
		}
		if ((num < data->stack_b[i] && num > data->stack_b[i + 1]))
			break ;
		i++;
	}
	return (i + 1);
}
