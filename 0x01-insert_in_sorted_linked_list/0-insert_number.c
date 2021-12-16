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
	listint_t *low = NULL;
	listint_t *high = NULL;

	if (!head || !*head)
		return (NULL);

	high = *head;

	while (high && high->n < number)
	{
		low = high;
		high = high->next;
	}

	listint_t *new_node = malloc(sizeof(listint_t *));

	if (new_node)
	{
		new_node->n = number;
		new_node->next = high;
	}
	else
	{
		return (NULL);
	}

	low->next = new_node;

	return (new_node);
}
