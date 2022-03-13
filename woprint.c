#include "push_swap.h"


int *copystack(int *stack_a, int argc)
{
	int	i;
	int	*stack_c;

	stack_c = ft_calloc(argc - 1, sizeof(int));
	i = 0;
	while(i < argc -2)
	{
		stack_c[i] = stack_a[i];
		i++;
	}
	return(stack_c);
}

int	*findchunks(int *stack_c,int *argc,  int *argb)
{
	int	*stack_b;
	int	*stack_a;

	stack_a = copystack(stack_c, *argc);
	stack_b = ft_calloc(*argc - 1, sizeof(int));
	while(*argc > 3)
	{
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'c', *argc);
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'c', *argc);
		if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && *argb > 2 && *argc > 2)
			ft_swapab(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1] && *argc > 2)
			ft_swap(stack_a, 'c');
		else if (stack_b[0] < stack_b[1] && *argb > 2)
			ft_swap(stack_b, 'c');

		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'c', *argc);
		
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'c', *argc);

		push_ab(stack_a, stack_b, argc, argb);
		if (*argc <= 4)
			break;
		
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);
		if (*argc <= 4)
			break;
		if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && *argb > 2 && *argc > 2)
			ft_swapab(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1] && *argc > 2)
			ft_swap(stack_a, 'c');
		else if (stack_b[0] < stack_b[1] && *argb > 2)
			ft_swap(stack_b, 'c');
		if (*argc <= 4)
			break;
		if (issmallest(stack_b[0], stack_b, *argb) && *argb > 2)
			ft_rotate(stack_b, 'c', *argc);
	}
	while(*argc == 4)
	{
		if (!(isbiggest(stack_a[0], stack_a, *argc)) && !(issmallest(stack_a[0], stack_a, *argc)))
			push_ab(stack_a, stack_b, argc, argb);	
		else
			if (!(isbiggest(stack_a[1], stack_a, *argc)) && !(issmallest(stack_a[1], stack_a, *argc)))
				if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && *argb > 2 && *argc > 2)
					ft_swapab(stack_a, stack_b);
				else
					ft_swap(stack_a, 'c');
			else
				rotate_r(stack_a, 'c', *argc);

	}
	while(*argb > 1)
	{
		if (issmallest(stack_a[0], stack_a, *argc))
			ft_swap(stack_a, 'c');
		if (stack_b[0] < stack_b[1])
			ft_swap(stack_b, 'c');

		if (isbiggest(stack_b[0], stack_b, *argb))
			push_ab(stack_b, stack_a, argb, argc);
		else
			rotate_r(stack_b , 'c', *argb);
	}
	rotate_r(stack_a, 'c', *argc);
	free(stack_b);
	return(stack_a);
}