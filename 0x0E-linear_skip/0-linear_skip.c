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
	skiplist_t *lastindex, *current;
	int found = 0;

	if (list == NULL)
		return (NULL);
	while (list->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				list->express->index, list->express->n);
		if (value > list->express->n)
			list = list->express;
		else
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					list->index, list->express->index);
			found = 1;
			break;
		}
	}
	current = list;
	if (found == 0)
	{
		lastindex = current;
		while (lastindex->next != NULL)
			lastindex = lastindex->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
				current->index, lastindex->index);
	}
	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}
