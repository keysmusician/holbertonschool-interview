#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Insert a number into a sorted singly linked list.
 * @head: address of the pointer to the head node of the singly linked list
 * @number: value of the new node
 * Return: pointer to the inserted node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *low = NULL, *high = NULL, *new_node = NULL;

	if (!head)
		return (NULL);

	high = *head;
	while (high && high->n < number)
	{
		low = high;
		high = high->next;
	}

	new_node = malloc(sizeof(listint_t *));

	if (!new_node)
		return (NULL);
	new_node->n = number;
	new_node->next = high;

	if (low)
		low->next = new_node;
	else
		*head = new_node;

	return (new_node);
}
