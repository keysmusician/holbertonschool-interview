#include "lists.h"

/**
 * recursive_check - helper for is_palindrome
 *
 * @A: initially the head node, but is recursively descended and used as a
 * backwards iterator
 * @head: the head node of the linked list, remains constant through recursion
 * @result: an output parameter containing the result; must be 1 when passed in
 */
void recursive_check(listint_t *A, listint_t *head, int *result)
{
	static int length, index;
	static listint_t *B;

	if (!A)
		return;

	B = head;
	length++;
	index++;
	recursive_check(A->next, head, result);
	index--;
	if (index >= length / 2)
	{
		if (B->n == A->n)
			B = B->next;
		else
			*result = 0;
	}
}

/**
 * is_palindrome - Determines if a singly linked list is a palindrome.
 * @head: the head node of the linked list
 * Return: 1 if the linked list is a palidrome, 0 if not.
 */
int is_palindrome(listint_t **head)
{
	int result = 1;

	if (!head)
		return (0);
	recursive_check(*head, *head, &result);
	return (result);
}

