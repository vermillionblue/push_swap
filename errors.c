/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:21:27 by danisanc          #+#    #+#             */
/*   Updated: 2022/03/24 22:10:21 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	senderror(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (0);
		while (argv[i][k])
		{
			if (k == 0 && argv[i][k] == '-')
			{
				k++;
				continue ;
			}
			if (!(ft_isdigit(argv[i][k])))
				return (0);
			k++;
		}
		i++;
	}
	if (!ft_checkdup(argv))
		return (0);
	return (1);
}

int	ft_checkdup(char **arr)
{
	int	i;
	int	k;

	i = 1;
	while (arr[i] != 0)
	{
		k = 1;
		while (arr[k])
		{
			if (k == i)
			{
				k++;
				continue ;
			}
			else
			{
				if (ft_atoi(arr[k]) == ft_atoi(arr[i]))
					return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}
