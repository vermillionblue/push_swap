
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include <limits.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void printarr(int argc, int	*arr)
{
	int i = 0;
	while(i < argc -1)
	{
		printf("%d\n", arr[i]);
		i++;
	}	
}

void rotate_push(int *arr, int *argc)
{
	int temp;
	int temp2;
	int i;

	i = *argc - 2;
	temp = arr[*argc - 2];
	while(i >= 0)
	{
		temp2 = arr[i];
		arr[i] = temp;
		temp = temp2;
		i--;
	}

}

void rotate_r_push(int *arr, int *argc)
{
	int temp;
	int temp2;
	int i;

	i = 1;
	temp = arr[0];
	while(i < *argc)
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

	temp = stack_a[0];
	rotate_push(stack_a, argc);
	*argc = *argc - 1;
	if (*argb == 0)
	{
		stack_b[0] = temp;
		*argb = 2;
	}
	else
	{
		rotate_r_push(stack_b, argb);
		stack_b[0] = temp;
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
		write(1 , "ra\n", 3);
	if(c == 'b')
		write(1 , "rb\n", 3);
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

int ft_checkdup(char **arr)
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
	if(!ft_checkdup(argv))
		return (0);
	return (1);
}

int	issmallest(int num, int *arr, int argc)
{
	int	i;

	i = 0;
	while(i < argc - 1)
	{
		if (num > arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	isbiggest(int num, int *arr, int argc)
{
	int	i;

	i = 0;
	while(i <= argc - 2)
	{
		if (num < arr[i])
			return (0);
		i++;
	}
	return (1);
}

int issorted(int *arr, int argc)
{
	int i;

	i = 0;
	while(i < argc - 2)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}


void forfour(int *stack_a,int *argc,  int *argb)
{
	int	*stack_b;

	stack_b = ft_calloc(*argc - 1, sizeof(int));
	while(*argc > 3)
	{
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
		push_ab(stack_a, stack_b, argc, argb);
		write(1, "pb\n", 3);
		if (issmallest(stack_a[0], stack_a, *argc) || isbiggest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);
		if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && *argb > 2 && *argc > 2)
			ft_swapab(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1] && *argc > 2)
			ft_swap(stack_a, 'a');
		else if (stack_b[0] < stack_b[1] && *argb > 2)
			ft_swap(stack_b, 'b');
		if (issmallest(stack_b[0], stack_b, *argb) && *argb > 2)
			ft_rotate(stack_b, 'b', *argc);
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


void forthree(int argc, int *stack_a)
{
	while(!(issorted(stack_a, argc)))
	{
		if (isbiggest(stack_a[0], stack_a, argc)
		&& issmallest(stack_a[1], stack_a, argc) && argc == 4)
			ft_rotate(stack_a, 'a', argc);
		if (stack_a[0] > stack_a[1])
			ft_swap(stack_a, 'a');
		if (!(isbiggest(stack_a[argc - 2], stack_a, argc)))
			rotate_r(stack_a, 'a', argc);
	}
}

int *placenums(int argc, char **argv)
{
	int	i;
	int	k;
	int	*stack_a;

	i = 1;
	k = 0;
	stack_a = ft_calloc(argc - 1, sizeof(int));
	while(argv[i])
	{
		stack_a[k] = ft_atoi(argv[i]);
		i++;
		k++;
	}
	return (stack_a);
}

int main(int argc, char **argv)
{
 int	*stack_a;
 int	*argc0;
 int	x;
 int	*argb;

x = 0;
argb = &x;
argc0 = &argc;
 if (!(senderror(argv)))
		return (write(2, "Error\n", 6));
stack_a = placenums(argc, argv);
if (argc == 2 || issorted(stack_a, argc))
	return (0);
if (argc <= 4)
	forthree(argc, stack_a);
if (argc >= 5)
	forfour(stack_a, argc0, argb);
return (0);
}