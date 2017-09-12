/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:38:36 by kkotliar          #+#    #+#             */
/*   Updated: 2017/06/05 14:40:56 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft/libft.h"

# define COL_RED "\x1B[31m"
# define COL_DEFAULT "\e[39m"
# define STACK_OVERFLAW 0
# define STACK_SIZE 2048


# define PR(expr) printf("%s\n", expr)
# define WR(expr) write(1, expr "\n", 2)
# define PRINTOPERATION 1

typedef struct	s_stack
{
	int			*stack;
	int			index;
	int			size;
}				t_stack;

void			ft_sa(t_stack *a);
void			ft_sb(t_stack *b);
void			ft_ss(t_stack *a, t_stack *b);
void			ft_pa(t_stack *a, t_stack *b);
void			ft_pb(t_stack *a, t_stack *b);
void			ft_ra(t_stack *a);
void			ft_rb(t_stack *b);
void			ft_rr(t_stack *a, t_stack *b);
void			ft_rra(t_stack *a);
void			ft_rrb(t_stack *b);
void			ft_rrr(t_stack *a, t_stack *b);
void			ft_print_stack(t_stack *name, char *comment);
void			ft_print_stacks(t_stack *a, t_stack *b, char *comment);
t_stack			*ft_create_stack(int stack_size);








void	ft_put_to_stacks(t_stack *name,char **argv, int argc);



int         ft_is_sort(t_stack *name);
int         ft_is_sort_reverse(t_stack *name);

int	ft_pop(t_stack *name, int *tmp);



void	ft_simple_sort(t_stack *a, t_stack *b);
void	ft_simple_sort2(t_stack *a, t_stack *b);


void quicksort(int *arr, int len);




#endif
