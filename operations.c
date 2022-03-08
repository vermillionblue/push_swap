#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include <limits.h>

void rotate_push(int *arr, int argc)
{
	int temp;
	int start;
	int temp2;
	int i;

	i = argc - 2;
	start = arr[0];
	temp = arr[argc - 2];
	while(i >= 0)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i--;
	}
	arr[argc - 2] = start;
}

void rotate_r_push(int *arr, int argc)
{
	int temp;
	int end;
	int temp2;
	int i;

	i = 1;
	end = arr[argc - 2];
	temp = arr[0];
	while(i < argc - 1)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i++;
	}
}


void	push_ab(int	*stack_a, int	*stack_b, int *argc, int *argb)
{
	int	temp;

	printarr(*argc, stack_a);
	temp = stack_a[0];
	rotate_push(stack_a, *argc);
	*argc = *argc - 1;
	if (*argb == 0)
	{
		stack_b[0] = temp;
		*argb = 2;
	}
	else
	{
		rotate_r_push(stack_a, *argc);
		*argb = *argb + 1;
	}
}

void ft_rotate(int *arr, char c, int argc)
{
	int temp;
	int start;
	int temp2;
	int i;

	i = argc - 2;
	start = arr[0];
	temp = arr[argc - 2];
	while(i >= 0)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i--;
	}
	arr[argc - 2] = start;
	if(c == 'a')
		write(1 , "rra\n", 4);
	if(c == 'b')
		write(1 , "rrb\n", 4);
}

void rotate_r(int *arr, char c, int argc)
{
	int temp;
	int end;
	int temp2;
	int i;

	i = 1;
	end = arr[argc - 2];
	temp = arr[0];
	while(i < argc - 1)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i++;
	}
	arr[0] = end;
	if(c == 'a')
		write(1 , "rra\n", 4);
	if(c == 'b')
		write(1 , "rrb\n", 4);
}

void ft_swap(int *arr, char c)
{
	int temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	if(c == 'a')
		write(1 , "sa\n", 3);
	if(c == 'b')
		write(1 , "sb\n", 3);
}

void ft_swapab(int *arr1, int *arr2)
{
	ft_swap(arr1, 'c');
	ft_swap(arr2, 'c');
	write(1 , "ss\n", 3);
}