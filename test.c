#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

	printarr(*argc, stack_a);
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
		rotate_r_push(stack_b, argc);
		stack_b[0] = temp;
		*argb = *argb + 1;
	}
	write(1, "pa\n", 3);
	printarr(*argc, stack_a);
	printf("++++++++++++++++++++++++++++\n");
	printarr(*argb, stack_b);
	write(1, "\n", 3);
	printf("argc : %d\n", *argc);
	printf("argb : %d\n", *argb);
}

int main()
{
	int argc = 7;
	int *argc2 = &argc;

	int x = 0;
	int *argb = &x;

	int arr[6] = {1, 2, 3, 4, 5, 6};
	int *stack_b = calloc(6, sizeof(int));
	push_ab(arr, stack_b, argc2, argb);
	push_ab(arr, stack_b, argc2, argb);
	push_ab(arr, stack_b, argc2, argb);
	push_ab(arr, stack_b, argc2, argb);
}
