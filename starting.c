/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:34:06 by danisanc          #+#    #+#             */
/*   Updated: 2022/03/23 23:34:24 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
