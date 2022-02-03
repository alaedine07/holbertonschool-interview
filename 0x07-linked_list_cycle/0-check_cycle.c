#include "lists.h"

/**
 * check_cycle - check if linked list contains a cycle
 * @list: pointer to head of linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *fast_p = NULL;
	listint_t *slow_p = NULL;

	if (list == NULL)
		return (0);
	fast_p = list;
	slow_p = list;
	while (fast_p && slow_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (fast_p == slow_p)
			return (1);
	}
	return (0);
}
