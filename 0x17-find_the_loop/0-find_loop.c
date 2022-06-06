#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the linked list
 * Return: the address of the loop node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *road_runner = head, *coyote = head;

	while (coyote && coyote->next)
	{
		coyote = coyote->next->next;
		road_runner = road_runner->next;
		if (coyote == road_runner)
		{
			road_runner = head;
			while (road_runner != coyote)
			{
				road_runner = road_runner->next;
				coyote = coyote->next;
			}
			return (coyote);
		}
	}
	return (NULL);
}
