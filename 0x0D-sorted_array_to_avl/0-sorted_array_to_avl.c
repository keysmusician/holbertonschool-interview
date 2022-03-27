#include "binary_trees.h"


/**
 * AVL - Builds an AVL tree from a sorted array of unique elements
 *
 * @parent: Parent of the new node
 * @array: Array of values to convert
 * @size:  Number of elements in the array
 * @was_visited: Bool array the same length as `array` which indicates whether
 *     or not a node has already been visited.
 *
 * Return: avl_t* to a new AVL tree on success, NULL on failure
 */
avl_t *AVL(avl_t *parent, int *array, size_t size, char *was_visited)
{
	static int *max;
	avl_t *node = NULL;
	size_t midpoint = (size - 1) / 2;

	if (!max)
		max = array + size;

	if (!size || array >= max || was_visited[midpoint])
		return (NULL);

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->n = array[midpoint];
	was_visited[midpoint] = 1;

	node->right = AVL(
		node,
		array + midpoint + 1,
		midpoint + 1,
		was_visited + midpoint + 1
	);
	node->left = AVL(node, array, midpoint, was_visited);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array of unique
 * elements
 *
 * @array: Array of values to convert
 * @size:  Number of elements in the array
 *
 * Return: avl_t* to a new AVL tree on success, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	char *was_visited;

	was_visited = calloc(size, sizeof(char));
	if (!was_visited)
		return (NULL);

	tree = AVL(NULL, array, size, was_visited);

	free(was_visited);

	return (tree);
}
