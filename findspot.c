// int	biggestnumindex(int *stack_a, int argc)
// {
// 	int i;
// 	int num;
// 	int	index;

// 	i = 1;
// 	num = stack_a[0];
// 	while(i < argc - 2)
// 	{
// 		if(stack_a[i] > num)
// 		{
// 			num = stack_a[i];
// 			index = i;
// 		}
// 		i++;
// 	}
// 	return (index);
// }
#include "push_swap.h"

int findindexbiggest(int *stack_b, int argb)
{
	int i;
	int num;
	int	index;

	i = 1;
	index = 0;
	num = stack_b[0];
	while(i < argb - 1)
	{
		if(stack_b[i] > num)
		{
			num = stack_b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int findindexsmallest(int *stack_b, int argb)
{
	int i;
	int num;
	int	index;

	i = 1;
	index = 0;
	num = stack_b[0];
	while(i < argb - 1)
	{
		if(stack_b[i] < num)
		{
			num = stack_b[i];
			index = i;
		}	
		i++;
	}
	return (index);
}

int findspot(int num, int *stack_b, int argb)
{
	int i;

	i = 0;
	while (i < argb - 2)
	{
		if (isbiggest(num, stack_b, argb))
			return (findindexbiggest(stack_b, argb));
		if (issmallest(num, stack_b, argb))
			return (findindexsmallest(stack_b, argb) + 1);
		if ((issmallest(stack_b[i], stack_b, argb) && isbiggest(stack_b[i + 1], stack_b, argb)) || 
		(issmallest(stack_b[i + 1], stack_b, argb) && isbiggest(stack_b[i], stack_b, argb) && argb > 3))
		{
			i++;
			continue;
		}
		if ((num < stack_b[i] && num > stack_b[i + 1]))
			break;
		i++;
	}
	return(i + 1);
}