#include "binary_trees.h"

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
	int root_n;

	if (!root || !*root)
		return (0);

	root_n = (*root)->n;



	return (root_n);
}
