#include "push_swap.h"

int choosesize(int argc)
{
	if (argc < 100)
		return(5);
	else if (argc >= 100 && argc < 500)
		return (10);
	else
		return (30);
}

int exploretop(int  *stack_a, int size, int *stack_b, int argb)
{
	int i;
	int num;
	int	index;

	i = 1;
	index = 0;
	num = findspot(stack_a[0], stack_b, argb);
	while(i < size - 1)
	{
		if(findspot(stack_a[i], stack_b, argb) < num)
		{
			num = findspot(stack_a[i], stack_b, argb);
			index = i;
		}
		i++;
	}
	return (index);
}

int explorebottom(int  *stack_a, int argc, int size, int *stack_b, int argb)
{
	int i;
	int num;
	int	index;

	i = argc - 3;
	index = argc - 2;
	num = findspot(stack_a[argc - 2], stack_b, argb);
	while(i > argc - 2 - size)
	{
		if(findspot(stack_a[i], stack_b, argb) < num)
		{
			num = findspot(stack_a[i], stack_b, argb);
			index = i;
		}	
		i--;
	}
	return (index);
}