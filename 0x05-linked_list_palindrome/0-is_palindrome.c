#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - check if linked list is palindrome
 *
 * @head: head of linked list
 * Return: 1 if list is palindrome else 0
 */
int is_palindrome(listint_t **head)
{
	int n = 1;
	int k, j, i = 0;
	int palindrome = 1;

	listint_t *current;

	if (*head == NULL)
		return (0);
	/* get the size of the linked list */
	current = *head;
	while (current->next != NULL)
	{
		n++;
		current = current->next;
	}
	/* transform the linked list to array */
	int *arr = malloc(n * sizeof(int));

	current = *head;
	while (current->next != NULL)
	{
		*(arr + i) = current->n;
		i++;
		current = current->next;
	}
	arr[i++] = current->n;
	/* check if the array is palindrome */
	k = i - 1;
	for (j = 0; j < i && j != k ; j++)
	{
		if (arr[j] != arr[k])
		{
			palindrome = 0;
			break;
		}
		k--;
	}
	return (palindrome);
}
