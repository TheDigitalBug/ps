/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:39:14 by kkotliar          #+#    #+#             */
/*   Updated: 2017/06/05 15:07:26 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int operation_counter = 0;

/*
** PUT income array (1,2,3,4) to stack:
** |1|
** |2|
** |3|
** |4|
*/

void	ft_put_to_stacks(t_stack *name,char **argv, int argc)
{
	int	i;
	int	j;
	
	i = 0;
	j = argc - 1;
	while (i < argc - 1)
	{
		name->stack[i] = ft_atoi(argv[j]);
		i++;
		j--;
	}
	name->index = argc - 2;
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc == 1)
		return((int)write(1, "usage: ./push_swap num1 num2 ... numN\n", 38));
	a = ft_create_stack(STACK_SIZE);
	b = ft_create_stack(STACK_SIZE);
	
	ft_put_to_stacks(a, argv, argc);

	ft_print_stacks(a, b, "init a b");
	
	ft_simple_sort2(a, b);
	
	ft_print_stacks(a, b, "after sort");

}
