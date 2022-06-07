#include "search_algos.h"

/**
 * search - searches value in sorted array of integers
 * @array: pointer first element of the array
 * @value: is the value to search for
 * @low: index to start with on the left
 * @high: index on the right
 * Return: the index where value is located -1 if not found
*/
int search(int *array, int value, int low, int high)
{
	int i, mid;

	mid = low +  (high - low) / 2;
	if (low == high)
	{
		if (value < array[low] || value > array[high])
		{
			printf("Searching in array: %d\n", array[mid]);
			return (-1);
		}
		return (low);
	}
	printf("Searching in array:");
	for (i = low; i <= high; i++)
	{
		if (i != high)
			printf(" %d,", array[i]);
		else
			printf(" %d\n", array[i]);
	}

	if (array[mid] < value)
		return (search(array, value, mid + 1, high));
	else
		return (search(array, value, low, mid));
}

/**
 * advanced_binary - searches value in sorted array of integers
 * @array: pointer first element of the array
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: the index where value is located
*/
int advanced_binary(int *array, size_t size, int value)
{
	int result;

	result = search(array, value, 0, size - 1);
	return (result);
}
