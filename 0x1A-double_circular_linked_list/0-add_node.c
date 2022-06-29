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
	/* There is no list or no string, or */
	if (!list || !str || (*list && (/* there is a list and a head node */
				(!(*list)->prev && (*list)->next) || /* but the list is not */
				((*list)->prev && !(*list)->next)))) /* circular */
		return (NULL);
	new_node = (List *)malloc(sizeof(List)); /* Initialize a new node */
	if (!new_node) /* Memory allocation failed */
		return (NULL);
	str_copy = strdup(str);
	if (!str_copy) /* Memory allocation failed */
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = str_copy;
	new_node->next = new_node;
	new_node->prev = new_node;
	if (!*list) /* There is a list, but no head node: */
		*list = new_node;
	else /* There is a head node */
	{
		if (!(*list)->next && !(*list)->prev) /* The head is the only node */
		{   /* Add the new node */
			(*list)->prev = new_node;
			(*list)->next = new_node;
			new_node->prev = *list;
			new_node->next = *list;
		}
		else
		{	/* There is a next and previous node */
			temp = (*list)->prev;
			(*list)->prev = new_node;
			new_node->next = *list;
			new_node->prev = temp;
			temp->next = new_node;
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
