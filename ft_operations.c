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

t_stack *ft_create_stack(int stack_size)
{
	t_stack *name;

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
	extern int operation_counter;
	
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
	printf("-----nb of operations = %d -----------\n", operation_counter);
}

void	ft_sa(t_stack *a)
{
	int tmp;
	extern int operation_counter;

	if (a->index >= 1)
	{
		tmp = a->stack[a->index];
		a->stack[a->index] = a->stack[a->index - 1];
		a->stack[a->index - 1] = tmp;
		(PRINTOPERATION) ? write(1, "sa\n", 3) : 0;
		operation_counter++;
	}
}

void	ft_sb(t_stack *b)
{
	int tmp;
	extern int operation_counter;
	
	if (b->index >= 1)
	{
		tmp = b->stack[b->index];
		b->stack[b->index] = b->stack[b->index - 1];
		b->stack[b->index - 1] = tmp;
		(PRINTOPERATION) ? write(1, "sb\n", 3) : 0;
		operation_counter++;
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	extern int operation_counter;
	
	ft_sa(a);
	ft_sb(b);
	(PRINTOPERATION) ? write(1, "ss\n", 3) : 0;
	operation_counter++;
}

//pa : push a - take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.

void	ft_pa(t_stack *a, t_stack *b)
{
	extern int operation_counter;
	
	if (b->index >= 0 && a->index < STACK_SIZE + 1)
	{
		a->stack[++(a->index)] = b->stack[(b->index)--];
		(PRINTOPERATION) ? write(1, "pa\n", 3) : 0;
		operation_counter++;
	}
}

void	ft_pb(t_stack *a, t_stack *b)
{
	extern int operation_counter;
	
	if (a->index >= 0 && b->index < STACK_SIZE + 1)
	{
		b->stack[++(b->index)] = a->stack[(a->index)--];
		(PRINTOPERATION) ? write(1, "pb\n", 3) : 0;
		operation_counter++;
	}
}

//ra : rotate a - shift up all elements of stack a by 1.
//The first element becomes the last one.

void	ft_ra(t_stack *a)
{
	int tmp;
	int i;
	extern int operation_counter;
	
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
		(PRINTOPERATION) ? write(1, "ra\n", 3) : 0;
		operation_counter++;
	}
}

void	ft_rb(t_stack *b)
{
	int tmp;
	int i;
	extern int operation_counter;

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
		(PRINTOPERATION) ? write(1, "rb\n", 3) : 0;
		operation_counter++;
	}
}

// rr : ra and rb at the same time.

void	ft_rr(t_stack *a, t_stack *b)
{
	extern int operation_counter;
	
	ft_ra(a);
	ft_rb(b);
	(PRINTOPERATION) ? write(1, "rr\n", 3) : 0;
	operation_counter++;
}

//rra : reverse rotate a - shift down all elements of stack a by 1.
//The flast element becomes the first one

void	ft_rra(t_stack *a)
{
	int tmp;
	int i;
	extern int operation_counter;
	
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
		(PRINTOPERATION) ? write(1, "rra\n", 4) : 0;
		operation_counter++;
	}
}

void	ft_rrb(t_stack *b)
{
	int tmp;
	int i;
	extern int operation_counter;
	
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
		(PRINTOPERATION) ? write(1, "rrb\n", 4) : 0;
		operation_counter++;
	}
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	extern int operation_counter;
	
	ft_rra(a);
	ft_rrb(b);
	(PRINTOPERATION) ? write(1, "rrr\n", 4) : 0;
	operation_counter++;
}
