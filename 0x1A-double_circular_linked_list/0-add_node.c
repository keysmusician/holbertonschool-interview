#include "list.h"

/**
 * add_node_end - Adds a node to the end of a circular doubly linked list
 *
 * @list: a list to add a node to the end of
 * @str: string content of the node
 * Return: pointer to the new node
 */
List *add_node_end(List **list, char *str)
{
	List *temp, *new_node = NULL;
	char *str_copy;

	if (!list || !str)
		return (NULL);

	/* Initialize a new node: */
	new_node = (List *)malloc(sizeof(List));
	str_copy = strdup(str);
	if (!new_node || !str_copy)
	/* Memory allocation failed */
		return (NULL);
	new_node->str = str_copy;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!*list)
	/* There is a list, but no head node: */
		*list = new_node;
	else
	/* There is a head node */
	{
		if (!(*list)->prev)
		/* ...but no previous node */
		{
			if (!(*list)->next)
			/* ...and no next node */
				{
					/* The head node is the only node; add the new node */
					(*list)->prev = new_node;
					(*list)->next = new_node;
					new_node->prev = *list;
					new_node->next = *list;

				}
			else
			/* There is a next node; The list is not circular */
			{
				free(new_node->str);
				free(new_node);
				return (NULL);
			}
		}
		else
		/* There is a previous node */
		{
			if (!(*list)->next)
			/* ...but no next node; The list is not circular */
			{
				free(new_node->str);
				free(new_node);
				return (NULL);
			}
			else
			/* There is a next and previous node */
			{
				temp = (*list)->prev;
				(*list)->prev = new_node;
				new_node->next = *list;
				new_node->prev = temp;
				temp->next = new_node;
			}
		}
	}

	return (new_node);
}

/**
 * add_node_begin - Adds a node to the beginning of a circular doubly linked
 * list
 *
 * @list: a list to add a node to the beginning of
 * @str: string content of the node
 * Return: pointer to the new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = add_node_end(list, str);
	if (new_node)
		*list = new_node;

	return (new_node);
}
