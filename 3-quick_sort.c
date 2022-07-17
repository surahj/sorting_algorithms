#include "sort.h"

void quick_sort(int *array, size_t size);
void swap_int(int *a, int *b);
void partion_sort(int *array, size_t size, int lower_b, int upper_b);
int lomuto_partition(int *array, size_t size, int lower_b, int upper_b);

/**
 * swap_int - swap ywo integer
 * @a: first integer to swap
 * @b: second integer to swap
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - lomuto_partition the array
 * @array: array of integers to sort
 * @size: size of the array
 * @lower_b: lower boundary of the array
 * @upper_b: upper boundary of the array
 * Return: return the position of the pivot
 */
int lomuto_partition(int *array, size_t size, int lower_b, int upper_b)
{
	int *pivot;
	int current_index, below;

	pivot = array + upper_b;
	for (current_index = below = lower_b; below < upper_b; below++)
	{
		if (array[below] < *pivot)
		{
			if (current_index < below)
			{
				swap_int(array + below, array + current_index);
				print_array(array, size);
			}
			current_index++;
		}
	}

	if (array[current_index] > *pivot)
	{
		swap_int(array + current_index, pivot);
		print_array(array, size);
	}

	return (current_index);
}

/**
 * quick_sort - quick sort
 * @array: array of integers to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	partion_sort(array, size, 0, size - 1);
}

/**
 * partion_sort - partition the array and sort recursively
 * @array: array of element to sort
 * @size: size of the array to sort
 * @lower_b: lower boundary of the list
 * @upper_b: upper boundary of the list
 */

void partion_sort(int *array, size_t size, int lower_b, int upper_b)
{
	int location;

	if (lower_b < upper_b)
	{
		location = lomuto_partition(array, size, lower_b, upper_b);
		partion_sort(array, size, lower_b, location - 1);
		partion_sort(array, size, location + 1, upper_b);
	}
}
