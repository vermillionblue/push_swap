#include "push_swap.h"

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
