#include "sort.h"
/**
 * top_down_merge - reassemble divided array
 * @array_copy: copy of original array
 * @begin: index to begin
 * @middle: middle index
 * @end: end index
 * @array: original array
 * Return: void
 */
void top_down_merge(int *array_copy, int begin,
int middle, int end, int *array)
{
	int i, j, k;

	i = begin;
	j = middle;

	for (k = begin; k < end; k++)
	{
		if (i < middle && (j >= end || (array_copy[i] <= array_copy[j])))
		{
			array[k] = array_copy[i];
			i += 1;
		}
		else
		{
			array[k] = array_copy[j];
			j += 1;
		}
	}
	for (k = begin; k < end; k++)
	{
		array_copy[k] = array[k];
	}
}
/**
 * top_down_split_merge - Split the array
 * @array_copy: copy of original array
 * @begin: index to begin
 * @end: end index
 * @array: original array
 * Return: void
 */
void top_down_split_merge(int *array_copy, int begin, size_t end, int *array)
{
	int middle, i;

	if ((int)end - begin <= 1)
		return;
	middle = ((int)end + begin) / 2;
	/* printf("%d\n", middle); */
	top_down_split_merge(array_copy, begin, middle, array);
	top_down_split_merge(array_copy, middle, end, array);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = begin; i < middle; i++)
	{
		printf("%d", array[i]);
		if (i + 1 < middle)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = middle; i < (int)end; i++)
	{
		printf("%d", array[i]);
		if (i + 1 < (int)end)
			printf(", ");
	}
	printf("\n");
	top_down_merge(array_copy, begin, middle, end, array);
	printf("[Done]: ");
	for (i = begin; i < (int)end; i++)
	{
		printf("%d", array[i]);
		if (i + 1 < (int)end)
			printf(", ");
	}
	printf("\n");
}
/**
 * merge_sort - Sorts an array of integers using Merge-sort
 * @array: Pointer to the first element in the array
 * @size: The size of the given array
 */
void merge_sort(int *array, size_t size)
{
	int *array_copy;
	size_t i;

	array_copy = malloc(sizeof(*array_copy) * size);
	if (!array_copy)
		return;

	for (i = 0; i < size; i++)
	{
		array_copy[i] = array[i];
	}
	top_down_split_merge(array_copy, 0, size, array);
	free(array_copy);
}
