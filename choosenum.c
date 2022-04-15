/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosenum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:20:31 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/15 18:17:33 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choosesize(int num)
{
	if ((num >= 100 && num) < 500)
		return (10);
	else
		return (30);
}

int	exploretop(t_data *data, int size)
{
	int	i;
	int	num;
	int	index;

	i = 1;
	index = 0;
	num = findspot(data->stack_a[0], &data);
	while (i < size - 1)
	{
		if (findspot(data->stack_a[i], &data) < num)
		{
			num = findspot(data->stack_a[i], &data);
			index = i;
		}
		i++;
	}
	return (index);
}

int	explorebottom(t_data *data, int size)
{
	int	i;
	int	num;
	int	index;

	i = data->len_a - 3;
	index = data->len_a - 2;
	num = findspot(data->stack_a[data->len_a - 2], &data);
	while (i > data->len_a - 2 - size)
	{
		if (findspot(data->stack_a[i], &data) < num)
		{
			num = findspot(data->stack_a[i], &data);
			index = i;
		}	
		i--;
	}
	return (index);
}
