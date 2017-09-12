
#include "push_swap.h"

void	ft_simple_sort(t_stack *a, t_stack *b)
{
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
	}
}

void	ft_simple_sort2(t_stack *a, t_stack *b)
{
	int tmp;
	int flag;

	
	while(a->index != -1)
	{
		flag = 1;
		tmp = a->stack[a->index];
		while(b->index != -1 && (b->stack[b->index] > tmp))
		{
			if (flag == 1)
			{
				ft_ra(a);
				flag = 0;
			}
			ft_pa(a, b);
		}
		if (flag == 0)
		{
			ft_rra(a);
			ft_pb(a, b);
		}
		ft_pb(a, b);
	}
	while(b->index != -1)
	{
		ft_pa(a, b);
	}
}
