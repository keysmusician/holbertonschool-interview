#include "lists.h"

/**
 * is_palindrome - Determines if a singly linked list is a palindrome.
 * @head: the head node of the linked list
 * Return: 1 if the linked list is a palidrome, 0 if not.
 */
int is_palindrome(listint_t **head)
{
	int length = 0, index = 0, *compare = NULL;
	listint_t *node = NULL;

	if (!head || !*head)
		return (0);
	node = *head;

	/* Find the length of the LL */
	while (node)
	{
		length++;
		node = node->next;
	}

	/* Remember the first half of the LL in reverse order */
	compare = (int *)calloc(length / 2, sizeof(int));
	index = length / 2;
	for (node = *head; node && index; node = node->next)
	{
		compare[index - 1] = node->n;
		index--;
	}

	if (length % 2 == 1)
		node = node->next;

	/* Compare the array with the LL */
	for (index = 0; index < length && node; index++)
	{
		if (node->n != compare[index])
		{
			free(compare);
			return (0);
		}
		node = node->next;
	}
	free(compare);
	return (1);
}
