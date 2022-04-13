#include "search.h"


/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 *
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: skiplist_t* to the first node where value is located on success;
 *     NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *a, *b = list;


	if (!list)
		return (NULL);

	do {
		a = b;
		b = b->express;
		if (!b)
		{
			b = a;
			while (b->next)
				b = b->next;
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n", b->index, b->n);
	} while (b && b->n < value);

	printf(
		"Value found between indexes [%lu] and [%lu]\n", a->index, b->index);

	while (a)
	{
		printf("Value checked at index [%lu] = [%d]\n", a->index, a->n);
		if (a->n == value)
			return (a);
		a = a->next;
	}

	return (NULL);
}
