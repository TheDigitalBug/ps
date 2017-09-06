
#include "push_swap.h"


int	ft_pop(t_stack *name, int *tmp)
{
	if (name->index >= 0)
	{
		*tmp = name->stack[name->index];
		name->index--;
		return (1);
	}
	return (0);
}

int	ft_is_sort(t_stack *name)
{
    int i;
	
    i = name->index;
    while (i > 0)
    {
        if (name->stack[i] > name->stack[i - 1])
        {
           // printf("%s\n", "NON Sorted");
            return (0);
        }
        i--;
    }
   // printf("%s\n", "Sorted");
    return (1);
}

int	ft_is_sort_reverse(t_stack *name)
{
    int i;
    
    i = name->index;
    while (i > 0)
    {
        if (name->stack[i] < name->stack[i - 1])
        {
            printf("%s\n", "NON Reverse Sorted");
            return (0);
        }
        i--;
    }
    printf("%s\n", "Reverse Sorted");
    return (1);
}
