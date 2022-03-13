void forfour(int *stack_a,int *argc,  int *argb)
{
	int	*stack_b;

	stack_b = ft_calloc(*argc - 1, sizeof(int));
	while(*argc > 3)
	{
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);
		if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && *argb > 2 && *argc > 2)
			ft_swapab(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1] && *argc > 2)
			ft_swap(stack_a, 'a');
		else if (stack_b[0] < stack_b[1] && *argb > 2)
			ft_swap(stack_b, 'b');

		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);
		
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);

		push_ab(stack_a, stack_b, argc, argb);
		write(1, "pb\n", 3);
		if (*argc <= 4)
			break;
		
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);
		if (*argc <= 4)
			break;
		if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && *argb > 2 && *argc > 2)
			ft_swapab(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1] && *argc > 2)
			ft_swap(stack_a, 'a');
		else if (stack_b[0] < stack_b[1] && *argb > 2)
			ft_swap(stack_b, 'b');
		if (*argc <= 4)
			break;
		if (issmallest(stack_b[0], stack_b, *argb) && *argb > 2)
			ft_rotate(stack_b, 'b', *argc);
	}
	while(*argc == 4)
	{
		if (!(isbiggest(stack_a[0], stack_a, *argc)) && !(issmallest(stack_a[0], stack_a, *argc)))
		{
			push_ab(stack_a, stack_b, argc, argb);
			write(1, "pb\n", 3);	
		}
		else
			if (!(isbiggest(stack_a[1], stack_a, *argc)) && !(issmallest(stack_a[1], stack_a, *argc)))
				if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && *argb > 2 && *argc > 2)
					ft_swapab(stack_a, stack_b);
				else
					ft_swap(stack_a, 'a');
			else
				rotate_r(stack_a, 'a', *argc);

	}
	while(*argb > 1)
	{
		if (issmallest(stack_a[0], stack_a, *argc))
			ft_swap(stack_a, 'a');
		if (stack_b[0] < stack_b[1])
			ft_swap(stack_b, 'b');

		if (isbiggest(stack_b[0], stack_b, *argb))
		{
			push_ab(stack_b, stack_a, argb, argc);
			write(1, "pa\n", 3);
		}
		else
			rotate_r(stack_b , 'b', *argb);
	}
	rotate_r(stack_a, 'a', *argc);
	//printf("+++++++++++++\n");
	//printarr(*argc, stack_a);
	//printf("+++++++++++++");
}
