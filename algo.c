#include "push_swap.h"

//30 for 500 nums  // 29 in loop   Mean: 8102 for stack of size 500
//10 for 100 nums	 Mean: 915 for stack of size 100 
// 5 for 20 nums     Mean: 74 for stack of size 20 

//to do
//remove var size and add the index to explore bottom and explore top

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

void	pushbackin(int *stack_a, int argc, int *stack_b, int argb)
{
	int index;
	int x;
	while(argb > 1)
	{
		if (isbiggest(stack_b[0], stack_b, argb))
		{
			push_ab(stack_b, stack_a, &argb, &argc);
			write(1, "pa\n", 3);
		}
		else
			{
				
				index = biggestnumindex(stack_b, argb);
				if (index < ((argb - 2) / 2) || index == ((argb - 2) / 2) || index == ((argb - 2) / 2) + 1)
				{
					while(index > 0)
					{
						ft_rotate(stack_b, 'b', argb);
						index--;
					}

				}
				else
				{
					x = argb - 1 - index;
					while(x > 0)
					{
						rotate_r(stack_b, 'b', argb);
						x--;
					}
				}

			}
	}
}
void forhundred(int *stack_a, int *stack_b, int *argc,  int *argb)
{
	int hold_bottom;
	int hold_top;
	int x;

	while(*argc > 1)
	{
		int f = 0;
		int size = 29;
		hold_top = exploretop(stack_a, size, stack_b, *argb);
		hold_bottom = explorebottom(stack_a,*argc, size,  stack_b, *argb);
		if (*argc - 1 - hold_bottom < hold_top)
		{
			f = findspot(stack_a[hold_bottom], stack_b, *argb);
			x = *argc - 1 - hold_bottom;
			int s;
			s = *argb - 1 - f;
			if (*argc - 1 - hold_bottom < hold_top)
			{
			if ((!(f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1)) && *argb >= 3 && f != 0)
			{
				while(s > 0 && x > 0)
				{	
					rotate_r(stack_a, 'c', *argc);
					rotate_r(stack_b, 'c', *argb);
					write(1, "rrr\n", 4);
					x--;
					s--;
				}

			}
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
			else
			{

				if (f == 0)
				{	
					push_ab(stack_a, stack_b, argc, argb);
					write(1, "pb\n", 3);
				}
			else
			{
				if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1) && *argb >= 3)
				{
					while(f > 0)
					{
						ft_rotate(stack_b, 'b', *argb);
						f--;
					}
				}
				else
				{
					
					while(s > 0)
					{	
						rotate_r(stack_b, 'b', *argb);
						s--;
					}
				}
				push_ab(stack_a, stack_b, argc, argb);
				write(1, "pb\n", 3);
			}
			}
			
		}
		}
		else
		{
			f = findspot(stack_a[hold_top], stack_b, *argb);
			if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1) && *argb >= 3 && f != 0)
			{
				while(hold_top > 0 && f > 0)
				{
					
					ft_rotate(stack_b, 'c', *argb);
					ft_rotate(stack_a, 'c', *argc);
					write(1, "rr\n", 3);
					f--;
				
					hold_top--;
				}
			}
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
			else
			{
				if (f == 0)
				{	
					push_ab(stack_a, stack_b, argc, argb);
					write(1, "pb\n", 3);
				}
				else
			{
				if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1) && *argb >= 3)
				{
					
					while(f > 0)
					{
					
						ft_rotate(stack_b, 'b', *argb);
						f--;
					}
				}
				else
				{
					
					int x;
					x = *argb - 1 - f;
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
		}
	pushbackin(stack_a, *argc, stack_b, *argb);
}

int main(int argc, char **argv)
{
 int	*stack_b;
 int	*stack_a;
 int	argb;

stack_b = ft_calloc(argc - 1, sizeof(int));
argb = 0;
 if (!(senderror(argv)))
		return (write(2, "Error\n", 6));
stack_a = placenums(argc, argv);
if (argc == 2 || issorted(stack_a, argc))
	return (0);
if (argc <= 6)
	forthree(argc, stack_a);
// if (argc == 6)
// 	forfive()
if (argc > 6)
	forhundred(stack_a, stack_b, &argc, &argb);
return (0);
}