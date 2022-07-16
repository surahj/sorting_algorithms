#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sort the element of the array in ascending order
 * @array: array of element to sort
 * @size: size of the array to sort
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_index, temp;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			print_array(array, size);
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
		}
	}
}
