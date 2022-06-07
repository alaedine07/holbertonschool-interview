#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap between two elements in an array
 * @a: first element
 * @b: second element
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - build and sort a max heap tree
 *
 * @array: unordered array
 * @size: the length of the input array
 * @i: index
*/
void heapify(int *array, size_t size, size_t i)
{
	/* find largest among root, left and right child */
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	/* Swap and continue heapifying if root is not largest */
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order.
 * @array: input: an unordered array
 * @size: the length of the input array
*/
void heap_sort(int *array, size_t size)
{
	/* Build the max heap */
	size_t i;

	for (i = size / 2 - 1; (int)i >= 0; i--)
	{
		heapify(array, size, i);
	}
	/* heap sort */
	for (i = size - 1; (int)i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}

}
