/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:34:39 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/15 18:21:19 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forthree(t_data *data)
{
	while (!(issorted(data->stack_a, data->len_a)))
	{
		int len = data->len_a;
		if (isbiggest(data->stack_a[0], data->stack_a, data->len_a)
			&& issmallest(data->stack_a[1], data->stack_a, data->len_a) && data->len_a == 4)
			ft_rotate(data->stack_a, 'a', data->len_a);
		if (data->stack_a[0] > data->stack_a[1])
			ft_swap(data->stack_a, 'a');
		if (!(isbiggest(data->stack_a[len - 2], data->stack_a, data->len_a)))
			rotate_r(data->stack_a, 'a', data->len_a);
	}
}

void	pushbackin(t_data *data)
{
	int	index;

	while (data->len_b > 1)
	{
		if (isbiggest(data->stack_b[0], data->stack_b, data->len_b))
		{
			push_ab(&data);
			write(1, "pa\n", 3);
		}
		else
		{
			index = findindexbiggest(data->stack_b, data->len_b);
			if (index < ((data->len_b - 2) / 2) || index == ((data->len_b - 2) / 2)
				|| index == ((data->len_b - 2) / 2) + 1)
				rotate_remainder(&index, data->stack_b, data->len_b, 'b');
			else
			{
				index = data->len_b - 1 - index;
				rotate_r_remainder(&index, data->stack_b, data->len_b, 'b');
			}
		}
	}
}

void	forfiveandfour(t_data *data)
{
	while (data->len_a > 3)
	{
		if (isbiggest(data->stack_a[0], data->stack_a, data->len_a)
			|| issmallest(data->stack_a[0], data->stack_a, data->len_a))
			ft_rotate(data->stack_a, 'a', data->len_a);
		else
			pbandprint(&data);
	}
	if (issmallest(data->stack_a[0], data->stack_a, data->len_a) && data->stack_b[0] < data->stack_b[1])
		ft_swapab(&data);
	else if (issmallest(data->stack_a[0], data->stack_a, data->len_a))
		ft_swap(data->stack_a, 'a');
	pushbackin(&data);
	rotate_r(data->stack_a, 'a', data->len_a);
}

void	forhundred(t_data* data)
{
	int	hold_bottom;
	int	hold_top;
	int	x;
	int	s;
	int	f;
	int	size;

	size = choosesize(data->len_a);
	while (data->len_a > 1)
	{
		f = 0;
		hold_top = exploretop(&data);
		hold_bottom = explorebottom(&data);
		if (data->len_a - 1 - hold_bottom < hold_top)
		{
			f = findspot(data->stack_a[hold_bottom], &data);
			x = data->len_a - 1 - hold_bottom;
			s = *argb - 1 - f;
			if (*argc - 1 - hold_bottom < hold_top)
			{
				if ((!(f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2)
							|| f == ((*argb - 2) / 2) + 1))
					&& *argb >= 3 && f != 0)
				{
					while (s > 0 && x > 0)
					{	
						double_r_r(stack_a, stack_b, data->len_a, *argb);
						x--;
						s--;
					}
				}
				rotate_r_remainder(&x, stack_a, data->len_a, 'a');
				if (*argb < 3)
					pbandprint(stack_a, stack_b, &data->len_a, argb);
				else
				{
					if (f == 0)
						pbandprint(stack_a, stack_b, &data->len_a, argb);
					else
					{
						if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2)
								|| f == ((*argb - 2) / 2) + 1) && *argb >= 3)
							rotate_remainder(&f, stack_b, *argb, 'b');
						else
							rotate_r_remainder(&s, stack_b, *argb, 'b');
						pbandprint(stack_a, stack_b, &data->len_a, argb);
					}
				}
			}
		}
		else
		{
			f = findspot(stack_a[hold_top], stack_b, *argb);
			if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2)
					|| f == ((*argb - 2) / 2) + 1) && *argb >= 3 && f != 0)
			{
				while (hold_top > 0 && f > 0)
				{
					double_r(stack_a, stack_b, *argc, *argb);
					f--;
					hold_top--;
				}
			}
			rotate_remainder(&hold_top, stack_a, *argc, 'a');
			if (*argb < 3)
				pbandprint(stack_a, stack_b, argc, argb);
			else
			{
				if (f == 0)
					pbandprint(stack_a, stack_b, argc, argb);
				else
				{
					x = *argb - 1 - f;
					if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2)
							|| f == ((*argb - 2) / 2) + 1) && *argb >= 3)
						rotate_remainder(&f, stack_b, *argb, 'b');
					else
						rotate_r_remainder(&x, stack_b, *argb, 'b');
					pbandprint(stack_a, stack_b, argc, argb);
				}
			}
		}
	}
	pushbackin(stack_a, *argc, stack_b, *argb);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.stack_b = ft_calloc(argc - 1, sizeof(int));
	data.len_b = 0;
	data.len_a = argc;
	if (!(senderror(argv)))
		return (write(2, "Error\n", 6));
	data.stack_a = placenums(argc, argv);
	if (argc == 2 || issorted(data.stack_a, argc))
		return (0);
	if (argc < 5)
		forthree(&data);
	if (argc <= 6)
		forfiveandfour(&data);
	if (argc > 6)
		forhundred(&data);
	free(stack_a);
	free(stack_b);
	return (0);
}
