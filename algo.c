#include "push_swap.h"
#define SIZE 5

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


		// if ((num > stack_b[0] && num < stack_b[argb - 2]) || (num < stack_b[0] && num > stack_b[argb - 1]))
		// 	return (0);
		if ((issmallest(stack_b[i], stack_b, argb) && isbiggest(stack_b[i + 1], stack_b, argb)) || (issmallest(stack_b[i + 1], stack_b, argb) && isbiggest(stack_b[i], stack_b, argb)))
		{
			i++;
			continue;
		}

		//removed || (num < stack_b[i] && num > stack_b[i + 1])
		//printf("%d vs %dxxxx %d\n", stack_b[i], stack_b[i + 1], num);
		if ((num < stack_b[i] && num > stack_b[i + 1]))
		{
			//printf("%d vs %dxxxx %d\n", stack_b[i], stack_b[i + 1], num);
			break;
		}
		i++;
	}
	return(i + 1);
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

int exploretop(int  *stack_a)
{
	int i;
	int num;
	int	index;

	i = 1;
	index = 0;
	num = stack_a[0];
	while(i < SIZE - 1)
	{
		if(stack_a[i] < num)
		{
			num = stack_a[i];
			index = i;
		}
			
		i++;
	}
	return (index);
}

int explorebottom(int  *stack_a, int argc)
{
	int i;
	int num;
	int	index;

	i = argc - 3;
	index = argc - 2;
	num = stack_a[argc - 2];
	while(i > argc - 2 - SIZE)
	{
		if(stack_a[i] < num)
		{
			num = stack_a[i];
			index = i;
		}	
		i--;
	}
	return (index);
}

int	biggestnumindex(int *stack_a, int argc)
{
	int i;
	int num;
	int	index;

	i = 1;
	num = stack_a[0];
	while(i < argc - 2)
	{
		if(stack_a[i] > num)
		{
			num = stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void forhundred(int *stack_a, int *argc,  int *argb)
{
	int hold_bottom;
	int hold_top;
	int x;
	int	*stack_b;

	stack_b = ft_calloc(*argc - 1, sizeof(int));
	while(*argc >= SIZE - 1)
	{
		int f = 0;
		hold_top = exploretop(stack_a);
		hold_bottom = explorebottom(stack_a, *argc);
		//printf("++++++");
		if (*argc - 1 - hold_bottom < hold_top)
		{
			f = findspot(stack_a[hold_bottom], stack_b, *argb);
			x = *argc - 1 - hold_bottom;
			while(x > 0)
			{
				rotate_r(stack_a, 'a', *argc);
				x--;
			}
			if (*argb < 3)
			{
				push_ab(stack_a, stack_b, argc, argb);
				write(1, "pb\n", 3);
			}
		}
		else
		{
			f = findspot(stack_a[hold_top], stack_b, *argb);
			while(hold_top > 0)
			{
				ft_rotate(stack_a, 'a', *argc);
				hold_top--;
			}
			if (*argb < 3)
			{
				push_ab(stack_a, stack_b, argc, argb);
				write(1, "pb\n", 3);
			}
		}

			
		if (*argb < 3)
		{
			push_ab(stack_a, stack_b, argc, argb);
			write(1, "pb\n", 3);
		}
		else
		{
			int f = 0;
			f = findspot(stack_a[0], stack_b, *argb);
			if (f == 0)
			{	
				push_ab(stack_a, stack_b, argc, argb);
				write(1, "pb\n", 3);
			}
			else
			{
				if (f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1)
				{
					
					while(f > 0)
					{
						//printf("++++ppp++++\n");
						ft_rotate(stack_b, 'b', *argb);
						f--;
					}
				}
				else
				{
					
					int x;
					x = *argb - 1 - f;

					//printf("++++++++x %d\n", x);
					while(x > 0)
					{	
						rotate_r(stack_b, 'b', *argb);
						x--;
					}
				}
				push_ab(stack_a, stack_b, argc, argb);
				write(1, "pb\n", 3);
			}
		}
		
		
	}
	while(*argc != 1)
	{
		int f = 0;
			f = findspot(stack_a[0], stack_b, *argb);
			//printf("++++spot+++%d for %d in stack_b\n", f, stack_a[0]);
			//printarr(*argb, stack_b);
			//printf("++++ccc++++%d\n", hold_top);
			if (f == 0)
			{	
				push_ab(stack_a, stack_b, argc, argb);
				write(1, "pb\n", 3);
			}
			else
			{
				if (f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1)
				{
					
					while(f > 0)
					{
						//printf("++++ppp++++\n");
						ft_rotate(stack_b, 'b', *argb);
						f--;
					}
				}
				else
				{
					
					int x;
					x = *argb - 1 - f;

					//printf("++++++++x %d\n", x);
					while(x > 0)
					{	
						rotate_r(stack_b, 'b', *argb);
						x--;
					}
				}
				push_ab(stack_a, stack_b, argc, argb);
				write(1, "pb\n", 3);
			}
		if (*argc == 1)
			break;
	}

	while(*argb > 1)
	{
		if (isbiggest(stack_b[0], stack_b, *argb))
		{
			push_ab(stack_b, stack_a, argb, argc);
			write(1, "pa\n", 3);
		}
		else
			{
				int index;
				index = biggestnumindex(stack_b, *argb);
				if (index < ((*argb - 2) / 2) || index == ((*argb - 2) / 2) || index == ((*argb - 2) / 2) + 1)
				{
					while(index > 0)
					{
						ft_rotate(stack_b, 'b', *argb);
						index--;
					}

				}
				else
				{
					int x;
					x = *argb - 1 - index;
					while(x > 0)
					{
						rotate_r(stack_b, 'b', *argb);
						x--;
					}
				}

			}
	}
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
if (argc > 5)
	forhundred(stack_a, argc0, argb);
return (0);
}