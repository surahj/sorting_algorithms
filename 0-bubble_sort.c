#include <stdio.h>
#include "sort.h"

void swap_integer(int *a, int *b);
void bubble_sort(int *array, size_t size);

/**
 * bubble_sort - sort array in ascending order
 * @array: array of element to sort
 * @size: size of the elemet to sort
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_integer(array + j, array + j + 1);
				print_array(array, size);
			}
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
