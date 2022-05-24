#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Is a pointer to the head of the skip list
 * @value: Is the value to search for
 *
 * Description: A node of the express lane is placed every index which is a
 * multiple of the square root of the size of the list, and we assume that the
 * lilst is sorted in ascending order.
 * Return: A pointer on the first node where value is located.
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *jumper = list;

	if (!list)
		return (NULL);
	while (jumper->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			jumper->express->index, jumper->express->n);
		if (jumper->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				jumper->index, jumper->express->index);
			break;
		}
		jumper = jumper->express;
	}
	if (!jumper->express)
	{
		for (list = jumper; list->next; list = list->next)
			;
		printf("Value found between indexes [%lu] and [%lu]\n",
				jumper->index, list->index);
	}
	for (list = jumper; list != jumper->express; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (value == list->n)
			break;
	}
	return (list == jumper->express ? NULL : list);
}
