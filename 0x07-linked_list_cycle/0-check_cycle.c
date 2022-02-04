#include "lists.h"


/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: a list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	if (!list)
		return (0);

	slow = list;
	fast = list->next;
	while (slow != fast) {
		if (!fast)
			return (0);
		slow = slow->next;
		fast = fast->next;
		if (!fast)
			return (0);
		fast = fast->next;
	}

	return (1);
}
