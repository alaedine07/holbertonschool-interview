#include "lists.h"

/**
 * insert_node - insert node in a sorted linked list
 * @head: head of the linked list
 * @number: number in the node
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	/* create the node */
	listint_t *new;
	listint_t *current;
	listint_t *prev_curr;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	/* insert at the beggining of linked list */
	if (current->n > number)
	{
		new->next = *head;
		return (new);
	}
	prev_curr = current;
	while (current->next != NULL)
	{
		/* comparing with current pointer */
		if (current->n > number)
		{
			new->next = current;
			prev_curr->next = new;
			return (new);
		}
		/* moving the pointers */
		prev_curr = current;
		current = current->next;
	}
	/* reached the last node */
	if (current->n > number)
	{
		new->next = current;
		prev_curr->next = new;
		return (new);
	}
	new->next = NULL;
	current->next = new;
	return (new);
}
