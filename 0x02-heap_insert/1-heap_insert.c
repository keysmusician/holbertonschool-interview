#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_left_height - Get the height of a binary tree's left-most branch
 *
 * @node: The (root) node of the tree of which to find the height
 *
 * Return: The height of the binary tree, if it is a complete tree
 */
int get_left_height(heap_t *node)
{
	int height = 0;

	while (node)
	{
		height++;
		node = node->left;
	}
	return (height);
}

/**
 * tree_to_array - Arranges nodes of a binary tree in an array
 *
 * @node: A binary tree (root) node
 * @array: The array in which to place pointers to the nodes
 * @index: The index of the current node
 */
void tree_to_array(heap_t *node, heap_t **array, int index)
{
	int index_left = index * 2 + 1;
	int index_right = index * 2 + 2;

	if (!node)
		return;

	array[index] = node;
	tree_to_array(node->left, array, index_left);
	tree_to_array(node->right, array, index_right);
}

/**
 * heap_insert - Insert a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert = NULL, *parent = NULL;
	heap_t **node_array = NULL;
	int height = 0, max_node_count = 0, i = 0;

	if (!root)
		return (NULL);
	if (!*root)
	{
		insert = binary_tree_node(*root, value);
		*root = insert;
		return (insert);
	}
	height = get_left_height(*root);
	max_node_count = (1 << height) - 1;
	node_array = (heap_t **)calloc(max_node_count, sizeof(heap_t *));
	if (!node_array)
		return (NULL);

	tree_to_array(*root, node_array, 0);
	while (i < max_node_count && node_array[i])
		i++;

	parent = node_array[(i - (2 - i % 2)) / 2];
	insert = binary_tree_node(parent, value);
	if (!insert)
		return (NULL);

	if (i % 2)
		parent->left = insert;
	else
		parent->right = insert;

	while (parent && value >= parent->n)
	{
		insert->n = parent->n;
		parent->n = value;
		insert = parent;
		parent = parent->parent;
	}
	free(node_array);
	return (insert);
}
