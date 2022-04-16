/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:08:30 by danisanc          #+#    #+#             */
/*   Updated: 2022/04/16 19:36:48 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_til_spot(t_data *data, int spot, int x)
{
	if (spot == 0)
		pbandprint(data);
	else
	{
		if ((spot < ((data->len_b - 2) / 2) || spot == ((data->len_b - 2) / 2)
				|| spot == ((data->len_b - 2) / 2) + 1) && data->len_b >= 3)
			rotate_remainder(&spot, data->stack_b, data->len_b, 'b');
		else
			rotate_r_remainder(&x, data->stack_b, data->len_b, 'b');
		pbandprint(data);
	}
}

void	bottom_is_closer(t_data *data, int hold_bottom)
{
	int	spot;
	int	x;
	int	s;

	spot = findspot(data->stack_a[hold_bottom], data);
	x = data->len_a - 1 - hold_bottom;
	s = data->len_b - 1 - spot;
	if ((!(spot < ((data->len_b - 2) / 2) || spot == ((data->len_b - 2) / 2)
				|| spot == ((data->len_b - 2) / 2) + 1))
		&& data->len_b >= 3 && spot != 0)
	{
		while (s-- > 0 && x-- > 0)
			double_r_r(data);
	}
	rotate_r_remainder(&x, data->stack_a, data->len_a, 'a');
	if (data->len_b < 3)
		pbandprint(data);
	else
		loop_til_spot(data, spot, s);
}

void	top_is_closer(t_data *data, int hold_top)
{
	int	spot;
	int	x;

	spot = findspot(data->stack_a[hold_top], data);
	if ((spot < ((data->len_b - 2) / 2) || spot == ((data->len_b - 2) / 2)
			|| spot == ((data->len_b - 2) / 2) + 1)
		&& data->len_b >= 3 && spot != 0)
	{
		while (hold_top > 0 && spot > 0)
		{
			double_r(data);
			spot--;
			hold_top--;
		}
	}
	rotate_remainder(&hold_top, data->stack_a, data->len_a, 'a');
	if (data->len_b < 3)
		pbandprint(data);
	else
	{
		x = data->len_b - 1 - spot;
		loop_til_spot(data, spot, x);
	}
}

void	pushbackin(t_data *data)
{
	int	index;

	while (data->len_b > 1)
	{
		if (isbiggest(data->stack_b[0], data->stack_b, data->len_b))
		{
			push_ab(data->stack_b, data->stack_a, &data->len_b, &data->len_a);
			write(1, "pa\n", 3);
		}
		else
		{
			index = findindexbiggest(data->stack_b, data->len_b);
			if (index < ((data->len_b - 2) / 2)
				|| index == ((data->len_b - 2) / 2)
				|| index == ((data->len_b - 2) / 2) + 1)
				rotate_remainder(&index, data->stack_b, data->len_b, 'b');
			else
			{
				index = data->len_b - 1 - index;
				rotate_r_remainder(&index, data->stack_b, data->len_b, 'b');
			}
		}
	}
	free(data->stack_b);
}
