/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:34:39 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/16 19:10:18 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forthree(t_data *data)
{
	int	len;

	while (!(issorted(data->stack_a, data->len_a)))
	{
		len = data->len_a;
		if (isbiggest(data->stack_a[0], data->stack_a, data->len_a)
			&& issmallest(data->stack_a[1], data->stack_a, data->len_a)
			&& data->len_a == 4)
			ft_rotate(data->stack_a, 'a', data->len_a);
		if (data->stack_a[0] > data->stack_a[1])
			ft_swap(data->stack_a, 'a');
		if (!(isbiggest(data->stack_a[len - 2], data->stack_a, data->len_a)))
			rotate_r(data->stack_a, 'a', data->len_a);
	}
	free(data->stack_a);
	exit (1);
}

void	forfiveandfour(t_data *data)
{
	while (data->len_a > 3)
	{
		if (isbiggest(data->stack_a[0], data->stack_a, data->len_a)
			|| issmallest(data->stack_a[0], data->stack_a, data->len_a))
			ft_rotate(data->stack_a, 'a', data->len_a);
		else
			pbandprint(data);
	}
	if (issmallest(data->stack_a[0], data->stack_a, data->len_a)
		&& data->stack_b[0] < data->stack_b[1])
		ft_swapab(data);
	else if (issmallest(data->stack_a[0], data->stack_a, data->len_a))
		ft_swap(data->stack_a, 'a');
	pushbackin(data);
	rotate_r(data->stack_a, 'a', data->len_a);
	free(data->stack_a);
	exit (1);
}

void	forhundred(t_data *data)
{
	int	hold_bottom;
	int	hold_top;
	int	size;

	size = choosesize(data->len_a);
	while (data->len_a > 1)
	{
		hold_top = exploretop(data, size);
		hold_bottom = explorebottom(data, size);
		if (data->len_a - 1 - hold_bottom < hold_top)
			bottom_is_closer(data, hold_bottom);
		else
			top_is_closer(data, hold_top);
	}
	pushbackin(data);
	free(data->stack_a);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.len_a = argc;
	if (!(senderror(argv)))
		return (write(2, "Error\n", 6));
	data.stack_a = placenums(argc, argv);
	if (argc == 2 || issorted(data.stack_a, argc))
	{
		free(data.stack_a);
		return (0);
	}
	if (argc < 5)
		forthree(&data);
	data.stack_b = ft_calloc(argc - 1, sizeof(int));
	data.len_b = 0;
	if (argc <= 6)
		forfiveandfour(&data);
	if (argc > 6)
		forhundred(&data);
	return (0);
}
