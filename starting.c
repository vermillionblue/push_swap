#include "push_swap.h"

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