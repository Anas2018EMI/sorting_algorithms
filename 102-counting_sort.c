#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *output_array;
	size_t i, max_val;

	if (array == NULL || size < 2)
		return;
	max_val = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max_val)
			max_val = array[i];
	}
	counting_array = malloc(sizeof(int) * (max_val + 1));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max_val; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	print_array(counting_array, max_val + 1);
	for (i = 1; i <= max_val; i++)
		counting_array[i] += counting_array[i - 1];

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(counting_array);
	free(output_array);
}
