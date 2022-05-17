#include "binary_trees.h"

/**
 * tree_into_array - Places the nodes of a binary tree into an array
 *
 * @node: The root node of the tree
 * @array: The array to place nodes in (must have enough room)
 * @index: Index of the root node (should initially be 0)
 *
 * Return: The index of the last node placed in the array
 */
heap_t *tree_into_array(heap_t *node, heap_t **array, size_t index)
{
	static size_t max_index;
	size_t left_index = index * 2 + 1, right_index = index * 2 + 2, temp = 0;

	if (node)
	{
		if (index > max_index)
			max_index = index;
		array[index] = node;
		tree_into_array(node->left, array, left_index);
		tree_into_array(node->right, array, right_index);
	}
	if (index == 0)
	{
		temp = max_index;
		max_index = 0;
	}
	return (array[temp]);
}

/**
 * heapify - Converts a binary tree to a binary heap
 *
 * @node: Root node of the binary tree
 */
void heapify(heap_t *node)
{
	heap_t *swap = node;
	int temp;

	if (node)
	{
		if (node->left && node->left->n > node->n)
			swap = node->left;
		if (node->right && node->right->n > swap->n)
			swap = node->right;
		if (swap == node)
			return;
		temp = swap->n;
		swap->n = node->n;
		node->n = temp;
		heapify(swap);
	}
}

/**
 * heap_extract - Extracts the root node from a binary heap, reconstructing the
 * heap if neccessary
 *
 * @root: The root node of the binary heap
 *
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *node, *new_root, *old_root, **binary_array;
	int root_n, binary_array_size = 1;

	if (!root || !*root)
		return (0);

	old_root = *root;
	root_n = old_root->n;
	for (node = old_root; node; node = node->left)
		binary_array_size *= 2;
	binary_array = (heap_t **)calloc(--binary_array_size, sizeof(heap_t *));
	new_root = tree_into_array(old_root, binary_array, 0);
	free(binary_array);
	if (new_root == old_root)
		new_root = NULL;
	else
	{
		if (new_root->parent->left == new_root)
			new_root->parent->left = NULL;
		else
			new_root->parent->right = NULL;
		new_root->parent = NULL;
		new_root->left = old_root->left;
		new_root->right = old_root->right;
		if (old_root->left)
			old_root->left->parent = new_root;
		if (old_root->right)
			old_root->right->parent = new_root;
		heapify(new_root);
	}
	free(*root);
	*root = new_root;
	return (root_n);
}
