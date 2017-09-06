/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:42:54 by kkotliar          #+#    #+#             */
/*   Updated: 2017/06/10 16:42:56 by kkotliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_quick_sort(int *arr, int num)
{
	int	pivot;
	int	tmp;
	int	i;
	int j;
	
	i = 0;
	j = num;
	pivot = arr[num / 2];
	
	while(i <= j)
	{
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (j > 0)
		ft_quick_sort(arr, j);
	if (num > i)
		ft_quick_sort(arr, num - i);
}

void	ft_pivot(int *arr, int *pivot, char **argv, int arr_size)
{
	int i;
	
	if(!(arr = (int*)malloc(sizeof(int) * arr_size)))
		exit(0);
	i = 0;
	while (i < arr_size - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_quick_sort(arr, arr_size);
	*pivot = arr[arr_size / 2];
}
