#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 *
 * @head: The head node of a linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if there is
 * no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast = head, *slow = head;

	if (!head)
		return (NULL);
	while (TRUE)
	{
		fast = fast->next;
		if (!fast)
			return (NULL);
		fast = fast->next;
		if (!fast)
			return (NULL);
		slow = slow->next;
		if (fast == slow)
			break;
	}
	while (TRUE)
	{
		fast = slow->next;
		while (TRUE)
		{
			if (fast == head)
				return (fast);
			if (fast == slow)
				break;
			fast = fast->next;
		}
		head = head->next;
	}
}
