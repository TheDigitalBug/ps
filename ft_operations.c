/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:47:06 by kkotliar          #+#    #+#             */
/*   Updated: 2017/06/05 15:11:39 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_create_stack(t_stack *name, int stack_size)
{
	if(!(name = (t_stack*)malloc(sizeof(t_stack))))
		exit(0);
	if(!(name->stack = (int*)malloc(sizeof(int) * (stack_size))))
		exit(0);
	name->size = stack_size;
	name->index = -1;
	return(name);
}

void	ft_print_stacks(t_stack *a, t_stack *b, char *comment)
{
	int i;
	
	printf("%s\n", comment);
	if (a->index > b->index)
	{
		i = a->index;
		while (i != -1)
		{
			printf("%4d ", a->stack[i]);
			if (i <= b->index)
				printf("%4d", b->stack[i]);
			else
				printf("%5s", " ");
			printf("\n");
			i--;
		}
	}
	else
	{
		i = b->index;
		while (i != -1)
		{
			if (i <= a->index)
				printf("%4d ", a->stack[i]);
			else
				printf("%5s", " ");
				
			printf("%4d", b->stack[i]);
			printf("%s","\n");
			i--;
		}
	}
	printf("%5s %5s", "- ", "-\n");
	printf("%5s %5s", "a ", "b\n");
	printf("------------------\n");
}






void	ft_sa(t_stack *a)
{
	int tmp;

	if (a->index >= 1)
	{
		tmp = a->stack[a->index];
		a->stack[a->index] = a->stack[a->index - 1];
		a->stack[a->index - 1] = tmp;
	}
}

void	ft_sb(t_stack *b)
{
	int tmp;
	
	if (b->index >= 1)
	{
		tmp = b->stack[b->index];
		b->stack[b->index] = b->stack[b->index - 1];
		b->stack[b->index - 1] = tmp;
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
}

//pa : push a - take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.

void	ft_pa(t_stack *a, t_stack *b)
{
	if (b->index >= 0 && a->index < STACK_SIZE + 1)
	{
		a->stack[++(a->index)] = b->stack[(b->index)--];
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (a->index >= 0 && b->index < STACK_SIZE + 1)
	{
		b->stack[++(b->index)] = a->stack[(a->index)--];
	}
}

//ra : rotate a - shift up all elements of stack a by 1.
//The first element becomes the last one.

void	ft_ra(t_stack *a)
{
	int tmp;
	int i;
	
	if (a->index >= 1)
	{
		tmp = a->stack[a->index];
		i = a->index;
		while(i)
		{
			a->stack[i] = a->stack[i - 1];
			i--;
		}
		a->stack[0] = tmp;
	}
}

void	ft_rb(t_stack *b)
{
	int tmp;
	int i;

	if (b->index >= 1)
	{
		tmp = b->stack[b->index];
		i = b->index;
		while(i)
		{
			b->stack[i] = b->stack[i - 1];
			i--;
		}
		b->stack[0] = tmp;
	}
}

// rr : ra and rb at the same time.

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
}

//rra : reverse rotate a - shift down all elements of stack a by 1.
//The flast element becomes the first one

void	ft_rra(t_stack *a)
{
	int tmp;
	int i;
	
	if (a->index >= 1)
	{
		tmp = a->stack[0];
		i = 0;
		while(i < a->index)
		{
			a->stack[i] = a->stack[i + 1];
			i++;
		}
		a->stack[a->index] = tmp;
	}
}

void	ft_rrb(t_stack *b)
{
	int tmp;
	int i;
	
	if (b->index >= 1)
	{
		tmp = b->stack[0];
		i = 0;
		while(i < b->index)
		{
			b->stack[i] = b->stack[i + 1];
			i++;
		}
		b->stack[b->index] = tmp;
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
}




