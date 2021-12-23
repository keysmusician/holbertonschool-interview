#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Create a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Value of the new node
 *
 * Return: Pointer to the new binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
