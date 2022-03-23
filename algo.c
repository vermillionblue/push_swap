#include "push_swap.h"
// 8207 for stack of size 500 
//842 for stack of size 100

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

void	pushbackin(int *stack_a, int argc, int *stack_b, int argb)
{
	int	index;

	while(argb > 1)
	{
		if (isbiggest(stack_b[0], stack_b, argb))
		{
			push_ab(stack_b, stack_a, &argb, &argc);
			write(1, "pa\n", 3);
		}
		else
		{
			index = findindexbiggest(stack_b, argb);
			if (index < ((argb - 2) / 2) || index == ((argb - 2) / 2) || index == ((argb - 2) / 2) + 1)
				rotate_remainder(&index, stack_b, argb, 'b');
			else
			{
				index = argb - 1 - index;
				rotate_r_remainder(&index, stack_b, argb, 'b');
			}
		}
	}
}

void	forfiveandfour(int *stack_a, int *stack_b, int *argc,  int *argb)
{
	while (*argc > 3)
	{
		if (isbiggest(stack_a[0], stack_a, *argc) || issmallest(stack_a[0], stack_a, *argc))
			ft_rotate(stack_a, 'a', *argc);
		else
			pbandprint(stack_a, stack_b, argc, argb);
	}
	if (issmallest(stack_a[0], stack_a, *argc) && stack_b[0] < stack_b[1])
		ft_swapab(stack_a, stack_b);
	else if (issmallest(stack_a[0], stack_a, *argc))
		ft_swap(stack_a, 'a');
	pushbackin(stack_a, *argc, stack_b, *argb);
	rotate_r(stack_a, 'a', *argc);
	
}

void	forhundred(int *stack_a, int *stack_b, int *argc,  int *argb)
{
	int hold_bottom;
	int hold_top;
	int x;
	int s;
	int f;
	int size;

	size = choosesize(*argc);
	while(*argc > 1)
	{
		f = 0;
		hold_top = exploretop(stack_a, size, stack_b, *argb);
		hold_bottom = explorebottom(stack_a,*argc, size,  stack_b, *argb);
		if (*argc - 1 - hold_bottom < hold_top)
		{
			f = findspot(stack_a[hold_bottom], stack_b, *argb);
			x = *argc - 1 - hold_bottom;
			s = *argb - 1 - f;
			if (*argc - 1 - hold_bottom < hold_top)
			{
				if ((!(f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1)) && *argb >= 3 && f != 0)
				{
					while(s > 0 && x > 0)
					{	
						double_r_r(stack_a, stack_b, *argc, *argb);
						x--;
						s--;
					}
				}
				rotate_r_remainder(&x, stack_a, *argc, 'a');
				if (*argb < 3)
					pbandprint(stack_a, stack_b, argc, argb);
				else
				{
					if (f == 0)
						pbandprint(stack_a, stack_b, argc, argb);
					else
					{
						if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1) && *argb >= 3)
							rotate_remainder(&f, stack_b, *argb, 'b');
						else
							rotate_r_remainder(&s, stack_b, *argb, 'b');
						pbandprint(stack_a, stack_b, argc, argb);
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
					double_r(stack_a, stack_b, *argc, *argb);
					f--;
					hold_top--;
				}
			}
			rotate_remainder(&hold_top, stack_a, *argc, 'a');
			if (*argb < 3)
				pbandprint(stack_a, stack_b, argc, argb);
			else
			{
				if (f == 0)
					pbandprint(stack_a, stack_b, argc, argb);
				else
				{
					x = *argb - 1 - f;
					if ((f < ((*argb - 2) / 2) || f == ((*argb - 2) / 2) || f == ((*argb - 2) / 2) + 1) && *argb >= 3)
						rotate_remainder(&f, stack_b, *argb, 'b');
					else
						rotate_r_remainder(&x, stack_b, *argb, 'b');
					pbandprint(stack_a, stack_b, argc, argb);
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
if (argc < 5)
	forthree(argc, stack_a);
if (argc <= 6)
	forfiveandfour(stack_a, stack_b, &argc, &argb);
if (argc > 6)
	forhundred(stack_a, stack_b, &argc, &argb);
return (0);
}