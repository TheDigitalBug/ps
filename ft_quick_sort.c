
#include "push_swap.h"


void quicksort(int *arr, int len)
{
	int temp;
	int i;
	int j;
	int pivot;
	
	if (len <= 1)
		return;
	
	pivot = arr[len / 2];
	i = 0;
	j = len - 1;
	
	while(1)
	{
		while (arr[i] > pivot)
			i++;
		while (arr[j] < pivot)
			j--;
		
		if (i >= j)
			break;
		
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		
		i++;
		j--;
	}
	
	quicksort(arr, i);
	quicksort(arr + i, len - i);
}
