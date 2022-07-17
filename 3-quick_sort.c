#include "sort.h"

void quick_sort(int *array, size_t size);
void swap_int(int *a, int *b);
void partion_sort(int *array, size_t size, size_t lower_b, size_t upper_b);
int partion(int *array, size_t size, size_t lower_b, size_t upper_b);

/**
 * swap_int - swap ywo integer
 * @a: first integer to swap
 * @b: second integer to swap
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partion - partion the array
 * @array: array of integers to sort
 * @size: size of the array
 * @lower_b: lower boundary of the array
 * @upper_b: upper boundary of the array
 * Return: return the position of the pivot
 */

int partion(int *array, size_t size, size_t lower_b, size_t upper_b)
{
	size_t current_index = lower_b, i;
	int *pivot = array + upper_b;

	for (i = lower_b; i < upper_b - 1; i++)
	{
		if (array[i] < *pivot)
		{
			if (current_index < i)
			{
				swap_int(array + i, array + current_index);
				current_index++;
				print_array(array, size);
			}
		}
	}
	if (array[current_index] > *pivot)
	{
		swap_int(pivot, array + current_index);
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

void partion_sort(int *array, size_t size, size_t lower_b, size_t upper_b)
{
	size_t start = lower_b, end = upper_b;
	size_t location;

	if (start < end)
	{
		location = partion(array, size, start, end);
		partion_sort(array, size, start, location);
		partion_sort(array, size, location + 1, end);
	}
}
