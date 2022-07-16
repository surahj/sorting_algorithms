#include <stdio.h>
#include "sort.h"

void swap_integer(int *a, int *b);
void selection_sort(int *array, size_t size);

/**
 * selection_sort - sort the element of the array in ascending order
 * @array: array of element to sort
 * @size: size of the array to sort
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = (array + i);
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min_index)
				min_index = (array + j);
		}
		if (min_index != (array + i))
		{
			swap_integer(array + i, min_index);
			print_array(array, size);
		}
	}
}

/**
 * swap_integer - swap two integers
 * @a: first integer to swap
 * @b: second integer to swap
 */

void swap_integer(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
