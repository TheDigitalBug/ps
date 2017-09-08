
#include "push_swap.h"

void	ft_simple_sort(t_stack *a, t_stack *b)
{
	int operation_counter = 0;
	int i;

	i = 0;
	while(a->index != -1)
	{
		if (a->stack[a->index] > a->stack[a->index - 1])
			ft_ra(a);
		else
		{
			ft_sa(a);
			ft_ra(a);
		}
		i++;
		if (i > a->index)
		{
			ft_pb(a, b);
			i = 0;
		}
	}
	while(b->index != -1)
	{
		ft_pa(a, b);
		operation_counter++;
	}
}
