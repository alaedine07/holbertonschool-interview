#include "lists.h"
/**
 * insert_logic - insert in rest of linked list
 * @c: current_node
 * @pc: previous node
 * @new: new_node
 * @n: number to be compared with
 * Return: address of the new node
 */
listint_t *insert_logic(listint_t *c, listint_t *pc, int n, listint_t *new)
{
	while (c->next != NULL)
	{
		if (c->n > n)
		{
			new->next = c;
			pc->next = new;
			return (new);
		}
		pc = c;
		c = c->next;
	}
	if (c->n > n)
	{
		new->next = c;
		pc->next = new;
		return (new);
	}
	new->next = NULL;
	c->next = new;
	return (new);
}

/**
 * insert_node - insert node in a sorted linked list
 * @head: head of the linked list
 * @number: number in the node
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;
	listint_t *prev_curr;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	if (current->n > number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	prev_curr = current;
	new = insert_logic(current, prev_curr, number, new);
	return (new);
}
