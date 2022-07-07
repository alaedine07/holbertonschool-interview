#include "sort.h"

/**
 * get_max - gets the max of an array
 * @array: A pointer to the first element of array of integer
 * @size: The size of the array
 *
 * Return: An integer max
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort - counts sort
 * @array: A pointer to the first element of array of integer
 * @size: The size of the array
 * @place: Place to be counted
 */
void counting_sort(int *array, size_t size, int place)
{
	size_t i;
	int j, x, *sld_container, *output;

	sld_container = malloc(sizeof(int) * (10));
		if (!sld_container)
			return;
		for (j = 0; j < 10; j++)
			sld_container[j] = 0;
		for (i = 0; i < size; i++)
		{
			j = (array[i] / place) % 10;
			sld_container[j] += 1;
		}
		for (j = 0; j < 10; j++)
			sld_container[j] += sld_container[j - 1];

		output = malloc(sizeof(int) * size);
		if (!output)
		{
			free(sld_container);
			return;
		}
		for (i = size - 1; (int)i >= 0 ; i--)
		for (j = 0; j < 10; j++)
		{
			if ((array[i] / place) % 10 == j)
			{
				x = sld_container[j] - 1;
				sld_container[j] -= 1;
				output[x] = array[i];
			}
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
	free(output);
	free(sld_container);
}

/**
 * radix_sort - sorts an array of intergers in ascending order
 * @array: A pointer to the first element of array of integer
 * @size: The size of the array
 *
 * Description: This function sorts an array of interger in ascending order
 * using the radix_sort following the LSD (Least Significant Digits) algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int place;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	for (place = 1; max / place > 0; place *= 10)
	{
		counting_sort(array, size, place);
		print_array(array, size);
	}
}
