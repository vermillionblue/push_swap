/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:19:37 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/15 17:58:50 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issmallest(int num, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (num > arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	isbiggest(int num, int *arr, int len)
{
	int	i;

	i = 0;
	while (i <= len - 2)
	{
		if (num < arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	issorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 2)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*placenums(int argc, char **argv)
{
	int	i;
	int	k;
	int	*stack_a;

	i = 1;
	k = 0;
	stack_a = ft_calloc(argc - 1, sizeof(int));
	while (argv[i])
	{
		stack_a[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
	return (stack_a);
}
