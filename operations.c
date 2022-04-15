/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:14:10 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/15 18:08:09 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_r(int *arr, char c, int len)
{
	int	temp;
	int	end;
	int	temp2;
	int	i;

	i = 1;
	end = arr[len - 2];
	temp = arr[0];
	while (i < len - 1)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i++;
	}
	arr[0] = end;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rotate(int *arr, char c, int len)
{
	int	temp;
	int	start;
	int	temp2;
	int	i;

	i = len - 2;
	start = arr[0];
	temp = arr[len - 2];
	while (i >= 0)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i--;
	}
	arr[len - 2] = start;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_swap(int *arr, char c)
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_swapab(t_data* data)
{
	ft_swap(data->stack_b, 'c');
	ft_swap(data->stack_a, 'c');
	write(1, "ss\n", 3);
}
