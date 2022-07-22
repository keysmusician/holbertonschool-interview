#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef char bool_t;

/**
 * struct tree_info - Information about a binary tree
 *
 * @is_AVL: Whether the tree is a valid AVL tree
 * @height: The height of the tree
 * @min: The minimum value in the tree
 * @max: The maximum value in the tree
 */
typedef struct tree_info
{
	bool_t is_AVL;
	int height;
	int min;
	int max;
} tree_info_t;

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
void binary_tree_print(const binary_tree_t *);
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
